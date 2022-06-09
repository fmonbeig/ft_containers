/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 14:32:52 by fmonbeig          #+#    #+#             */
/*   Updated: 2022/06/09 15:53:56 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include <limits>
#include <string>
#include <iterator>
#include <memory>
#include <sstream>
#include <stdexcept>
#include <functional>
#include <string>
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
			protected:
				Compare comp;
			public:
				value_compare(Compare c): comp(c) {}
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
		size_type				_size;
		node					*_end;

		// +------------------------------------------+ //
		//   CONSTRUCTOR && DESTRUCTOR					//
		// +------------------------------------------+ //
	public:
		explicit map( const Compare& comp = Compare(), const Allocator& alloc = Allocator() ):
			_comp(comp), _allocNode(std::allocator<node>()),_allocPair(alloc),
			_root(NULL),_size(0), _end(NULL)
		{ initialize_end(); }

		template< class InputIt >
		map( InputIt first, InputIt last, const Compare& comp = Compare(), const Allocator& alloc = Allocator() ):
			_comp(comp), _allocNode(std::allocator<node>()), _allocPair(alloc), _root(NULL), _size(0), _end(NULL)
		{
			initialize_end();
			insert(first, last);
		}

		~map()
		{
			clear();
			// Destroy _end
			_allocPair.deallocate(_end->_key, 1);
			// _allocPair.destroy(_end->_key);
			_allocNode.deallocate(_end, 1);
			_allocNode.destroy(_end);
		}

		map( const map& other ) //NB Ne fonctionne pas (peut etre lié a end())
		{
			_comp = other._comp;
			_allocNode = other._allocNode;
			_allocPair = other._allocPair;
			_root = NULL;
			_size = 0;
			initialize_end();
			insert(other.begin(), other.end());
		}

		map& operator=( const map& other )
		{
			_comp = other._comp;
			_allocNode = other._allocNode;
			_allocPair = other._allocPair;
			clear();
			insert(other.begin(), other.end());
			return *this;
		}

		Allocator_type get_allocator() const
		{ return this->_allocPair;}


		// +------------------------------------------+ //
		//   ELEMENT ACCESS								//
		// +------------------------------------------+ //

		T& at( const Key& key )
		{
			iterator it = find(key);
			if (it != end() && it->first == key)
				return it->second;
			else
				throw std::out_of_range("map");
		}

		const T& at( const Key& key ) const
		{
			iterator it = find(key);
			if (it != end() && it->first == key)
				return it->second;
			else
				throw std::out_of_range("map");
		}

		T& operator[]( const Key& key )
		{
			iterator it = find(key);
			if (it != end() && it->first == key)
				return it->second;
			else
			{
				value_type	add(key,T());
				insert(add);
			}
			it = find(key);
			return it->second;
		}

		// +------------------------------------------+ //
		//   ITERATORS									//
		// +------------------------------------------+ //

		iterator	begin()
		{
			if (_size == 0)
				return iterator(_end);
			return iterator(node_value_min(_root));
		}

		const_iterator	begin() const
		{
			if (_size == 0)
				return const_iterator(_end);
			return const_iterator(node_value_min(_root));
		}

		iterator	end() // end () doit etre le meme a chaque fois // on pourrait le créer en dur dans map et en mettre une copie dans chaque node, et on met a jour le end a chaque changement
		{ return iterator(_end);}

		const_iterator	end() const
		{ return const_iterator(_end); }

		reverse_iterator	rbegin()
		{ return reverse_iterator(end()); }

		const_reverse_iterator	rbegin() const
		{ return const_reverse_iterator(end()); }

		reverse_iterator	rend()
		{ return reverse_iterator(begin()); }

		const_reverse_iterator	rend() const
		{ return const_reverse_iterator(begin()); }

		// +------------------------------------------+ //
		//   CAPACITY									//
		// +------------------------------------------+ //

		bool empty() const
		{
			if (_size == 0)
				return 1;
			return 0;
		}

		size_type size() const
		{ return _size; }

		size_type max_size() const
		{ return (_allocNode.max_size()); }

		// +------------------------------------------+ //
		//   MODIFIERS									//
		// +------------------------------------------+ //

		void clear()
		{
			if (_size > 0)
				destroy_tree(_root);
			// 	erase(begin(), end());
		}

		/* At each insert we have to recalculate the new end() */
		void	insert( const value_type& value )
		{
			_root = insert_node(_root, value, NULL);
			if (_end->_dad == NULL)
			{
				_end->_dad = _root;
				_end->_left = _root;
			}
			else
			{
				node *new_max = node_value_max(_root);
				if (_comp(_end->_dad->_key->first, new_max->_key->first))
				{
					_end->_dad = new_max;
					_end->_left = new_max;
				}
				new_max->_left = NULL;
				new_max->_right = NULL;
			}
			// std::cout << "==================================" << std::endl;
			// print_tree();
		}

		template< class InputIt >
		void insert( InputIt first, InputIt last )
		{
			for(; first != last; first++)
				insert(*first.operator->());
		}

		iterator insert( iterator hint, const value_type& value )
		{
			(void)hint;
			insert(value);
			return find(value.first);
		}

		void	erase( iterator pos )
		{
			_root = deleteNode(_root, *pos.getnode()->_key);

			if (_root)
			{
				node *new_max = node_value_max(_root);
				_end->_dad = new_max;
				_end->_left = new_max;
			}
			else
			{
				_end->_dad = NULL;
				_end->_left = NULL;
			}
		}

		void erase( iterator first, iterator last )
		{
			map temp(first, last);
			iterator it = temp.begin();
			iterator ite = temp.end();
			ite--;

			for(; it != ite;)
			{
				erase(it);
				it++;
			}
			erase(it);
			if (_size == 0)
			{
				_end->_dad = NULL;
				_end->_left = NULL;
			}
			// node *new_max = node_value_max(_root);
			// new_max->_left = NULL;
			// new_max->_right = NULL;
		}

		size_type erase( const Key& key )
		{
			iterator it = find(key);
			if (it == end())
				return 0;
			else
			{
				erase(it);
				return 1;
			}
		}

		void swap( map& other )
		{
			Compare					tmp_comp = _comp;
			std::allocator<node>	tmp_allocNode = _allocNode;
			Allocator				tmp_allocPair = _allocPair;
			node					*tmp_root = _root;
			size_type				tmp_size = _size;
			_comp = other._comp;
			_allocNode = other._allocNode;
			_allocPair = other._allocPair;
			_root = other._root;
			_size = other._size;
			other._comp = tmp_comp;
			other._allocNode = tmp_allocNode;
			other._allocPair = tmp_allocPair;
			other._root = tmp_root;
			other._size = tmp_size;
		}

		// +------------------------------------------+ //
		//   LOOKUP										//
		// +------------------------------------------+ //

		size_type count( const Key& key ) const
		{
			const_iterator it = find(key);
			if (it == end())
				return 0;
			else
				return 1;
		}

		iterator find( const Key& key )  //NB problem when we try to find something with 0 data
		{ return (find_in_tree(_root, key)); }

		const_iterator find( const Key& key ) const
		{ return (find_in_tree(_root, key)); }

		iterator upper_bound( const Key& key )
		{
			iterator it = find(key);
			if (it == end())
				return end();
			else
			{
				it++;
				return it;
			}
		}

		const_iterator upper_bound( const Key& key ) const
		{
			const_iterator it = find(key);
			if (it == end())
				return end();
			else
			{
				it++;
				return it;
			}
		}

		iterator lower_bound( const Key& key )
		{
			iterator it = find(key);
			if (it == begin())
				return end();
			else
			{
				// it--;
				return it;
			}
		}

		const_iterator lower_bound( const Key& key ) const
		{
			const_iterator it = find(key);
			if (it == begin())
				return end();
			else
			{
				// it--;
				return it;
			}
		}

		ft::pair<iterator,iterator> equal_range( const Key& key )
		{ return ft::pair<iterator,iterator>(lower_bound(key), upper_bound(key)); }

		ft::pair<const_iterator,const_iterator> equal_range( const Key& key ) const
		{ return ft::pair<iterator,iterator>(lower_bound(key), upper_bound(key)); }

		// +------------------------------------------+ //
		//   OBSERVERS									//
		// +------------------------------------------+ //

		key_compare key_comp() const {return (_comp);}

		value_compare value_comp() const { return (value_compare(Compare())); };

		void	print_tree() // NB we need to comment this at the end
			{ printTree(_root, "********* ", true); }

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

		void destroy_tree(node *N)  //FIXME Some leaks problem
		{
			if (N != NULL)
			{
				destroy_tree(N->_left);
				destroy_tree(N->_right);
				_size--;
				if (_size == 0)
				{
					_end->_dad = NULL;
					_end->_left = NULL;
				}
				free_node(N);
			}
			_root = NULL;
		}

		iterator find_in_tree(node *N, const Key& key)  //FIXME Some leaks problem
		{
			if (N == NULL)
				return end();
			if (N->_key->first == key)
				return iterator(N);
			else if (_comp(key, N->_key->first))
				return find_in_tree(N->_left, key);
			else
				return find_in_tree(N->_right, key);
		}

		const_iterator find_in_tree(node *N, const Key& key) const //FIXME Some leaks problem
		{
			if (N == NULL)
				return end();
			if (N->_key->first == key)
				return iterator(N);
			else if (_comp(key, N->_key->first))
				return find_in_tree(N->_left, key);
			else
				return find_in_tree(N->_right, key);
		}

		node	*new_node(const value_type& value, node *parent)
		{
			node *N = _allocNode.allocate(1);
			_allocNode.construct(N, node());
			N->_left = NULL;
			N->_right = NULL;
			N->_dad = parent;
			N->_end = _end;
			N->_height = 1;
			N->_key = _allocPair.allocate(1);
			_allocPair.construct(N->_key, value);
			return (N);
		}

		void	free_node(node *N)
		{
			// std::cout << "NODE FREE = " << N->_key->first << " END = " << N->_end << std::endl;

			// std::cout << "REAL DESTROY = " << N->_key->first << " POINTER = " << N->_key << std::endl;
			if (N->_key)
			{
				_allocPair.deallocate(N->_key, 1);
				// _allocPair.destroy(N->_key);
				N->_key = NULL;
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
				_size++;
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
		node *node_value_min(node *N) const
		{
			node *temp = N;
			while (temp->_left != NULL)
				temp = temp->_left;
			return temp;
		}

		node *node_value_max(node *N) const
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
						// std::cout << root->_key->first << " " << temp->_key->first << std::endl;
						root->_key = temp->_key;
						root->_left = temp->_left;
						root->_right = temp->_right;
						// root->_end = temp->_end;

						temp->_key = swap._key;

						// std::cout <<"AFTER ROOT DAD " << _root->_right->_dad->_key->first << "-----" << std::endl;

						// std::cout <<"AFTER ROOT " << _root->_right->_key->first << "-----" << std::endl;
					}
						_size--;
						// std::cout << "SIZE " << _size + 1 << " IS NOW " << _size << " after deleting node " << temp->_key->first << std::endl;
						free_node(temp);
				}
				else
				{
					node swap;

					swap._key = root->_key;

					node *temp = node_value_min(root->_right);

					if (temp->_key->first == root->_right->_key->first)
					{
						root->_right = root->_right->_right;
					}
					else
					{
						temp->_dad->_left = NULL;
					}
					root->_key = temp->_key;

					temp->_key = swap._key;
					if (temp->_right)
						temp->_right->_dad = root;
					_size--;
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
		//FIXME    HERE
		void	initialize_end()
		{ _end = new_node(value_type(key_type(), mapped_type()), NULL); }

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
				printInfoNode(root);
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

	template < typename Key, typename T, typename Compare, typename Allocator >
	bool operator==(const ft::map<Key,T,Compare,Allocator>& lhs, const ft::map<Key,T,Compare,Allocator>& rhs)
	{
		if (lhs.size() != rhs.size())
			return 0;
		typename ft::map<Key,T,Compare,Allocator>::const_iterator it_r = rhs.begin();
		typename ft::map<Key,T,Compare,Allocator>::const_iterator it_l = lhs.begin();

		while (it_l != lhs.end())
		{
			if (*it_l != *it_r)
				return 0;
			it_l++;
			it_r++;
		}
		return 1;
	}

	template < typename Key, typename T, typename Compare, typename Allocator >
	bool operator!=(const ft::map<Key,T,Compare,Allocator>& lhs, const ft::map<Key,T,Compare,Allocator>& rhs)
	{ return (!(lhs == rhs)); }

	template < typename Key, typename T, typename Compare, typename Allocator >
	bool operator<(const ft::map<Key,T,Compare,Allocator>& lhs, const ft::map<Key,T,Compare,Allocator>& rhs)
	{ return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()); }

	template < typename Key, typename T, typename Compare, typename Allocator >
	bool operator<=(const ft::map<Key,T,Compare,Allocator>& lhs, const ft::map<Key,T,Compare,Allocator>& rhs)
	{
		if (lhs == rhs)
			return true;
		return (lhs < rhs);
	}
	template < typename Key, typename T, typename Compare, typename Allocator >
	bool operator>(const ft::map<Key,T,Compare,Allocator>& lhs, const ft::map<Key,T,Compare,Allocator>& rhs)
	{
		if (lhs == rhs)
			return false;
		return (!(lhs < rhs));
	}

	template < typename Key, typename T, typename Compare, typename Allocator >
	bool operator>=(const ft::map<Key,T,Compare,Allocator>& lhs, const ft::map<Key,T,Compare,Allocator>& rhs)
	{
		if (lhs == rhs)
			return true;
		return (!(lhs < rhs));
	}

	template < typename Key, typename T, typename Compare, typename Allocator >
	void swap( ft::map<Key,T,Compare,Allocator>& lhs, ft::map<Key,T,Compare,Allocator>& rhs )
	{ lhs.swap(rhs); }

}
#endif
