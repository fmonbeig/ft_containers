/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 16:57:32 by fmonbeig          #+#    #+#             */
/*   Updated: 2022/04/19 15:29:15 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <string>
#include <memory>

namespace ft
{

template<class T, class Allocator = std::allocator<T> >
class vector
{
	public:
		// types:
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
};
#endif

// Array<T>(unsigned int n): _size(n)
// 		{
// 			if (n != 0)
// 				this->array = new T[n];
// 			else
// 				this->array = new T[0];
// 		}

// 		Array<T>(Array const & other )
// 		{
// 			this->_size = other._size;
// 			this->array = new T[_size];
// 			for (unsigned int i = 0; i < _size; i++)
// 				this->array[i] = other.array[i];
// 		}

// 		virtual ~Array<T>(void)
// 		{
// 			if (this->array)
// 				delete [] this->array;
// 		}

// 		Array & operator=(Array const & other)
// 		{
// 			this->_size = other._size;
// 			if (this->array)
// 				delete [] this->array;
// 			this->array = new T[_size];
// 			for (unsigned int i = 0; i < _size; i++)
// 				this->array[i] = other.array[i];
// 			return *this;
// 		}

// 		class OutArrayIndex: public std::exception{
// 			public:
// 				virtual const char* what() const throw()
// 				{ return ("\e[0;31mERROR: You are out of the Array index\e[0m");} };

// 		unsigned int	size() const
// 		{
// 			return (_size);
// 		}

// 		T & operator[](unsigned int index)
// 		{
// 			if (index >= size() || index < 0)
// 				throw OutArrayIndex();
// 			return (this->array[index]);
// 			exit(0);
// 		}
