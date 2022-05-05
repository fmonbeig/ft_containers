/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 14:37:21 by fmonbeig          #+#    #+#             */
/*   Updated: 2022/05/05 17:58:31 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>
#include <memory>
#include <vector>

namespace ft
{

	template< class T, class Container = std::vector<T>> //FIXME a changer avec mon vector
	class stack
	{
		public:
		// +------------------------------------------+ //
		//   MEMBER OBJECT						        //
		// +------------------------------------------+ //

			Container C;

		// +------------------------------------------+ //
		//   MEMBER TYPE						        //
		// +------------------------------------------+ //
			typedef			 Container					container_type;
			typedef typename Container::value_type		value_type;
			typedef typename Container::size_type		size_type;
			typedef typename Container::reference		reference;
			typedef typename Container::const_reference	const_reference;

		// +------------------------------------------+ //
		//   MEMBER FUNCTION					        //
		// +------------------------------------------+ //

			stack(){}
			virtual ~stack(){}

			stack(stack const & other): C(other.C)
			{}

			stack & operator=(stack & rhs)
			{
				if (this != &rhs)
				{
					// destroy container c ??
					C = rhs.C;
				}
				return *this;
			}
		// +------------------------------------------+ //
		//   ELEMENT ACCESS						        //
		// +------------------------------------------+ //

		value_type & top()
		{ return (C.back()); }

		// +------------------------------------------+ //
		//   CAPACITY							        //
		// +------------------------------------------+ //

		bool empty() const
		{ return (C.empty()); }

		size_type size() const
		{ return (C.size()); }

		// +------------------------------------------+ //
		//   MODIFIERS							        //
		// +------------------------------------------+ //

		void push( value_type const & value )
		{ C.push_back(value); }

		void pop()
		{ C.pop_back(); }


	};
}

    operator==(const array<_Tp, _Nm>& __one, const array<_Tp, _Nm>& __two)
    { return std::equal(__one.begin(), __one.end(), __two.begin()); }

  template<typename _Tp, std::size_t _Nm>
    _GLIBCXX20_CONSTEXPR
    inline bool
    operator==(const array<_Tp, _Nm>& __one, const array<_Tp, _Nm>& __two)
    { return std::equal(__one.begin(), __one.end(), __two.begin()); }


template< class T, class Alloc >
bool operator==( const ft::stack<T,Alloc>& lhs,
                 const ft::stack<T,Alloc>& rhs );
 { return ft::equal(lhs.begin(), lhs.end(), rhs.begin()); }



/*
operator==
operator!=
operator<
operator<=
operator>
operator>=

*/

#endif
