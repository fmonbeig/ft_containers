/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 14:32:52 by fmonbeig          #+#    #+#             */
/*   Updated: 2022/06/06 18:10:48 by fmonbeig         ###   ########.fr       */
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
#include "map_iterator.hpp"

namespace ft
{

template<typename T>
struct node
{
	node(){}

	node &operator=(node const &rhs)
	{
		if (this != &rhs)
		{
			this->_key = rhs._key;
			this->_left = rhs._left;
			this->_right = rhs._right;
			this->_dad = rhs._dad;
			this->_end = rhs._end;
		}
		return (*(this));
	}
	T			*_key;
	node		*_left;
	node		*_right;
	node		*_dad;
	node		*_end;
	int			_height;

};

template<
	typename Key,
	typename T,
	typename Compare = std::less<Key>,// Function object for performing comparisons. ex : Compare(x, y)
	typename Allocator = std::allocator<ft::pair<const Key, T> > >
class map
{
		// +------------------------------------------+ //
		//   TYPEDEF 									//
		// +------------------------------------------+ //
	public:
		typedef Key													key_type;
		typedef T													mapped_type;
		typedef typename ft::pair<const Key, T>						value_type;

		typedef std::size_t 										size_type;
		typedef std::ptrdiff_t										difference_type;

		typedef Compare												key_compare;
		typedef Allocator											Allocator_type;
		typedef value_type&											reference;
		typedef const value_type&									const_reference;

		typedef typename Allocator::pointer							pointer;
		typedef typename Allocator::const_pointer					const_pointer;
		typedef map_iterator<Compare, node<value_type>, value_type>			iterator;
		typedef map_iterator<Compare, node<value_type>, const value_type>	const_iterator;
		typedef ft::reverse_iterator<iterator>							reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>					const_reverse_iterator;
	protected:
		typedef node<value_type>								node;

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


		// +------------------------------------------+ //
		//   PRIVATE MEMBER								//
		// +------------------------------------------+ //

	protected:
		Compare					_comp;
		std::allocator<node>	_allocNode;
		Allocator				_allocPair;
		node					*_root;


		// +------------------------------------------+ //
		//   CONSTRUCTOR && DESTRUCTOR					//
		// +------------------------------------------+ //
	public:
		explicit map( const Compare& comp = Compare(), const Allocator& alloc = Allocator() ):
			_comp(comp), _allocNode(std::allocator<node>()),_allocPair(alloc),
			_root(NULL) {}

		// template< class InputIt >
		// map( InputIt first, InputIt last, const Compare& comp = Compare(), const Allocator& alloc = Allocator() ):
		// _ptr(comp, alloc)
		// {

		// }
		// map( const map& other )
		// {

		// }

		// supprimer son arbre binaire de maniere recursif a partir de root (et bien penser supprimer end dans le root)


		// +------------------------------------------+ //
		//   MODIFIERS									//
		// +------------------------------------------+ //

		iterator	begin()
		{ return iterator(node_value_min(_root)); }

		const_iterator	begin() const
		{ return const_iterator(node_value_min(_root));}

		iterator	end()
		{ return iterator(node_value_max(_root)->_end); }

		const_iterator	end() const
		{ return const_iterator(node_value_max(_root)->_end); }

		reverse_iterator	rbegin()
		{ return reverse_iterator(end()); }

		const_reverse_iterator	rbegin() const
		{ return const_reverse_iterator(end()); }

		reverse_iterator	rend()
		{ return reverse_iterator(begin()); }

		const_reverse_iterator	rend() const
		{ return const_reverse_iterator(begin()); }

		// +------------------------------------------+ //
		//   MODIFIERS									//
		// +------------------------------------------+ //

		/* At each insert we have to recalculate the new end()
		*
		*/
		void	insert( const value_type& value )
		{
			value_type add(0,0);
			node *ancient_max = NULL;
			node *new_max = NULL;

			if (_root)
				ancient_max = node_value_max(_root);
			_root = insert_node(_root, value, NULL);
			if (ancient_max == NULL)
			{
				_root->_end = new_node(add, _root);
				return ;
			}
			new_max = node_value_max(_root);
			if (_comp(ancient_max->_key->first, new_max->_key->first)) // if new value is the biggest value in map then we free _end
			{
				free_node(ancient_max->_end);
				ancient_max->_end = NULL;
				new_max->_end = new_node(add, new_max);
				new_max->_end->_left = new_max->_end->_dad;
			}
		}
		
