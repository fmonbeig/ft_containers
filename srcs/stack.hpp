// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   stack.hpp                                          :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2022/05/05 14:37:21 by fmonbeig          #+#    #+#             */
// /*   Updated: 2022/05/06 16:33:10 by fmonbeig         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#ifndef STACK_HPP
#define STACK_HPP

#include <vector>
#include "utility.hpp"

namespace ft
{
	template< class T, class Container = std::vector<T> > //FIXME a changer avec mon vector
	class stack
	{
		private:
		// +------------------------------------------+ //
		//   MEMBER OBJECT						        //
		// +------------------------------------------+ //
			Container c;

		public:
		// +------------------------------------------+ //
		//   MEMBER TYPE						        //
		// +------------------------------------------+ //
			typedef			 Container					container_type;
			typedef typename Container::value_type		value_type;
			typedef typename Container::size_type		size_type;
			typedef typename Container::reference		reference;
			typedef typename Container::const_reference	const_reference;

		// +------------------------------------------+ //
		//   CONSTRUCT / DESTRUCT / COPY				//
		// +------------------------------------------+ //

			explicit stack( const Container& cont = Container() )
			{ c = cont; }

			virtual ~stack(){}

			stack(stack const & other): c(other.c)
			{}

			stack & operator=(stack & rhs)
			{
				if (this != &rhs)
					c = rhs.c;
				return *this;
			}
		// +------------------------------------------+ //
		//   FRIEND								        //
		// +------------------------------------------+ //

			friend bool operator==(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
			{ return (lhs.c == rhs.c); }

			friend bool operator<(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
			{ return (lhs.c < rhs.c); }
		// +------------------------------------------+ //
		//   ELEMENT ACCESS						        //
		// +------------------------------------------+ //

			value_type & top()
			{ return (c.back()); }

		// +------------------------------------------+ //
		//   CAPACITY							        //
		// +------------------------------------------+ //

			bool empty() const
			{ return (c.empty()); }

			size_type size() const
			{ return (c.size()); }

		// +------------------------------------------+ //
		//   MODIFIERS							        //
		// +------------------------------------------+ //

			void push( value_type const & value )
			{ c.push_back(value); }

			void pop()
			{ c.pop_back(); }
	};

	// +------------------------------------------+ //
	//   OPERATOR							        //
	// +------------------------------------------+ //

	template< class T, class Container >
	bool operator!=( const stack<T,Container>& lhs, const stack<T,Container>& rhs )
	{ return (!(lhs == rhs)); }

	template< class T, class Container >
	bool operator<=( const stack<T,Container>& lhs, const stack<T,Container>& rhs )
	{
		if (lhs == rhs)
			return true;
		return (lhs < rhs);
	}

	template< class T, class Container >
	bool operator>( const stack<T,Container>& lhs, const stack<T,Container>& rhs )
	{
		if (lhs == rhs)
			return false;
		return (!(lhs < rhs));
	}

	template< class T, class Container >
	bool operator>=( const stack<T,Container>& lhs, const stack<T,Container>& rhs )
	{
		if (lhs == rhs)
			return true;
		return (!(lhs < rhs));
	}
}

#endif
