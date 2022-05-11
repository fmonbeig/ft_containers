/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 10:57:09 by fmonbeig          #+#    #+#             */
/*   Updated: 2022/05/11 18:00:57 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR
#define REVERSE_ITERATOR

#include "iterator_traits.hpp"

namespace ft
{
	template< class Iter >
	class reverse_iterator
	{
		typedef				Iter											iterator_type;
		typedef typename	ft::iterator_traits<Iter>::iterator_category	iterator_category;
		typedef typename	ft::iterator_traits<Iter>::difference_type		difference_type;
		typedef typename	ft::iterator_traits<Iter>::value_type			value_type; //T
		typedef typename	ft::iterator_traits<Iter>::pointer				pointer;    //T*
		typedef typename	ft::iterator_traits<Iter>::reference			reference;  // T&

		protected:
			iterator_type	_it;

		public:
			reverse_iterator(){ _it = Iter(); }
			explicit reverse_iterator( iterator_type x ) { _it = Iter(x); }
			template <class U>
			reverse_iterator( const reverse_iterator<U>& other ) { _it = other._it; };

			reverse_iterator & operator=(reverse_iterator & rhs) { _it = rhs._it; }
			reverse_iterator & operator+=( difference_type n ) { _it -=n, return (*this); }
			reverse_iterator & operator-=( difference_type n ) { _it +=n, return (*this); }

			// +------------------------------------------+ //
			//   ACCESS							            //
			// +------------------------------------------+ //

			reference operator*() const { return *_it; }
			pointer operator->() const { return _it; }
			reference operator[](diffenrence_type n) const
			{
				reverse_iterator temp_it = _it;

				temp_it -= n;
				return (*(temp_it));
			}

			iterator_type base() const
			{
				iterator_type temp = Iter(_it);
				temp++;
				return(temp);
			}

			// +------------------------------------------+ //
			//   OPERATOR							        //
			// +------------------------------------------+ //

			reverse_iterator& operator++() { _it--; return *this; }
			reverse_iterator& operator--() { _it++; return *this; }
			reverse_iterator& operator++(int) { reverse_iterator temp_it(*this); _it--; return temp_it; }
			reverse_iterator& operator--(int) { reverse_iterator temp_it(*this); _it++; return temp_it; }
			reverse_iterator operator+( difference_type n ) const { it - n; return *this;}
			reverse_iterator operator-( difference_type n ) const { it + n; return *this;}

	};

	// +------------------------------------------+ //
	//   OPERATOR NON MEMBER				        //
	// +------------------------------------------+ //
	template <class _IteratorL, class _IteratorR>
	bool operator==(const reverse_iterator<_IteratorL>& lhs, const reverse_iterator<_IteratorR>& rhs)
	{ return (lhs.base() == rhs.base()); }

	template <class _IteratorL, class _IteratorR>
	bool operator!=(const reverse_iterator<_IteratorL>& lhs, const reverse_iterator<_IteratorR>& rhs)
	{ return (lhs.base() != rhs.base()); }

	template <class _IteratorL, class _IteratorR>
	bool operator<(const reverse_iterator<_IteratorL>& lhs, const reverse_iterator<_IteratorR>& rhs)
	{ return (lhs.base() < rhs.base()); }

	template <class _IteratorL, class _IteratorR>
	bool operator<=(const reverse_iterator<_IteratorL>& lhs, const reverse_iterator<_IteratorR>& rhs)
	{ return (lhs.base() <= rhs.base()); }

	template <class _IteratorL, class _IteratorR>
	bool operator>(const reverse_iterator<_IteratorL>& lhs, const reverse_iterator<_IteratorR>& rhs)
	{ return (lhs.base() > rhs.base()); }

	template <class _IteratorL, class _IteratorR>
	bool operator>=(const reverse_iterator<_IteratorL>& lhs, const reverse_iterator<_IteratorR>& rhs)
	{ return (lhs.base() >= rhs.base()); }

	template< class Iterator >
	typename ft::reverse_iterator<Iterator>::difference_type
	operator-( const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs )
	{ return (rhs.base() - lhs.base()); }

	template< class Iter >
	reverse_iterator<Iter>
	operator+( typename reverse_iterator<Iter>::difference_type n, const reverse_iterator<Iter>& it )
	{ return (&it[n]); }
}


	// template <class it>
	// class reverse_iterator {
	// public:
	// 	// -structors
	// 	reverse_iterator			(void)												{ _it = it(); }
	// 	reverse_iterator			(typename it::value_type * ptr)						{ _it = it(ptr); }
	// 	reverse_iterator			(const it & x)										{ _it = x; --_it; }
	// 	~reverse_iterator			(void)												{}
	// 	// Conversion
	// 	template <class U>			friend class										reverse_iterator;
	// 	template <class U>
	// 	reverse_iterator			(const reverse_iterator<U> & x)						{ _it = x.getIt(); }

	// 	// Assignment
	// 	reverse_iterator &			operator=	(const reverse_iterator & x)			{ _it = x.getIt(); return (*this); }
	// 	reverse_iterator &			operator+=	(int n)									{ _it -= n; return (*this); }
	// 	reverse_iterator &			operator-=	(int n)									{ _it += n; return (*this); }
	// 	// Comparison
	// 	template <class U> bool		operator==	(const reverse_iterator<U> & x) const	{ return (_it == x.getIt()); }
	// 	template <class U> bool		operator!=	(const reverse_iterator<U> & x) const	{ return (_it != x.getIt()); }
	// 	template <class U> bool		operator<	(const reverse_iterator<U> & x) const	{ return (_it > x.getIt()); }
	// 	template <class U> bool		operator>	(const reverse_iterator<U> & x) const	{ return (_it < x.getIt()); }
	// 	template <class U> bool		operator<=	(const reverse_iterator<U> & x) const	{ return (_it >= x.getIt()); }
	// 	template <class U> bool		operator>=	(const reverse_iterator<U> & x) const	{ return (_it <= x.getIt()); }
	// 	// -crementation
	// 	reverse_iterator &			operator++	(void)									{ --_it; return (*this); }
	// 	reverse_iterator &			operator--	(void)									{ ++_it; return (*this); }
	// 	reverse_iterator			operator++	(int)									{ reverse_iterator<it> x(*this); --_it; return (x); }
	// 	reverse_iterator			operator--	(int)									{ reverse_iterator<it> x(*this); ++_it; return (x); }
	// 	// Operation
	// 	reverse_iterator			operator+	(int n) const							{ return (_it - n + 1); }
	// 	reverse_iterator			operator-	(int n) const							{ return (_it + n + 1); }
	// 	std::ptrdiff_t				operator-	(const reverse_iterator & x) const		{ return (x.getIt() - _it); }
	// 	// Dereference
	// 	typename it::value_type &	operator[]	(size_t n) const						{ return (*(_it - n)); }
	// 	typename it::value_type &	operator*	(void) const							{ return (*_it); }
	// 	typename it::value_type *	operator->	(void) const							{ return (&(*_it)); }
	// 	// Member functions
	// 	it							base		(void)									{ return (++it(_it)); }
	// 	it							getIt		(void) const							{ return (_it); }
	// 	// Non-member functions
	// 	friend reverse_iterator		operator+	(int n, const reverse_iterator & x)		{ return (x.getIt() - n + 1); }

	// private:
	// 	it		_it;
	// };


#endif