		void	erase( iterator pos )
		{
			value_type add(0,0);
			node *ancient_max = node_value_max(_root);
			node *new_max = NULL;

			free_node(ancient_max->_end);
			// std::cout <<"KEY ROOT " << _root->_key->first << "-----" << std::endl;

			_root = deleteNode(_root, *pos.getnode()->_key);

			new_max = node_value_max(_root);
			new_max->_end = new_node(add, new_max);
			new_max->_end->_left = new_max->_end->_dad;


			// std::cout <<"LAST KEY ROOT " << _root->_key->first << "-----" << std::endl;
			// std::cout <<"LAST RIGHT ROOT " << _root->_right->_key->first << "-----" << std::endl;
			// node *ancient_max = NULL;
			// node *new_max = NULL;

			// if (_root)
			// 	ancient_max = node_value_max(_root);
			// _root = insert_node(_root, value, NULL);
			// if (ancient_max == NULL)
			// {
			// 	_root->_end = new_node(value, _root);
			// 	return ;
			// }
			// new_max = node_value_max(_root);
			// if (_comp(ancient_max->_key->first, new_max->_key->first)) // if new value is the biggest value in map then we free _end
			// {
			// 	free_node(ancient_max->_end);
			// 	new_max->_end = new_node(value, new_max);
			// 	new_max->_end->_left = new_max->_end->_dad;
			// }

		}

		void	print_tree()
		{ printTree(_root, "********* ", true); }

		value_compare value_comp() const { return (value_compare(Compare())); };

/******************************************************************************************************/
/************** AVL TREE		AVL TREE		AVL TREE		AVL TREE		AVL TREE **************/
/******************************************************************************************************/
/* 1- Insert Element one by one in the three
** 2- For each insert we will check the Balance of the tree
** 3- If unbalance we use RotateRight - RotateLeft - RightLeftRotate - LeftRightRotate
*/

	private:
		int	max(int a, int b)
		{ return (a > b) ? a : b; }

		int height(node *N)
		{
			if (N == NULL)
				return 0;
			return N->_height;
		}

		node	*new_node(const value_type& value, node *parent)
		{
			node *N = _allocNode.allocate(1);
			_allocNode.construct(N, node());
			N->_left = NULL;
			N->_right = NULL;
			N->_dad = parent;
			N->_end = NULL;
			N->_height = 1;
			N->_key = _allocPair.allocate(1);
			_allocPair.construct(N->_key, value);
			return (N);
		}

		void	free_node(node *N)
		{
			// std::cout << "REAL DESTROY = " << N->_key->first << std::endl;
			_allocPair.deallocate(N->_key, 1);
			_allocPair.destroy(N->_key);
			if (N->_end)
			{
				// std::cout << "DESTROY END = " << N->_end->_key->first << std::endl;
				_allocPair.deallocate(N->_end->_key, 1);
				_allocPair.destroy(N->_end->_key);
				_allocNode.deallocate(N->_end, 1);
				_allocNode.destroy(N->_end);
			}
			_allocNode.deallocate(N, 1);
			_allocNode.destroy(N);
			N = NULL;
		}

