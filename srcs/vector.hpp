/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 16:57:32 by fmonbeig          #+#    #+#             */
/*   Updated: 2022/06/10 16:05:56 by fmonbeig         ###   ########.fr       */
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
#include "utils.hpp"
#include "reverse_iterator.hpp"

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
		typedef T*											iterator;
		typedef const T*									const_iterator;
		typedef ft::reverse_iterator<iterator>				reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;

		// +------------------------------------------+ //
		//   MEMBER FUNCTIONS							//
		// +------------------------------------------+ //

		explicit vector(const Allocator& alloc = Allocator())
		{
			_alloc = alloc;
			_ptr = _alloc.allocate(0);
			_size = 0;
			_cap = 0;
		}

		explicit vector( size_type count, const T& value = T(), const Allocator& alloc = Allocator())
		{
			_alloc = alloc;
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
			_alloc = other._alloc;
			_ptr = _alloc.allocate(other._cap);
			_size = other._size;
			_cap = other._cap;
			for (size_t i = 0; i < other._size; i++)
				_alloc.construct(_ptr + i, other._ptr[i]);
		}

		~vector()
		{
			this->clear();
			_alloc.deallocate(_ptr, _cap);
		}

		vector & operator=(vector const & other)
		{
			this->clear();
			_alloc = other._alloc;
			_alloc.deallocate(_ptr, _cap);

			_ptr = _alloc.allocate(other._cap);
			for (size_t i = 0; i < other._size; i++)
				_alloc.construct(_ptr + i, other._ptr[i]);
			_size = other._size;
			_cap = other._cap;
			return *this;
		}

		void assign( size_type count, const T& value )
		{
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
			difference_type count = std::distance(first, last);

			this->clear();
			if (count)
				this->reserve(count);
			_size = count;
			for (iterator i = begin(); i < begin() + count; i++)
				_alloc.construct(i, *first++);
		}

		// template< class InputIt >
		// void assign(InputIt first, InputIt last,
		// 	typename ft::enable_if<!ft::is_integral<InputIt>::value>::type* = 0)
		// {
		// 	size_t count = 0;

		// 	this->clear();
		// 	for (int i = 0; (first + i) != last; i++)
		// 		count++;
		// 	this->reserve(count);
		// 	_size = count;
		// 	for (size_t i = 0; i < _size; i++)
		// 		_alloc.construct(_ptr + i, *(first + i));
		// }

		allocator_type get_allocator() const
		{ return (_ptr); }

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

		iterator 		begin() { return (_ptr);}
		const_iterator	begin() const { return (_ptr);}

		iterator		end() { return (_ptr + _size);}
		const_iterator	end() const	 { return ((_ptr + _size));}

		reverse_iterator		rbegin() { return reverse_iterator(end()); }
		const_reverse_iterator	rbegin() const { return const_reverse_iterator(end()); }

		reverse_iterator		rend() { return reverse_iterator(begin()); }
		const_reverse_iterator	rend() const { return const_reverse_iterator(begin()); }

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
				throw std::length_error("vector::reserve");
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
		size_type max_size() const { return _alloc.max_size(); }
		size_type capacity() const { return _cap; }


		// +------------------------------------------+ //
		//   MODIFIERS							        //
		// +------------------------------------------+ //

		void push_back( const T& value )
		{
			if (_size + 1 > _cap)
			{
				if (_size == 0)
					this->reserve(1);
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
			if (_size + count > _cap * 2)
				this->reserve(_cap + count);
			else if (_size + count < _cap * 2 && _size + count > _cap)
				this->reserve(_cap * 2);
			iterator newPos(&_ptr[index]);
			movePtrRight(count, newPos, end());
			for (size_t i = 0; i < count; i++)
				_alloc.construct(&(*(newPos + i)), value);
			_size += count;
		}

		template< class InputIt >
		void insert( iterator pos, InputIt first, InputIt last,
			typename ft::enable_if<!ft::is_integral<InputIt>::value>::type* = 0)
		{
			difference_type index = pos - begin();
			difference_type count = std::distance(first, last);
			// difference_type count = last - first;

			if (count == 0)
				return ;
			if (_size + count > _cap * 2)
				this->reserve(_cap + count);
			else if (_size + count < _cap * 2 && _size + count > _cap)
				this->reserve(_cap * 2);
			iterator newPos(&_ptr[index]);
			movePtrRight(count, newPos, end());
			for (long i = 0; i < count; i++)
				_alloc.construct(&(*(newPos + i)), *first++);
			_size += count;
		}

		// template< class InputIt >
		// void insert( iterator pos, InputIt first, InputIt last,
		// 	typename ft::enable_if<!ft::is_integral<InputIt>::value>::type* = 0)
		// {
		// 	difference_type index = pos - begin();
		// 	difference_type count = last - first;

		// 	if (count == 0)
		// 		return ;
		// 	if (_size + count > _cap * 2)
		// 		this->reserve(_cap + count);
		// 	else if (_size + count < _cap * 2 && _size + count > _cap)
		// 		this->reserve(_cap * 2);
		// 	iterator newPos(&_ptr[index]);
		// 	movePtrRight(count, newPos, end());
		// 	for (long i = 0; i < count; i++)
		// 		_alloc.construct(&(*(newPos + i)), *(first + i));
		// 	_size += count;
		// }

		iterator erase( iterator pos )
		{
			difference_type index = pos - begin();

			_alloc.destroy(&(*(pos)));
			movePtrLeft(1, pos);
			_size -= 1;
			return begin() + index;
		}

		iterator erase( iterator first, iterator last,
			typename ft::enable_if<!ft::is_integral<iterator>::value>::type* = 0)
		{
			difference_type index = first - begin();
			difference_type count = last - first;

			for(int i = 0; (first + i) != last; i++)
				_alloc.destroy(&(*(first + i)));
			movePtrLeft(count, first);
			_size -= count;
			return begin() + index;
		}

		void pop_back(){ _alloc.destroy(&(*(end() - 1))); _size -= 1;}

		void resize( size_type count, T value = T() )
		{
			checkSize(count);
			if (count == 0)
				return (clear());
			if (_size == count)
				return ;
			if (_size > count)
			{
				iterator it = end();
				size_t diff = _size - count;
				while (diff--)
					this->_alloc.destroy(--it);
			}
			if (_size < count)
			{
				if (count > _cap * 2)
					this->reallocateMemoryAndValue(count, count, value);
				else
					this->reallocateMemoryAndValue(_cap * 2, count, value);
			}
			_size = count;
		}

		void swap( vector& other )
		{
			swapping(_ptr, other._ptr);
			swapping(_alloc, other._alloc);
			swapping(_size, other._size);
			swapping(_cap, other._cap);
		}

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

		void movePtrLeft(size_t count, iterator first)
		{
			for (; first + count != end() ; first++)
			{
				_alloc.construct(&(*(first)), *(first + count));
				_alloc.destroy(&(*(first + count)));
			}
		}

		void checkSize(size_t n)
		{
			if (n > max_size()) //NB ca serait alloc.max_size() ??
				throw std::out_of_range("vector");
		}

		void reallocateMemoryAndValue(size_t new_cap, size_t new_size, T value = T())
		{
			size_t i = 0;

			if (new_cap > this->max_size())
				throw std::length_error("vector");

			T* temp = _alloc.allocate(new_cap);

			for (; i < _size; i++)
			{
				_alloc.construct(temp + i, _ptr[i]);
				_alloc.destroy(_ptr + i);
			}
				for (; i < new_size ; i++)
					_alloc.construct(temp + i, value);
			_alloc.deallocate(_ptr, _cap);
			_ptr = temp;
			_cap = new_cap;
		}

		template <typename X>
		void swapping( X& a, X& b )
		{
			X temp = a;
			a = b;
			b = temp;
		}
};

	template<class T, class Allocator>
	bool operator==(const vector<T, Allocator>& lhs, const vector<T, Allocator>& rhs)
		{ return lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin()); }

	template<class T, class Allocator>
	bool operator<(const vector<T, Allocator>& lhs, const vector<T, Allocator>& rhs)
		{ return (ft::lexicographical_compare(lhs.begin(), lhs.end(),
					  rhs.begin(), rhs.end())); }

	template<class T, class Allocator>
	bool operator!=( const vector<T, Allocator>& lhs, const vector<T, Allocator>& rhs )
	{ return (!(lhs == rhs)); }

	template<class T, class Allocator>
	bool operator<=( const vector<T, Allocator>& lhs, const vector<T, Allocator>& rhs )
	{
		if (lhs == rhs)
			return true;
		return (lhs < rhs);
	}
	template<class T, class Allocator>
	bool operator>( const vector<T, Allocator>& lhs, const vector<T, Allocator>& rhs )
	{
		if (lhs == rhs)
			return false;
		return (!(lhs < rhs));
	}

	template<class T, class Allocator>
	bool operator>=( const vector<T, Allocator>& lhs, const vector<T, Allocator>& rhs )
	{
		if (lhs == rhs)
			return true;
		return (!(lhs < rhs));
	}

	template< class T, class Allocator>
	void swap( ft::vector<T, Allocator>& lhs, ft::vector<T, Allocator>& rhs )
	{ lhs.swap(rhs); }
}
#endif
