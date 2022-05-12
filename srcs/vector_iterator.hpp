/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 10:57:09 by fmonbeig          #+#    #+#             */
/*   Updated: 2022/05/12 17:55:44 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_ITERATOR
#define VECTOR_ITERATOR

namespace ft
{
	template<class T>
	class vector_iterator
	{
		typedef	T				value_type;
		typedef	T*				pointer;
		typedef	T&				reference;
		typedef	std::ptrdiff_t	difference_type;
		typedef	std::size_t		size_type;

		protected:
			T* _ptr;

		public:
			vector_iterator(){_ptr = NULL; }
			vector_iterator(T *pointer){ _ptr = pointer; }
			vector_iterator( const vector_iterator<T>& other ) { _ptr = other._ptr; };

			vector_iterator & operator=(const vector_iterator & rhs) { _ptr = rhs._ptr; return (*this);}
			vector_iterator & operator+=( difference_type n ) { _ptr += n; return (*this); }
			vector_iterator & operator-=( difference_type n ) { _ptr -= n; return (*this); }

			// +------------------------------------------+ //
			//   ACCESS							            //
			// +------------------------------------------+ //

			reference operator*() const { return *_ptr; }
			pointer operator->() const { return _ptr; }
			reference operator[](difference_type n) const{ return _ptr + n; }

			// +------------------------------------------+ //
			//   OPERATOR							        //
			// +------------------------------------------+ //

			vector_iterator& operator++() { _ptr++; return *this; }
			vector_iterator& operator--() { _ptr--; return *this; }
			vector_iterator operator++(int) {_ptr++; return (vector_iterator(_ptr - 1)); }
			vector_iterator operator--(int) { _ptr--; return (vector_iterator(_ptr + 1)); }

			vector_iterator operator+( difference_type n ) const { _ptr + n; return *this;}
			vector_iterator operator-( difference_type n ) const { _ptr - n; return *this;}

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
	};
}


	// template <class it>
	// class vector_iterator {
	// public:
	// 	// -structors
	// 	vector_iterator			(void)												{ _it = it(); }
	// 	vector_iterator			(typename it::value_type * ptr)						{ _it = it(ptr); }
	// 	vector_iterator			(const it & x)										{ _it = x; --_it; }
	// 	~vector_iterator			(void)												{}
	// 	// Conversion
	// 	template <class U>			friend class										vector_iterator;
	// 	template <class U>
	// 	vector_iterator			(const vector_iterator<U> & x)						{ _it = x.getIt(); }

	// 	// Assignment
	// 	vector_iterator &			operator=	(const vector_iterator & x)			{ _it = x.getIt(); return (*this); }
	// 	vector_iterator &			operator+=	(int n)									{ _it -= n; return (*this); }
	// 	vector_iterator &			operator-=	(int n)									{ _it += n; return (*this); }
	// 	// Comparison
	// 	template <class U> bool		operator==	(const vector_iterator<U> & x) const	{ return (_it == x.getIt()); }
	// 	template <class U> bool		operator!=	(const vector_iterator<U> & x) const	{ return (_it != x.getIt()); }
	// 	template <class U> bool		operator<	(const vector_iterator<U> & x) const	{ return (_it > x.getIt()); }
	// 	template <class U> bool		operator>	(const vector_iterator<U> & x) const	{ return (_it < x.getIt()); }
	// 	template <class U> bool		operator<=	(const vector_iterator<U> & x) const	{ return (_it >= x.getIt()); }
	// 	template <class U> bool		operator>=	(const vector_iterator<U> & x) const	{ return (_it <= x.getIt()); }
	// 	// -crementation
	// 	vector_iterator &			operator++	(void)									{ --_it; return (*this); }
	// 	vector_iterator &			operator--	(void)									{ ++_it; return (*this); }
	// 	vector_iterator			operator++	(int)									{ vector_iterator<it> x(*this); --_it; return (x); }
	// 	vector_iterator			operator--	(int)									{ vector_iterator<it> x(*this); ++_it; return (x); }
	// 	// Operation
	// 	vector_iterator			operator+	(int n) const							{ return (_it - n + 1); }
	// 	vector_iterator			operator-	(int n) const							{ return (_it + n + 1); }
	// 	std::ptrdiff_t				operator-	(const vector_iterator & x) const		{ return (x.getIt() - _it); }
	// 	// Dereference
	// 	typename it::value_type &	operator[]	(size_t n) const						{ return (*(_it - n)); }
	// 	typename it::value_type &	operator*	(void) const							{ return (*_it); }
	// 	typename it::value_type *	operator->	(void) const							{ return (&(*_it)); }
	// 	// Member functions
	// 	it							base		(void)									{ return (++it(_it)); }
	// 	it							getIt		(void) const							{ return (_it); }
	// 	// Non-member functions
	// 	friend vector_iterator		operator+	(int n, const vector_iterator & x)		{ return (x.getIt() - n + 1); }

	// private:
	// 	it		_it;
	// };


#endif
