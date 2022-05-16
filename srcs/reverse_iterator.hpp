/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 10:57:09 by fmonbeig          #+#    #+#             */
/*   Updated: 2022/05/16 17:13:20 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR
#define REVERSE_ITERATOR

namespace ft
{
	template< class Iter >
	class reverse_iterator
	{
		public:
			typedef				Iter											iterator_type;
			typedef typename	std::random_access_iterator_tag					iterator_category;
			typedef 			long int										difference_type;
			typedef typename	Iter::value_type								value_type; //T
			typedef typename	Iter::pointer									pointer;    //T*
			typedef typename	Iter::reference									reference;  // T&
			// typedef typename	Iter::const_pointer								const_pointer;    //T*
			// typedef typename	Iter::const_reference							const_reference;  // T&

			// +------------------------------------------+ //
			//   CONSTRUCT...					            //
			// +------------------------------------------+ //
			reverse_iterator(){ _it = Iter(); }
			explicit reverse_iterator( iterator_type x ) { _it = Iter(x); }

			template <class U>
			reverse_iterator( const reverse_iterator<U>& other ) { _it = other.base(); };
			reverse_iterator( reverse_iterator const & other ) { _it = other.base(); };

			reverse_iterator & operator=(reverse_iterator const & rhs) { _it = rhs._it; return (*this);}
			reverse_iterator & operator+=( difference_type n ) { _it -=n; return (*this); }
			reverse_iterator & operator-=( difference_type n ) { _it +=n; return (*this); }

			// +------------------------------------------+ //
			//   ACCESS							            //
			// +------------------------------------------+ //

			// operator reverse_iterator<Iter const>() const
			// {	return (reverse_iterator<Iter const>(_it)); };

			reference operator*() { return *_it; }
			// const_reference operator*() const { return *_it; }
			pointer operator->() const { return _it; }
			reference operator[](difference_type n) const
			{
				// reverse_iterator temp_it = _it;

				// temp_it -= n;
				// return (*(temp_it));
				return (this->base()[-n - 1]);
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
			reverse_iterator operator++(int) { _it--; return (reverse_iterator(_it - 1)); }
			reverse_iterator operator--(int) { _it++; return (reverse_iterator(_it + 1)); }

			reverse_iterator operator+( difference_type n ) const
			{
				reverse_iterator temp(*this);
				return (temp -= n);
			}
			reverse_iterator operator-( difference_type n ) const
			{
				reverse_iterator temp(*this);
				return (temp += n);
			}

			difference_type operator+(const reverse_iterator & x)  { return (_it - x._it); }
			difference_type operator-(const reverse_iterator & x)  { return (_it + x._it); }

			protected:
				iterator_type	_it;
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
