/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 16:57:32 by fmonbeig          #+#    #+#             */
/*   Updated: 2022/05/18 14:52:53 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <limits>
#include <string>
#include <memory>
#include <sstream>
#include <stdexcept>
#include "utility.hpp"
#include "iterator_traits.hpp"
#include "reverse_iterator.hpp"
#include "vector_iterator.hpp"

namespace ft
{
template<class T, class Allocator = std::allocator<T> >
class vector
{
	public:
		// +------------------------------------------+ //
		//   MEMBER TYPE						        //
		// +------------------------------------------+ //
		typedef	T											value_type;
		typedef Allocator									allocator_type;
		typedef typename Allocator::reference				reference;		 //T&
		typedef typename Allocator::const_reference			const_reference; //const T&
		typedef typename Allocator::pointer					pointer;		// T*
		typedef typename Allocator::const_pointer			const_pointer; // const T*
		typedef std::size_t									size_type;
		typedef std::ptrdiff_t								difference_type;
		typedef ft::vector_iterator<T>						iterator; // pas besoin de faire de classe iterateur on peut juste ecrire T
		typedef ft::vector_iterator<T const>				const_iterator; // T*
		typedef ft::reverse_iterator<iterator>				reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator; //FIXME Problem on this one

		// +------------------------------------------+ //
		//   MEMBER FUNCTIONS							//
		// +------------------------------------------+ //

		explicit vector(const Allocator& alloc = Allocator())
		{
			_alloc = alloc;
			_ptr = _alloc.allocate(0);
			_size = 0;
			_cap = 0;
		}		// Create the first pointer

		explicit vector( size_type count, const T& value = T(), const Allocator& alloc = Allocator())
		{
			_ptr = alloc;
			_ptr = _alloc.allocate(count);
			for (size_t i = 0; i < count; i++)
				_alloc.construct(_ptr + i, value);
			_size = count;
			_cap = count;
		}		//how to use --> it std::vector<int> v(size);

		template< class InputIt >
		vector( InputIt first, InputIt last, const Allocator& alloc = Allocator())
		{
			_alloc = alloc;
			_ptr = _alloc.allocate(0);
			_size = 0;
			_cap = 0;
			this->assign(first,last);
		}

		vector( const vector& other )
		{
			_ptr = _alloc.allocate(other._size);
			for (size_t i = 0; i < other._size; i++)
				_alloc.construct(_ptr + i, other._ptr[i]);
			_size = other._size;
			_cap = other._cap;
		}

		~vector()
		{
			this->clear();
			_alloc.deallocate(_ptr, _cap);
		}

		vector & operator=(vector & other)
		{
			this->clear();
			_alloc.deallocate(_ptr, _cap);

			_ptr = _alloc.allocate(other._cap);
			for (size_t i = 0; i < other._size; i++)
				_alloc.construct(_ptr + i, other._ptr[i]);
			_size = other._size;
			return *this;
		}

		void assign( size_type count, const T& value )
		{
			// std::cout << "NORMAL" << std::endl;
			this->clear();
			this->reserve(count);
			_size = count;
			for (size_t i = 0; i < _size; i++)
				_alloc.construct(_ptr + i, value);
		}

		/* if is_integral::value is true (int...) the ::type will be valid
		in this case we inverse the ::value to avoid integral type */

		template< class InputIt >
		void assign(InputIt first, InputIt last,
			typename ft::enable_if<!ft::is_integral<InputIt>::value>::type* = 0)
		{
			size_t count = 0;

			this->clear();
			for (int i = 0; (first + i) != last; i++)
				count++;
			this->reserve(count);
			_size = count;
			for (size_t i = 0; i < _size; i++)
				_alloc.construct(_ptr + i, *(first + i));
		}

		allocator_type get_allocator() const
		{ return (_ptr); }

		// +------------------------------------------+ //
		//   FRIEND								        //
		// +------------------------------------------+ //

		// +------------------------------------------+ //
		//   ELEMENT ACCESS						        //
		// +------------------------------------------+ //

		reference at( size_type pos )
		{
			if (pos > _size)
			{
				std::stringstream ss;
				std::stringstream ss2;
				std::string str_pos;
				std::string str_size;

				ss << pos;
				ss >> str_pos;
				ss2 << _size;
				ss2 >> str_size;
				throw std::out_of_range("vector::_M_range_check: __n (which is " + str_pos + ") >= this->size() (which is " + str_size + ")");
			}
			return (_ptr[pos]);
		}

		const_reference at( size_type pos ) const
		{
			if (pos > _size)
			{
				std::stringstream ss;
				std::stringstream ss2;
				std::string str_pos;
				std::string str_size;

				ss << pos;
				ss >> str_pos;
				ss2 << _size;
				ss2 >> str_size;
				throw std::out_of_range("vector::_M_range_check: __n (which is " + str_pos + ") >= this->size() (which is " + str_size + ")");
			}
			return (_ptr[pos]);
		}

		reference operator[](unsigned int index) { return (_ptr[index]); }
		const_reference operator[]( unsigned int index ) const { return (_ptr[index]); }

		reference front() { return (_ptr[0]);}
		const_reference front() const { return (_ptr[0]);}

		reference back() { return (_ptr[_size - 1]);}
		const_reference back() const { return (_ptr[_size - 1]);}

		T*	data() { return _ptr; }
		const T* data() const { return _ptr; }

		// +------------------------------------------+ //
		//   ITERATORS							        //
		// +------------------------------------------+ //

		iterator 		begin() { iterator it(_ptr); return (it);}
		const_iterator	begin() const { const_iterator it(_ptr); return (it);}

		iterator		end() { iterator it(_ptr + _size); return (it);}
		const_iterator	end() const	 { const_iterator it(_ptr + _size); return (it);}

		reverse_iterator		rbegin() { return reverse_iterator(_ptr + _size - 1); }
		const_reverse_iterator	rbegin() const { return const_reverse_iterator(_ptr + _size - 1); }

		reverse_iterator		rend() { return reverse_iterator(_ptr - 1); }
		const_reverse_iterator	rend() const { return const_reverse_iterator(_ptr - 1); }

		// +------------------------------------------+ //
		//   CAPACITY							        //
		// +------------------------------------------+ //

		bool empty() const
		{
			if (_size == 0)
				return true;
			return false;
		}

		void reserve( size_type new_cap )
		{
			if (new_cap > this->max_size())
				throw std::length_error("vector");
			if (new_cap > _cap)
			{
				T* temp = _alloc.allocate(new_cap);

				for (size_t i = 0; i < _size; i++)
				{
					_alloc.construct(temp + i, _ptr[i]);
					_alloc.destroy(_ptr + i);
				}
				_alloc.deallocate(_ptr, _cap);
				_ptr = temp;
				_cap = new_cap;
			}
		}

		size_type size() const { return _size; }
		size_type max_size() const { return std::numeric_limits<difference_type>::max(); }
		size_type capacity() const { return _cap; }


		// +------------------------------------------+ //
		//   MODIFIERS							        //
		// +------------------------------------------+ //

		void push_back( const T& value )
		{
			if (_size + 1 > _cap)
			{
				if (_size == 0)
					this->reserve(2);
				else
					this->reserve(_size * 2);
			}
			_alloc.construct(_ptr + _size, value);
			_size++;
		}

		void clear()
		{
			for (size_t i = 0; i < _size; i++)
				_alloc.destroy(_ptr + i);
			_size = 0;
		}

		iterator insert( iterator pos, const T& value )
		{
			difference_type index = pos - begin();

			insert(pos, 1, value);
			return begin() + index;
		}

		void insert( iterator pos, size_type count, const T& value )
		{
			difference_type index = pos - begin();

			if (count == 0)
				return ;
			if (_size + count > _cap)
				this->reserve(_cap + count);
			iterator newPos(&_ptr[index]);
			movePtrRight(count, newPos, end());
			for (size_t i = 0; i < count; i++)
				_alloc.construct(&(*(newPos + i)), value);
			_size += count;
		}

		// template< class InputIt >
		// void insert( iterator pos, InputIt first, InputIt last );

	private:
		pointer			_ptr;
		allocator_type	_alloc;
		size_t			_size; // how many construct object they are
		size_t			_cap; // how many memory they are

		void movePtrRight(size_t count, iterator start, iterator end)
		{
			for (iterator it = end - 1; it != start - 1; it--)
			{
				_alloc.construct(&(*(it + count)), *it);
				_alloc.destroy(&(*(it)));
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
 */

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
