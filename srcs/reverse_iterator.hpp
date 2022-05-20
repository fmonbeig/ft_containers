/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 10:57:09 by fmonbeig          #+#    #+#             */
/*   Updated: 2022/05/20 15:29:48 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR
#define REVERSE_ITERATOR

#include "utils.hpp"

namespace ft
{
	template< class Iter >
	class reverse_iterator
	{
		public:
			typedef				Iter											iterator_type;
			typedef typename	std::random_access_iterator_tag					iterator_category;
			typedef typename	iterator_traits<Iter>::difference_type			difference_type;
			typedef typename	iterator_traits<Iter>::value_type				value_type; //T
			typedef typename	iterator_traits<Iter>::pointer					pointer;    //T* ou const T* ...
			typedef typename	iterator_traits<Iter>::reference				reference;

			// +------------------------------------------+ //
			//   CONSTRUCT...					            //
			// +------------------------------------------+ //
			reverse_iterator(): _it() {}
			explicit reverse_iterator( iterator_type x ) { _it = x; }
			reverse_iterator( reverse_iterator const & other ) { _it = other._it; };
			template <class U>
			reverse_iterator( const reverse_iterator<U>& other ) { _it = other.base(); };

			reverse_iterator & operator=(reverse_iterator const & rhs) { _it = rhs._it; return (*this);}
			reverse_iterator & operator+=( difference_type n ) { _it -=n; return (*this); }
			reverse_iterator & operator-=( difference_type n ) { _it +=n; return (*this); }

			// +------------------------------------------+ //
			//   ACCESS							            //
			// +------------------------------------------+ //

			/* Acces to the element before we are currently pointing with operator ' * '*/

			reference operator*()
			{
				Iter temp = _it;
				--temp;
				return *temp;
			}

			/* Acces to the element before we are currently pointing with operator ' -> ' */

			pointer operator->() const { return (&(operator*())); }

			/* Acces to the element with operator ' [] ' using operator ' * ' */

			reference operator[](difference_type n) const
			{  return *(*this + n); }

			iterator_type base() const { return _it; }

			// +------------------------------------------+ //
			//   OPERATOR							        //
			// +------------------------------------------+ //

			reverse_iterator& operator++() { _it--; return *this; }
			reverse_iterator& operator--() { _it++; return *this; }
			reverse_iterator operator++(int) { reverse_iterator temp = *this; _it--; return (temp); }
			reverse_iterator operator--(int) { reverse_iterator temp = *this; _it++; return (temp); }

			reverse_iterator operator+( difference_type n ) const
			{ return reverse_iterator(_it - n); }
			reverse_iterator operator-( difference_type n ) const
			{ return reverse_iterator(_it + n); }

			difference_type operator+(const reverse_iterator & x)  { return (this->base() + x.base()); }
			difference_type operator-(const reverse_iterator & x)  { return (this->base() - x.base()); }

			protected:
				iterator_type	_it;
				typedef iterator_traits<Iter> traits_type;
	};

	// +------------------------------------------+ //
	//   OPERATOR NON MEMBER				        //
	// +------------------------------------------+ //

	// no const vs no const && const vs const

	template <class _Iterator>
	bool operator==(const reverse_iterator<_Iterator>& lhs, const reverse_iterator<_Iterator>& rhs)
	{ return (lhs.base() == rhs.base()); }

	template <class _Iterator>
	bool operator<(const reverse_iterator<_Iterator>& lhs, const reverse_iterator<_Iterator>& rhs)
	{ return (rhs.base() < lhs.base()); }

	template <class _Iterator>
	bool operator!=(const reverse_iterator<_Iterator>& lhs, const reverse_iterator<_Iterator>& rhs)
	{ return (!(lhs == rhs)); }

	template <class _Iterator>
	bool operator<=(const reverse_iterator<_Iterator>& lhs, const reverse_iterator<_Iterator>& rhs)
	{ return !(rhs < lhs); }

	template <class _Iterator>
	bool operator>(const reverse_iterator<_Iterator>& lhs, const reverse_iterator<_Iterator>& rhs)
	{  return rhs < lhs; }

	template <class _Iterator>
	bool operator>=(const reverse_iterator<_Iterator>& lhs, const reverse_iterator<_Iterator>& rhs)
	{ return !(lhs < rhs); }

	// no const vs const

	template <class _IteratorL, class _IteratorR>
	bool operator==(const reverse_iterator<_IteratorL>& lhs, const reverse_iterator<_IteratorR>& rhs)
	{ return (lhs.base() == rhs.base()); }

	template <class _IteratorL, class _IteratorR>
	bool operator<(const reverse_iterator<_IteratorL>& lhs, const reverse_iterator<_IteratorR>& rhs)
	{ return (rhs.base() < lhs.base()); }

	template <class _IteratorL, class _IteratorR>
	bool operator!=(const reverse_iterator<_IteratorL>& lhs, const reverse_iterator<_IteratorR>& rhs)
	{ return (!(lhs == rhs)); }

	template <class _IteratorL, class _IteratorR>
	bool operator<=(const reverse_iterator<_IteratorL>& lhs, const reverse_iterator<_IteratorR>& rhs)
	{ return !(rhs < lhs); }

	template <class _IteratorL, class _IteratorR>
	bool operator>(const reverse_iterator<_IteratorL>& lhs, const reverse_iterator<_IteratorR>& rhs)
	{ return rhs < lhs; }

	template <class _IteratorL, class _IteratorR>
	bool operator>=(const reverse_iterator<_IteratorL>& lhs, const reverse_iterator<_IteratorR>& rhs)
	{ return !(lhs < rhs); }


	template< class Iter >
	reverse_iterator<Iter>
	operator+( typename reverse_iterator<Iter>::difference_type n, const reverse_iterator<Iter>& it )
	{ return reverse_iterator<Iter>(it.base() - n); }

	template< class Iter >
	reverse_iterator<Iter>
	operator-( typename reverse_iterator<Iter>::difference_type n, const reverse_iterator<Iter>& it )
	{ return reverse_iterator<Iter>(it.base() + n); }
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
