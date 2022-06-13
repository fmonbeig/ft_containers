/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 11:37:09 by fmonbeig          #+#    #+#             */
/*   Updated: 2022/06/13 18:10:12 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <functional>
#include "vector.hpp"
#include "stack.hpp"
#include "map.hpp"
#include <cstdio>
#include <iomanip>
#include <list>

/* PRACTICE ZONE */

int main()
{
	// +------------------------------------------+ //
	//   STD								        //
	// +------------------------------------------+ //
	ft::map<int, int> real;
	ft::pair<int, int> add(100, 42);
	ft::pair<int, int> add2(50, 42);
	ft::pair<int, int> add3(4, 42);
	ft::pair<int, int> add4(2, 42);
	ft::pair<int, int> add5(999, 48);
	ft::pair<int, int> add6(7, 42);

	real.insert(add);
	real.insert(add);
	real.insert(add);
	real.insert(add);
	real.insert(add);
	real.insert(add);
	real.insert(add2);
	real.insert(add3);
	real.insert(add4);
	real.insert(add5);
	real.insert(add6);
	real.insert(ft::make_pair(20,30));

	for (ft::map<int, int>::iterator it = real.begin(); it != real.end(); it++)
	{
		std::cout << it->first << std::endl;
	}


	// std::cout << real.find(20)->first << std::endl;



// 			+------------------------------------------+ //
// 			  FT								         //
// 			+------------------------------------------+ //

	// ft::map<int, int> mine;

	// mine[100] = 42;
	// mine[50] = 43;
	// mine[4] = 44;
	// mine[2] = 45;
	// mine[999] = 46;

	// ft::map<int, int> mine2;
	// mine[6] = 47;
	// mine[7] = 48;
	// mine[10] = 49;

	// ft::map<int, int>::iterator it = mine.begin();
	// ft::map<int, int>::iterator ite = mine.end();

	// mine.swap(mine2);

	// for (; it != ite; ++it)
	// 	std::cout << it->first << std::endl;



	// for (ft::map<int, int>::iterator it = mine.begin(); it != mine.end(); it++)
	// {
	// 	std::cout << it->first << std::endl;
	// }
}
