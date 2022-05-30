/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avl_tree.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 16:17:36 by fmonbeig          #+#    #+#             */
/*   Updated: 2022/05/30 18:07:54 by fmonbeig         ###   ########.fr       */
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
			typedef typename avl_tree::avl_node node;

		public:
			struct avl_node
			{
				avl_node(T val, node *dad, node *Lchild, node *Rchild):
					_value(val), _dad(dad), _Lchild(Lchild), _Rchild(Rchild)

				T		_value;
				node	*_dad;
				node	*_Lchild;
				node	*_Rchild;
			};

		protected:
			Allocator				_allocPair;
			std::allocator<node>	_allocNode;
			Compare			_comp;
			avl_tree::node	*root;

		public:
			avl_tree(const Compare &comp, const Allocator& alloc)
			{
				_alloc = Allocator();
				_comp = comp;
				root = _allocNode.allocate(1);
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
