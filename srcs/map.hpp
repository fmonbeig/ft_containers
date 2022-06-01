/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 14:32:52 by fmonbeig          #+#    #+#             */
/*   Updated: 2022/06/01 17:30:51 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include <limits>
#include <string>
#include <memory>
#include <sstream>
#include <stdexcept>
#include <functional>
#include "pair.hpp"
#include "utils.hpp"
#include "reverse_iterator.hpp"

namespace ft
{
template<
	typename Key,
	typename T,
	typename Compare = std::less<Key>,// Function object for performing comparisons. ex : Compare(x, y)
	typename Allocator = std::allocator<ft::pair<const Key, T> > >
class map
{
		// +------------------------------------------+ //
		//   TYPEDEF FOR MAP							//
		// +------------------------------------------+ //
	public:
		typedef Key										key_type;
		typedef T										mapped_type;
		typedef typename ft::pair<const Key, T>			value_type;

		typedef std::size_t 							size_type;
		typedef std::ptrdiff_t							difference_type;

		typedef Compare									key_compare;
		typedef Allocator								Allocator_type;
		typedef value_type&								reference;
		typedef const value_type&						const_reference;

		typedef typename Allocator::pointer				pointer;
		typedef typename Allocator::const_pointer		const_pointer;
		//typedef 										iterator;
		//typedef 										const_iterator;
		//typedef ft::reverse_iterator<iterator>			reverse_iterator;
		//typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;

		// +------------------------------------------+ //
		//   STRUCT AND CLASS FOR MAP 					//
		// +------------------------------------------+ //

		/*	std::map::value_compare is a function object that compares objects of type
			std::map::value_type (key-value pairs) by comparing of the first components of the pairs.
			binary_function is a base class for creating function objects with two arguments.*/

	public:
		class value_compare : public std::binary_function<value_type, value_type, bool>
		{
			//friend class map<Key, T, Compare, Allocator>;
			protected:
				Compare comp;
				value_compare(Compare c): comp(c) {}
			public:
				bool operator()( const value_type& lhs, const value_type& rhs ) const
				{ return comp(lhs.first, rhs.first); }
		};

		struct node
		{
			node(){}
			value_type	*_key;
			node		*_left;
			node		*_right;
			int			_height;
		};

		// +------------------------------------------+ //
		//   PRIVATE MEMBER								//
		// +------------------------------------------+ //

	protected:
		Compare					_comp;
		size_t					_size;
		std::allocator<node>	_allocNode;
		Allocator				_allocPair;
		node					*_root;

		// +------------------------------------------+ //
		//   CONSTRUCTOR && DESTRUCTOR					//
		// +------------------------------------------+ //
	public:
		explicit map( const Compare& comp = Compare(), const Allocator& alloc = Allocator() ):
			_comp(comp), _size(0), _allocNode(std::allocator<node>()),_allocPair(alloc), _root(NULL) {} // construction de l'arbre

		// template< class InputIt >
		// map( InputIt first, InputIt last, const Compare& comp = Compare(), const Allocator& alloc = Allocator() ):
		// _ptr(comp, alloc)
		// {

		// }
		// map( const map& other )
		// {

		// }

		// supprimer son arbre binaire de maniere recursif

		// +------------------------------------------+ //
		//   MODIFIERS									//
		// +------------------------------------------+ //

		// std::pair<iterator, bool> insert( const value_type& value );
		void	insert( const value_type& value )
		{
			_root = insert_node(_root, value);
			_size++;
		}

		void	print_tree()
		{ printTree(_root, " ", true); }

		void	rootKey()
		{
			std::cout << _root->_key->first << " " <<  _root->_key->second<< std::endl;
		}

		value_compare value_comp() const { return (value_compare(Compare())); };