		node *rightRotate(node *y)
		{
			// std::cout << "RIGHT ROTATE" << std::endl;
			// if (y)
			// {
			// 	if(y->_dad)
			// 		std::cout << "NODE Y = " << y->_key->first << " OLD Dad " << y->_dad->_key->first << std::endl;
			// 	else
			// 		std::cout << "NODE Y = " << y->_key->first << " OLD Dad == NULL" << std::endl;
			// }

			node *x = y->_left;
			node *B = x->_right;

			// if (x)
			// {
			// 	if(x->_dad)
			// 		std::cout << "NODE X = " << x->_key->first << " OLD Dad " << x->_dad->_key->first << std::endl;
			// 	else
			// 		std::cout << "NODE X = " << x->_key->first << " OLD Dad == NULL" << std::endl;
			// }
			// if (B)
			// {
			// 	if(B->_dad)
			// 	std::cout << "NODE B = " << B->_key->first<< std::endl; //<< " OLD Dad " << B->_dad->_key->first << std::endl;
			// 	else
			// 		std::cout << "NODE B = " << B->_key->first << " OLD Dad == NULL" << std::endl;
			// }

			x->_dad = y->_dad;
			y->_dad = x;
			x->_right = y;
			y->_left = B;
			if (B)
				B->_dad = y;
			y->_height = max(height(y->_left), height(y->_right)) + 1;
			x->_height = max(height(x->_left), height(x->_right)) + 1;

			// if (y)
			// {
			// 	if(y->_dad)
			// 		std::cout << "NODE Y = " << y->_key->first << " NEW Dad " << y->_dad->_key->first << std::endl;
			// 	else
			// 		std::cout << "NODE Y = " << y->_key->first << " NEW Dad == NULL" << std::endl;
			// }
			// if (x)
			// {
			// 	if(x->_dad)
			// 		std::cout << "NODE X = " << x->_key->first << " NEW Dad " << x->_dad->_key->first << std::endl;
			// 	else
			// 		std::cout << "NODE X = " << x->_key->first << " NEW Dad == NULL" << std::endl;
			// }
			// if (B)
			// {
			// 	if(B->_dad)
			// 		std::cout << "NODE B = " << B->_key->first << " NEW Dad " << B->_dad->_key->first << std::endl;
			// 	else
			// 		std::cout << "NODE B = " << B->_key->first << " NEW Dad == NULL" << std::endl;
			// }
			// std::cout << "=======" << std::endl;
			return x;
		}

		node *leftRotate(node *x)
		{
			// std::cout << "LEFT ROTATE" << std::endl;
			// if (x)
			// {
			// 	if(x->_dad)
			// 		std::cout << "NODE X = " << x->_key->first << " OLD Dad " << x->_dad->_key->first << std::endl;
			// 	else
			// 		std::cout << "NODE X = " << x->_key->first << " OLD Dad == NULL" << std::endl;
			// }

			node *y = x->_right;
			node *B = y->_left;

			// if (y)
			// {
			// 	if(y->_dad)
			// 		std::cout << "NODE Y = " << y->_key->first << " OLD Dad " << y->_dad->_key->first << std::endl;
			// 	else
			// 		std::cout << "NODE Y = " << y->_key->first << " OLD Dad == NULL" << std::endl;
			// }
			// if (B)
			// {
			// 	if(B->_dad)
			// 	std::cout << "NODE B = " << B->_key->first<< std::endl; //<< " OLD Dad " << B->_dad->_key->first << std::endl;
			// 	else
			// 		std::cout << "NODE B = " << B->_key->first << " OLD Dad == NULL" << std::endl;
			// }
			y->_dad = x->_dad;
			x->_dad = y;
			y->_left = x;
			x->_right = B;
			if (B)
				B->_dad = x;
			x->_height = max(height(x->_left), height(x->_right)) + 1;
			y->_height = max(height(y->_left), height(y->_right)) + 1;

			// if(y->_dad)
			// 	std::cout << "NODE Y = " << y->_key->first << " NEW Dad " << y->_dad->_key->first << std::endl;
			// else
			// 	std::cout << "NODE Y = " << y->_key->first << " NEW Dad == NULL" << std::endl;
			// if(x->_dad)
			// 	std::cout << "NODE X = " << x->_key->first << " NEW Dad " << x->_dad->_key->first << std::endl;
			// else
			// 	std::cout << "NODE X = " << x->_key->first << " NEW Dad == NULL" << std::endl;
			// if(B->_dad)
			// 	std::cout << "NODE B = " << B->_key->first << " NEW Dad " << B->_dad->_key->first << std::endl;
			// else
			// 	std::cout << "NODE B = " << B->_key->first << " NEW Dad == NULL" << std::endl;
			// std::cout << "=======" << std::endl;
			return y;
		}

		int getBalanceFactor(node *N)
		{
			if (N == NULL)
				return 0;
			return height(N->_left) - height(N->_right);
		}

