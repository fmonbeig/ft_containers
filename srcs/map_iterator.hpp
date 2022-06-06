/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 11:34:07 by fmonbeig          #+#    #+#             */
/*   Updated: 2022/06/06 17:30:02 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_ITERATOR_HPP
#define MAP_ITERATOR_HPP

#include "map.hpp"
#include <iostream>
#include <cstddef>

namespace ft
{
	template<typename Compare, typename node, typename T>
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
			node 	*_current;
			Compare	_comp;

		public:
			map_iterator(): _current(NULL){}
			map_iterator(node *ptr): _current(ptr), _comp(Compare()) {}
			map_iterator( const map_iterator& other ) { _current = other._current; _comp = other._comp;};

			virtual ~map_iterator(){};

			map_iterator &operator=(map_iterator const &rhs)
			{
				if (this != &rhs)
					this->_current = rhs._current;
				return (*(this));
			}
			map_iterator & operator+=( difference_type n )
			{
				for (int i = 0; i < n; ++i)
					_current++;
				return (*this);
			}
			map_iterator & operator-=( difference_type n )
			{
				for (int i = 0; i < n; ++i)
					_current--;
				return (*this);
			}

			operator map_iterator<Compare, node, T const>() const
			{	return (map_iterator<Compare, node, T const>(_current)); };

			reference operator*() const { return *_current->_key; }
			pointer operator->() const { return _current->_key; }

			// +------------------------------------------+ //
			//   OPERATOR							        //
			// +------------------------------------------+ //

			map_iterator& operator++()
			{
				// if (_current->_dad)
				// 	std::cout <<"NODE " << _current->_key->first <<" DAD " << _current->_dad->_key->first << " END ?? = " << _current->_end<< std::endl;
				// if(_current  == find_last(_current))
				// {
				// 	_current = find_end(_current);
				// 		std::cout << " FIND END" << std::endl;
				// 	return *this;
				// }
				if (_current->_right)
				{
					_current = _current->_right;
					while (_current->_left != NULL)
						_current = _current->_left;
				}
				else if (_current->_right == NULL)
				{
					node *temp = _current;
					if (_comp(_current->_key->first, _current->_dad->_key->first))
						_current = _current->_dad;
					else
					{
						// std::cout << "********1" << std::endl;
						while (_current->_dad && (!(_comp(_current->_key->first, _current->_dad->_key->first))))
						{
							_current = _current->_dad;
							// std::cout << " NOUVEAU NODE " << _current->_key->first << std::endl;
						}
						if (_current->_dad && _comp(_current->_key->first, _current->_dad->_key->first))
						{
								// std::cout << "**********2" << std::endl;
							_current = _current->_dad;
							// std::cout << " NOUVEAU NODE FINAL " << _current->_key->first << std::endl;
						}
						if (_comp(_current->_key->first, temp->_key->first))
						{
								// std::cout << "**********3" << std::endl;
							_current = temp->_end;
						}
					}
				}
				// std::cout <<"APRES ++ " << _current->_key->first << std::endl;
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
				if (_current->_left)
				{
					_current = _current->_left;
					while (_current->_right)
						_current = _current->_right;
				}
				else
				{
					while (_current->_dad && (_comp(_current->_key->first, _current->_dad->_key->first)))
						_current = _current->_dad;
					if (_current->_dad && (!_comp(_current->_key->first, _current->_dad->_key->first)))
						_current = _current->_dad;
				}
				return *this;
			}

			map_iterator operator--(int)
			{
				node *temp = _current;
				--(*this);
				return (map_iterator(temp));
			}

			bool operator==(const map_iterator& rhs)
			{ return (_current == rhs._current); }

			bool operator!=(const map_iterator& rhs)
			{ return (_current != rhs._current); }

			node *find_end(node *N)
			{
				node *temp = N;

				while (temp->_dad)
					temp = temp->_dad;
				while (temp->_right)
					temp = temp->_right;
				return temp->_end;
			}

			node *find_last(node *N)
			{
				node *temp = N;

				while (temp->_dad)
					temp = temp->_dad;
				while (temp->_right)
					temp = temp->_right;
				return temp;
			}

			node	*getnode()
			{ return _current;}

	};
}

#endif
