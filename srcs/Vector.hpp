/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 16:57:32 by fmonbeig          #+#    #+#             */
/*   Updated: 2022/05/09 18:06:43 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <string>
#include <memory>
#include "utility.hpp"

namespace ft
{
template<class T, class Allocator = std::allocator<T> >
class vector
{
	private:
		// +------------------------------------------+ //
		//   MEMBER OBJECT						        //
		// +------------------------------------------+ //
			allocator_type	_ptr;
			size_t			_size;
			size_t			_cap;
			// T*	_ptr;
			// rajouter une structure d'iterateur avec begin / end ?
	public:
		// +------------------------------------------+ //
		//   MEMBER TYPE						        //
		// +------------------------------------------+ //

		typedef	T										value_type;
		typedef Allocator								allocator_type;
		typedef typename Allocator::reference			reference;
		typedef typename Allocator::const_reference		const_reference;
		typedef typename Allocator::pointer				pointer;
		typedef typename Allocator::const_pointer		const_pointer;
		typedef implementation defined					iterator; //NB : Je ne sais pas trop comment ca fonctionne
		typedef implementation defined					const_iterator;
		typedef implementation defined					size_type;
		typedef implementation defined					difference_type;
		typedef std::reverse_iterator<iterator>			reverse_iterator; //FIXME mettre son iterateur
		typedef std::reverse_iterator<const_iterator>	const_reverse_iterator;

		// +------------------------------------------+ //
		//   MEMBER FUNCTIONS							//
		// +------------------------------------------+ //

		explicit vector(const Allocator& alloc = Allocator())
		{
			_ptr = alloc;
			_ptr.allocate(0);
			_ptr.construct();
			_size = 0;
			_cap = 0;
		} // Create the first pointer

		explicit vector( size_type count, const T& value = T(), const Allocator& alloc = Allocator())
		{
			_ptr = alloc;
			_ptr.allocate(count);
			for (int i = 0; i < count; i++)
				_ptr.construct(_ptr + i, value);
			_size = count;
			_cap = count;
		}		//how to use it std::vector<int> v(size);

		vector( const vector& other )
		{
			_ptr.allocate(other._size);
			for (int i = 0; i < _size.other; i++)
				_ptr.construct(_ptr + i, other._ptr[i]);
			_size = other._size;
			_cap = other._cap;
		}

		~vector()
		{
			for(size_t i = 0; i < _size; i++)
				_ptr.destroy(_ptr + i);
			_ptr.desallocate(_size);
		}

		vector & operator=(vector & other)
		{
			for(size_t i = 0; i < _size; i++)
				_ptr.destroy(_ptr + i);
			_ptr.desallocate(_size);

			_ptr.allocate(other._size);
			for (int i = 0; i < _size.other; i++)
				_ptr.construct(_ptr + i, other._ptr[i]);
			_size = other._size;
			return *this;
		}

		// void assign(InputIterator first, InputIterator last);

		allocator_type get_allocator() const
		{ return (_ptr); }

		// +------------------------------------------+ //
		//   FRIEND								        //
		// +------------------------------------------+ //

		// +------------------------------------------+ //
		//   ELEMENT ACCESS						        //
		// +------------------------------------------+ //

		// +------------------------------------------+ //
		//   CAPACITY							        //
		// +------------------------------------------+ //

		// +------------------------------------------+ //
		//   MODIFIERS							        //
		// +------------------------------------------+ //

		void push_back( const T& value )
		{
			if (_size > _cap)
			{
				allocator_type	temp; // copier _ptr en allouant la mémoire + construct
				// recalculate ALL iterator
				for(size_t i = 0; i < _size; i++)
				_ptr.destroy(_ptr + i);
				_ptr.desallocate(_size);
				// delete + reallocated everything + the value
				// recalculate _size and _cap value
			}
			else
			{
				//recalculate only the last iterator (past the end)
				// add the value
				// recalculate _size and _cap value  .size() + .capacity()

			}
		}
};
}



	// template <class T, class Alloc>
	// bool operator==(const vector<T, Alloc> & lhs, const vector<T, Alloc> & rhs)
	// { return (ft::equal(C.begin(), C.end(), other.begin())); }

	// template< class T, class Alloc >
	// bool operator!=( const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs )
	// { return (lhs == rhs); }

	// template< class T, class Alloc >
	// bool operator<( const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs )
	// { return (ft::lexicographical_compare(C.begin(), C.end(),
	// 				  other.begin(), other.end())); }

	// template< class T, class Alloc >
	// bool operator<=( const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs )
	// {}

	// template< class T, class Alloc >
	// bool operator>( const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs )
	// {

	// }

	// template< class T, class Alloc >
	// bool operator>=( const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs )
	// {

	// }
#endif

/*********
 * Internally, vectors use a dynamically allocated array to store their elements.
 * This array may need to be reallocated in order to grow in size when new elements are inserted,
 * which implies allocating a new array and moving all elements to it.
 * This is a relatively expensive task in terms of processing time, and thus,
 * vectors do not reallocate each time an element is added to the container.

Instead, vector containers may allocate some extra storage to accommodate for possible growth,
and thus the container may have an actual capacity greater than the
storage strictly needed to contain its elements (i.e., its size).
Libraries can implement different strategies for growth to balance between
memory usage and reallocations, but in any case, reallocations should only happen
at logarithmically growing intervals of size so that the insertion of
individual elements at the end of the vector can be provided
with amortized constant time complexity (see push_back).

Therefore, compared to arrays, vectors consume more memory in exchange
for the ability to manage storage and grow dynamically in an efficient way.

Compared to the other dynamic sequence containers
(deques, lists and forward_lists), vectors are very efficient accessing
its elements (just like arrays) and relatively efficient adding or
removing elements from its end. For operations that involve inserting
or removing elements at positions other than the end, they perform worse
than the others, and have less consistent iterators and references than lists and forward_lists.
*/

