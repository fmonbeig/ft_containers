/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 14:25:48 by fmonbeig          #+#    #+#             */
/*   Updated: 2022/05/20 14:31:15 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
#define UTILS_HPP

#include <cstddef>

namespace ft
{
		// +------------------------------------------+ //
		//   ITERATOR TRAITS						    //
		// +------------------------------------------+ //
		/*******
		 * Think of a trait as a small object whose main purpose is
		 * to carry information used by another object or algorithm
		 * to determine "policy" or "implementation details".*/

	struct random_access_iterator_tag {};
	template< class Iter >
	struct iterator_traits
	{
		typedef typename Iter::difference_type		difference_type;
		typedef typename Iter::value_type			value_type;
		typedef typename Iter::pointer				pointer;
		typedef typename Iter::reference			reference;
		typedef typename Iter::iterator_category 	iterator_category;
	};

	template< class T >
	struct iterator_traits<T*>
	{
		typedef typename	std::ptrdiff_t					difference_type;
		typedef				T								value_type;
		typedef				T*								pointer;
		typedef				T&								reference;
		typedef typename	std::random_access_iterator_tag	iterator_category;
	};

	template< class T >
	struct iterator_traits<const T*>
	{
		typedef typename	std::ptrdiff_t					difference_type;
		typedef				T								value_type;
		typedef				const T*						pointer;
		typedef				const T&						reference;
		typedef typename	std::random_access_iterator_tag	iterator_category;
	};

		// +------------------------------------------+ //
		//   ENABLE IF								    //
		// +------------------------------------------+ //
	template<bool B, class T = void>
	struct enable_if {};

	template<class T>
	struct enable_if<true, T> { typedef T type; };



		// +------------------------------------------+ //
		//   IS INTEGRAL							    //
		// +------------------------------------------+ //

	template< class T >
	struct is_integral { static const bool value = false; };

	template<>
	struct is_integral<float> { static const bool value = false; };

	template<>
	struct is_integral<bool> { static const bool value = true; };

	template<>
	struct is_integral<int> { static const bool value = true; };

	template<>
	struct is_integral<short> { static const bool value = true; };

	template<>
	struct is_integral<unsigned int> { static const bool value = true; };

	template<>
	struct is_integral<unsigned short> { static const bool value = true; };

	// template<>
	// struct is_integral<size_t> { static const bool value = true; };

	template<>
	struct is_integral<char> { static const bool value = true; };

	template<>
	struct is_integral<unsigned char> { static const bool value = true; };

	template<>
	struct is_integral<long int> { static const bool value = true; };

	template<>
	struct is_integral<long long int> { static const bool value = true; };

		// +------------------------------------------+ //
		//   LEXICOGRAPHICAL COMPARE				    //
		// +------------------------------------------+ //

    template <class InputIterator1, class InputIterator2>
	bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
									InputIterator2 first2, InputIterator2 last2)
	{
		while (first1 != last1)
		{
			if (first2 == last2 || *first2 < *first1)
				return false;
			else if (*first1 < *first2)
				return true;
			++first1;
			++first2;
		}
		return (first2 != last2);
	}

		// +------------------------------------------+ //
		//   EQUAL									    //
		// +------------------------------------------+ //

	template <class InputIterator1, class InputIterator2>
	bool equal ( InputIterator1 first1, InputIterator1 last1, InputIterator2 first2 )
	{
		while (first1 != last1)
		{
			if (!(*first1 == *first2))
				return false;
			++first1;
			++first2;
		}
		return true;
	}

	template <typename InputIterator1, typename InputIterator2, typename BinaryPredicate>
	bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate pred)
	{
		while (first1 != last1)
		{
			if (!pred(*first1, *first2))
				return (false);
			first1++;
			first2++;
		}
		return (true);
	}

}

#endif
