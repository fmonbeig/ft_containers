/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 11:34:07 by fmonbeig          #+#    #+#             */
/*   Updated: 2022/06/02 15:01:24 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_ITERATOR_HPP
#define MAP_ITERATOR_HPP

#include "map.hpp"
#include <iostream>
#include <cstddef>

namespace ft
{
	template<typename node, typename T>
	class map_iterator
	{
		public:
			typedef	T								value_type; // T is a std::pair here
			typedef	T*								pointer;
			typedef	T&								reference;
			typedef	std::ptrdiff_t					difference_type;
			typedef	std::size_t						size_type;
			typedef std::bidirectional_iterator_tag	iterator_category;

		private:
			node *_current;

		public:
			map_iterator(){_current = NULL; }
			map_iterator(node *ptr){ _current = ptr; }
			map_iterator( const map_iterator& other ) { _current = other._current; };

			map_iterator &operator=(map_iterator const &rhs)
			{
				if (this != &rhs)
					this->_current = rhs._current;
				return (*(this));
			}

			pointer operator->() const { return _current->_key; }

			// +------------------------------------------+ //
			//   OPERATOR							        //
			// +------------------------------------------+ //

			map_iterator& operator++()
			{
				if (_current->_right)
					_current = _current->_right;
				else if (_current->_right == NULL)
				{
					if (_current->_dad)
						_current = _current->_dad;
					else
						_current = _current->_right;
				}
				return *this;
			}

			map_iterator operator++(int)
			{
				node *temp = _current;
				++(*this);
				return (map_iterator(temp));
			}

			map_iterator& operator--()
			{
				_current = _current->_left;
				return *this;
			}

			map_iterator operator--(int)
			{
				node *temp = _current;
				--(*this);
				return (map_iterator(temp));
			}

			// vector_iterator& operator++() { _ptr++; return *this; }
			// vector_iterator& operator--() { _ptr--; return *this; }
			// vector_iterator operator++(int) {_ptr++; return (vector_iterator(_ptr - 1)); }
			// vector_iterator operator--(int) { _ptr--; return (vector_iterator(_ptr + 1)); }

	};
}

#endif
