/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 11:32:04 by fmonbeig          #+#    #+#             */
/*   Updated: 2022/06/10 14:23:25 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
#define PAIR_HPP

namespace ft
{
	template<class T1, class T2>
	struct pair
	{
		typedef T1 first_type;
		typedef T2 second_type;

		T1	first;
		T2	second;

		pair() : first(), second() {}

		pair( const T1& x, const T2& y ) :
			first(x), second(y) {}

		template< class U1, class U2 >
		pair( const pair<U1, U2>& p ):
			first(p.first), second(p.second) {}

		~pair(){}

		pair& operator=( const pair& other )
		{
			if (this != &other)
			{
				first = other.first;
				second = other.second;
			}
			return *this;
		}
	};

	template<class T1, class T2>
	bool operator==(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return (lhs.first == rhs.first && lhs.second == rhs.second); }

	template<class T1, class T2>
	bool operator<(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return (lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second)); }

	template<class T1, class T2>
	bool operator!=( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs )
	{ return (!(lhs == rhs)); }

	template<class T1, class T2>
	bool operator<=( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs )
	{
		if (lhs == rhs)
			return true;
		return (lhs < rhs);
	}

	template<class T1, class T2>
	bool operator>( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs )
	{
		if (lhs == rhs)
			return false;
		return (!(lhs < rhs));
	}

	template<class T1, class T2>
	bool operator>=( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs )
	{
		if (lhs == rhs)
			return true;
		return (!(lhs < rhs));
	}

	template< class T1, class T2 >
	pair<T1,T2> make_pair( T1 t, T2 u )
	{ return pair<T1, T2>(t, u); }
}

#endif