/************DOC*************
 * OPERATOR	== 402
 * VECTOR	== 484
 *
 * /

/*
		typedef typename Allocator::reference reference;
		typedef typename Allocator::const_reference const_reference;
		typedef implementation defined iterator; // See 23.1
		typedef implementation defined const_iterator; // See 23.1
		typedef implementation defined size_type; // See 23.1
		typedef implementation defined difference_type;// See 23.1
		typedef T value_type;
		typedef Allocator allocator_type;
		typedef typename Allocator::pointer pointer;
		typedef typename Allocator::const_pointer const_pointer
		typedef std::reverse_iterator<iterator> reverse_iterator;
		typedef std::reverse_iterator<const_iterator> const_reverse_iterator;
		//construct/copy/destroy:
		explicit vector(const Allocator& = Allocator());
		explicit vector(size_type n, const T& value = T(),
		const Allocator& = Allocator());

		template <class InputIterator>
		vector(InputIterator first, InputIterator last,
		const Allocator& = Allocator());
		vector(const vector<T,Allocator>& x);
		~vector();

		vector<T,Allocator>& operator=(const vector<T,Allocator>& x);
		template <class InputIterator>
		void assign(InputIterator first, InputIterator last);
		void assign(size_type n, const T& u);
		allocator_type get_allocator() const;

		// iterators:
		iterator begin();
		const_iterator begin() const;
		iterator end();
		const_iterator end() const;
		reverse_iterator rbegin();
		const_reverse_iterator rbegin() const;
		reverse_iterator rend();
		const_reverse_iterator rend() const;

		// 23.2.4.2 capacity:
		size_type size() const;
		size_type max_size() const;
		void resize(size_type sz, T c = T());
		size_type capacity() const;
		bool empty() const;
		void reserve(size_type n);

		// element access:
		reference operator[](size_type n);
		const_reference operator[](size_type n) const;
		const_reference at(size_type n) const;
		reference at(size_type n);
		reference front();
		const_reference front() const;
		reference back();
		const_reference back() const;

		// 23.2.4.3 modifiers:
		void push_back(const T& x);
		void pop_back();
		iterator insert(iterator position, const T& x);
		void insert(iterator position, size_type n, const T& x);
		template <class InputIterator>
		void insert(iterator position,
		InputIterator first, InputIterator last);
		iterator erase(iterator position);
		iterator erase(iterator first, iterator last);
		void swap(vector<T,Allocator>&);
		void clear();
*/