/******************************************************************************************************/
/************** AVL TREE		AVL TREE		AVL TREE		AVL TREE		AVL TREE **************/
/******************************************************************************************************/
/* 1- Insert Element one by one in the three
** 2- For each insert we will check the Balance of the tree
** 3- If unbalance we use RotateRight - RotateLeft - RightLeftRotate - LeftRightRotate
*/

	private:
		// si a > b alors on renvoie a sinon c 'est b
		int	max(int a, int b)
		{ return (a > b) ? a : b; }

		int height(node *N)
		{
			if (N == NULL)
				return 0;
			return N->_height;
		}

		node	*new_node(const value_type& value)
		{
			node *N = _allocNode.allocate(1);
			_allocNode.construct(N, node());
			N->_left = NULL;
			N->_right = NULL;
			N->_height = 1;
			N->_key = _allocPair.allocate(1);
			_allocPair.construct(N->_key, value);
			return (N);
		}

		void	free_node(node *N)
		{
			_allocPair.deallocate(N->_key, 1);
			_allocPair.destroy(N->_key);
			_allocNode.deallocate(N, 1);
			_allocNode.destroy(N);
		}

		node *rightRotate(node *y)
		{
			node *x = y->_left;
			node *B = x->_right;
			x->_right = y;
			y->_left = B;
			y->_height = max(height(y->_left), height(y->_right)) + 1;
			x->_height = max(height(x->_left), height(x->_right)) + 1;
			return x;
		}

		node *leftRotate(node *x)
		{
			node *y = x->_right;
			node *B = y->_left;
			y->_left = x;
			x->_right = B;
			x->_height = max(height(x->_left), height(x->_right)) + 1;
			y->_height = max(height(y->_left), height(y->_right)) + 1;
			return y;
		}

		int getBalanceFactor(node *N)
		{
			if (N == NULL)
				return 0;
			return height(N->_left) - height(N->_right);
		}

		// Insert a node in a recursive way
		node *insert_node(node *root, const value_type value)
		{
			// Find the correct postion and insert the N
			if (root == NULL)
			{
				return (new_node(value));
			}
			if (_comp(value.first, root->_key->first)) // if value lower than root key
				root->_left = insert_node(root->_left, value);
			else if (!(_comp(value.first, root->_key->first)))
				root->_right = insert_node(root->_right, value);
			else
				return root;

			// Update the balance factor of each node you pass through and balance the tree
			root->_height = 1 + max(height(root->_left), height(root->_right));
			int balanceFactor = getBalanceFactor(root);
			if (balanceFactor > 1)
			{
				if (_comp(value.first, root->_left->_key->first))
				{
					return rightRotate(root);
				}
				else if (!(_comp(value.first, root->_left->_key->first)))
				{
					root->_left = leftRotate(root->_left);
					return rightRotate(root);
				}
			}
			if (balanceFactor < -1)
			{
				if (!(_comp(value.first, root->_right->_key->first)))
				{
					return leftRotate(root);
				}
				else if (_comp(value.first, root->_right->_key->first))
				{
					root->_right = rightRotate(root->_right);
					return leftRotate(root);
				}
			}
			return root;
		}

		// Node with minimum value in it
		node *node_value_min(node *N)
		{
			node *temp = N;
			while (temp->_left != NULL)
				temp = temp->_left;
			return temp;
		}

		// Delete a node

		node *deleteNode(node *root, const value_type value)
		{
			// Find the node and delete it
			if (root == NULL)
				return root;
			if (_comp(value.first, root->_key->first))
				root->_left = deleteNode(root->_left, value);
			else if (!(_comp(value.first, root->_key->first)))
				root->_right = deleteNode(root->_right, value);
			else
			{
				if ((root->_left == NULL) || (root->_right == NULL))
				{
					node *temp = root->_left ? root->_left : root->_right;
					if (temp == NULL)
					{
						temp = root;
						root = NULL;
					}
					else
					{
						*root = *temp;
						free_node(temp);
					}
				}
				else
				{
					node *temp = node_value_min(root->_right);
					root->_key = temp->_key;
					root->_right = deleteNode(root->_right, temp->_key);
				}
			}

			if (root == NULL)
				return root;

			// Update the balance factor of each node and
			// balance the tree
			root->_height = 1 + max(height(root->_left), height(root->_right));
			int balanceFactor = getBalanceFactor(root);
			if (balanceFactor > 1)
			{
				if (getBalanceFactor(root->_left) >= 0)
				{
					return rightRotate(root);
				}
				else
				{
					root->_left = leftRotate(root->_left);
					return rightRotate(root);
				}
			}
			if (balanceFactor < -1)
			{
				if (getBalanceFactor(root->_right) <= 0)
				{
					return leftRotate(root);
				}
				else
				{
					root->_right = rightRotate(root->_right);
					return leftRotate(root);
				}
			}
			return root;
		}

		// Print the tree
		void printTree(node *root, std::string indent, bool last) {
		if (root != NULL) {
			std::cout << indent;
			if (last) {
			std::cout << "R----";
			indent += "   ";
			} else {
			std::cout << "L----";
			indent += "|  ";
			}
			std::cout << root->_key->first << std::endl;
			printTree(root->_left, indent, false);
			printTree(root->_right, indent, true);
		}
		}
};

}
#endif



// AVL tree implementation in C++

// #include <iostream>
// using namespace std;

// class Node {
//    public:
//   int key;
//   Node *left;
//   Node *right;
//   int height;
// };









// // Print the tree
// void printTree(Node *root, string indent, bool last) {
//   if (root != nullptr) {
//     cout << indent;
//     if (last) {
//       cout << "R----";
//       indent += "   ";
//     } else {
//       cout << "L----";
//       indent += "|  ";
//     }
//     cout << root->key << endl;
//     printTree(root->left, indent, false);
//     printTree(root->right, indent, true);
//   }
// }

// int main() {
//   Node *root = NULL;
//   root = insert_node(root, 33);
//   root = insertNode(root, 13);
//   root = insertNode(root, 53);
//   root = insertNode(root, 9);
//   root = insertNode(root, 21);
//   root = insertNode(root, 61);
//   root = insertNode(root, 8);
//   root = insertNode(root, 11);
//   printTree(root, "", true);
//   root = deleteNode(root, 13);
//   cout << "After deleting " << endl;
//   printTree(root, "", true);
// }

// Map utilise des arbres pour equilibré l'acces a ses données
// A verifier
// Map ne peut avoir que des cles unique
// Les elements vont etre choisi par une fonction (autre classe ?) Compare
// Dans un arbre binaire on range les elements comme suit : si nouveau mot et au dessus du dernier alors on le met a droite sinon c'est a gauche
// Pas opti car si toujours d'un cote alors l'arbre est desequilibré

/*  https://fr.wikipedia.org/wiki/Arbre_bicolore
les règles suivantes sont utilisées :

1 - Un nœud est soit rouge soit noir ;
2 - La racine est noire ;
3 - Les enfants d'un nœud rouge sont noirs;
4 - Tous les nœuds ont 2 enfants. Ce sont d'autres nœuds ou des feuilles NIL, qui ne possèdent pas de valeur et qui sont les seuls nœuds sans enfants. Leur couleur est toujours noire et rentre donc en compte lors du calcul de la hauteur noire.
5 - Le chemin de la racine à n'importe quelle feuille (NIL) contient le même nombre de nœuds noirs. On peut appeler ce nombre de nœuds noirs la hauteur noire.

	https://fr.wikipedia.org/wiki/Arbre_binaire_de_recherche
	https://fr.wikipedia.org/wiki/Arbre_AVL
*/


// S'il y a des duplications alors on ne les prends pas en compte