		// Insert a node in a recursive way
		node *insert_node(node *root, const value_type value, node *parent)
		{
			// Find the correct postion and insert the N
			if (root == NULL)
			{
				return (new_node(value, parent));
			}
			if (_comp(value.first, root->_key->first)) // if value lower than root key
				root->_left = insert_node(root->_left, value, root);
			else if (!(_comp(value.first, root->_key->first))) // if value higher or equal than root key
			{
				if (value.first == root->_key->first)
					return root;
				root->_right = insert_node(root->_right, value, root);
			}
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

		node *node_value_max(node *N)
		{
			node *temp = N;
			while (temp->_right != NULL)
				temp = temp->_right;
			return temp;
		}

		node *deleteNode(node *root, const value_type value)
		{
			// Find the node and delete it
			// std::cout <<"RIGHT ROOT " << _root->_right->_key->first << "-----" << std::endl;
			if (root == NULL)
				return root;
			if (_comp(value.first, root->_key->first))
				root->_left = deleteNode(root->_left, value);
			else if (!(_comp(value.first, root->_key->first)) && value.first != root->_key->first )
			{
				// std::cout << "RIGHT " << value.first << " " << root->_key->first <<std::endl<< std::endl;
				root->_right = deleteNode(root->_right, value);
			}
			else
			{
				// std::cout << "EQUAL " << value.first << " " << root->_key->first <<std::endl<< std::endl;
				if ((root->_left == NULL) || (root->_right == NULL))
				{
					// std::cout << " ONE ROOT IS NULL " << std::endl<< std::endl;
					node *temp = root->_left ? root->_left : root->_right;
					if (temp == NULL)
					{
						// std::cout << "Leaf Node = NULL" << std::endl<< std::endl<< std::endl;
						temp = root;
						// root->_dad->_end = root->_end; // NB we have to check leaks
						root = NULL;
						// free_node(root);
						// root = NULL;
					}
					else
					{
						// std::cout << "SWAPPING TIME" << std::endl<< std::endl;
						node swap;

						swap._key = root->_key;

						// std::cout <<"ROOT->_KEY ==== " << root->_key->first << "-----" << std::endl;
						// std::cout <<"BEFORE ROOT " << _root->_right->_key->first << "-----" << std::endl;
						// std::cout <<"BEFORE ROOT DAD " << _root->_right->_dad->_key->first << "-----" << std::endl;
						std::cout << root->_key->first << " " << temp->_key->first << std::endl;
						root->_key = temp->_key;
						root->_left = temp->_left;
						root->_right = temp->_right;
						// root->_end = temp->_end;

						temp->_key = swap._key;

						// std::cout <<"AFTER ROOT DAD " << _root->_right->_dad->_key->first << "-----" << std::endl;

						// std::cout <<"AFTER ROOT " << _root->_right->_key->first << "-----" << std::endl;
					}
						free_node(temp);
				}
				else
				{
					node swap;

					swap._key = root->_key;
					// std::cout << "NO ROOT IS NULL " << std::endl << std::endl;

					node *temp = node_value_min(root->_right);
					if (temp->_key->first == root->_right->_key->first)
						root->_right = root->_right->_right;
					root->_key = temp->_key;
					// root->_end = temp->_end;
					temp->_key = swap._key;
					if (temp->_right)
						temp->_right->_dad = root;

					free_node(temp);
				}
			}

			if (root == NULL)
				return root;

			// Update the balance factor of each node and balance the tree
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
		void printTree(node *root, std::string indent, bool last)
		{
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
				//  printInfoNode(root);
				printTree(root->_left, indent, false);
				printTree(root->_right, indent, true);
			}
		}

		void printInfoNode(node *N)
		{
			std::cout << "NODE " << N->_key->first;
			//  std::cout << "NODE " << N->_key->first << " HEIGHT LEFT = " << height(N->_left) << " HEIGHT RIGHT = " << height(N->_right) << " HEIGHT = " << height(N->_left) - height(N->_right);
			if (N->_left)
				std::cout<< " Value N->_left "<< N->_left->_key->first;
			if (N->_right)
				std::cout<< " Value N->_right "<< N->_right->_key->first;
			if (N->_dad)
				std::cout << " DAD = " << N->_dad->_key->first;
			else
				std::cout << " DAD = NULL ";
			std::cout<< std::endl;
		}
};

}
#endif

// A faire

// rajouter la suppression de l'arbre a la sortie de map, le faire en mode recursif voir printTree
// tester le delete
// comprendre le system d'iterateur
// reussir a rajouter le dad dans la creation des nodes




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
