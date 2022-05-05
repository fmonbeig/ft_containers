/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 16:47:54 by fmonbeig          #+#    #+#             */
/*   Updated: 2022/05/05 17:21:58 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPARE_HPP
#define COMPARE_HPP

#include <iostream>

namespace ft
{

template< class InputIt1, class InputIt2 >
bool equal(InputIt1 first1, InputIt1 last1, InputIt2 first2 )
{
	int dist = std::distance(first1, last1);
	int dist2 = std::distance(first2, first2 + (last1 - first1));

	if (dist == dist2)
		return true;
	else
		return false;
}

// 1,3) Returns true if the range [first1, last1) is equal to the range [first2, first2 + (last1 - first1)), and false otherwise



template< class InputIt1, class InputIt2, class BinaryPredicate >
bool equal( InputIt1 first1, InputIt1 last1, InputIt2 first2, BinaryPredicate p );

//std::lexicographical_compare
}

#endif
