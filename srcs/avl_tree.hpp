/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avl_tree.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 16:17:36 by fmonbeig          #+#    #+#             */
/*   Updated: 2022/05/31 16:26:09 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AVL_TREE_HPP
#define AVL_TREE_HPP

#include "utils.hpp"
#include <memory>

namespace ft
{
	// T sera un makepair<x, y>
	template<typename T, typename Compare, typename Allocator>
	class avl_tree
	{
		public:
			struct node
			{
				T		*_key;
				node	*_dad;
				node	*_left;
				node	*_right;
				int		_height;
			};

		protected:
			Allocator				_allocPair;
			std::allocator<node>	_allocNode;
			Compare					_comp;
			Allocator				_alloc;
			node					*_root;

		public:
			avl_tree(const Compare &comp, const Allocator& alloc)
			{
				_alloc = alloc;
				_comp = comp;
				_root = NULL;
			}

			~avl_tree() {}
			//destroy every node

			void	insert(const T& value )
			{
				if (_root == NULL)
					_root = new_node(value);
			}

			T	*rootKey()
			{
				return (_root->_key);
			}

			node	*new_node(const T& value)
			{
				node *ptr = _allocNode.allocate(1);
				ptr->_dad = NULL;
				ptr->_left = NULL;
				ptr->_right = NULL;
				ptr->_height = 0;
				ptr->_key = _allocPair.allocate(1);
				_allocPair.construct(ptr->_key, value);
				return (ptr);
			}
	};
}

#endif

/*
	Tree Height ==> single node = 0
	Balance == We need a treshold of one

	Si dernier node alors 0 en
	B(h) = H(Lchild) - H(Rchild)
	si positif alors left heavy si negative alors right heavy
	Rotation
	left Heavy

	Insert (respect balance after each insert)
	1 - Calculer la taille de l'arbre pour savoir s'il va etre balance
	2 - faire des rotations pour le balance ( right / left / right-left / left-right)


*/
