/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 10:57:09 by fmonbeig          #+#    #+#             */
/*   Updated: 2022/05/17 11:26:52 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_ITERATOR
#define VECTOR_ITERATOR

#include "iterator_traits.hpp"

namespace ft
{
	template<class T>
	class vector_iterator
	{
		public:

			typedef	T				value_type;
			typedef	T*				pointer;
			typedef	T&				reference;
			// typedef	const T*		const_pointer;
			// typedef	const T&		const_reference;
			typedef	std::ptrdiff_t	difference_type;
			typedef	std::size_t		size_type;

			vector_iterator(){_ptr = NULL; }
			vector_iterator(pointer p){ _ptr = p; }
			vector_iterator( const vector_iterator<T>& other ) { _ptr = other._ptr; };

			vector_iterator & operator=(const vector_iterator & rhs) { _ptr = rhs._ptr; return (*this);}
			vector_iterator & operator+=( difference_type n ) { _ptr += n; return (*this); }
			vector_iterator & operator-=( difference_type n ) { _ptr -= n; return (*this); }

			// +------------------------------------------+ //
			//   ACCESS							            //
			// +------------------------------------------+ //

			// Implicit conversion to const T
			operator vector_iterator<T const>() const
			{	return (vector_iterator<T const>(_ptr)); };

			reference operator*() const { return *_ptr; }
			pointer operator->() const { return _ptr; }
			reference operator[](difference_type n) const{ return _ptr + n; }
			// NB : Const version ??

			// +------------------------------------------+ //
			//   OPERATOR							        //
			// +------------------------------------------+ //

			vector_iterator& operator++() { _ptr++; return *this; }
			vector_iterator& operator--() { _ptr--; return *this; }
			vector_iterator operator++(int) {_ptr++; return (vector_iterator(_ptr - 1)); }
			vector_iterator operator--(int) { _ptr--; return (vector_iterator(_ptr + 1)); }

			vector_iterator operator+( difference_type n ) const
			{
				vector_iterator temp(*this);
				return (temp += n);
			}

			vector_iterator operator-( difference_type n ) const
			{
				vector_iterator temp(*this);
				return (temp -= n);
			}

			difference_type operator+(const vector_iterator & x)  { return (_ptr + x._ptr); }
			difference_type operator-(const vector_iterator & x)  { return (_ptr - x._ptr); }

			bool operator==(const vector_iterator<T>& rhs)
			{ return (_ptr == rhs._ptr); }
			bool operator!=(const vector_iterator<T>& rhs)
			{ return (_ptr != rhs._ptr); }
			bool operator<(const vector_iterator<T>& rhs)
			{ return (_ptr < rhs._ptr); }
			bool operator<=(const vector_iterator<T>& rhs)
			{ return (_ptr <= rhs._ptr); }
			bool operator>(const vector_iterator<T>& rhs)
			{ return (_ptr > rhs._ptr); }
			bool operator>=(const vector_iterator<T>& rhs)
			{ return (_ptr >= rhs._ptr); }

			protected:
				pointer _ptr;
	};
}

#endif
