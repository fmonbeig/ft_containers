/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 11:37:09 by fmonbeig          #+#    #+#             */
/*   Updated: 2022/06/06 16:46:16 by fmonbeig         ###   ########.fr       */
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

int main()
{
	// std::map<int, int> real;
	// std::pair<int, int> add(100, 42);
	// std::pair<int, int> add2(50, 42);
	// std::pair<int, int> add3(4, 42);
	// std::pair<int, int> add4(2, 42);
	// std::pair<int, int> add5(999, 42);
	// std::pair<int, int> add6(7, 42);

	// real.insert(add);
	// real.insert(add2);
	// real.insert(add3);
	// real.insert(add4);
	// real.insert(add5);
	// real.insert(add6);

	// std::map<int, int>::iterator it = real.begin();
	// std::cout << it->first << std::endl;


	// int i = 0;

	// for (std::map<int, int>::iterator it = real.begin(); i < 1; ++it)
	// {
	// 	std::cout << it->first << std::endl;
	// 	i++;
	// }

	// std::cout << real.empty() << std::endl;


	// for (std::map<int, int>::iterator it = real.begin();it != real.end();++it)
	// 	std::cout << it->first << std::endl;
	// std::cout << real.at(4)<< std::endl;
	//Returns a reference to the mapped value of the element with key equivalent to key
	// Ici 99 car std::pair<int, int> add4(4, 99);
	// std::cout << real[400]<< std::endl;
	//Returns a reference to the value that is mapped to a key equivalent to key,
	//performing an insertion if such key does not already exist.

	ft::map<int, int> mine;
	ft::pair<int, int> add(100, 42);
	ft::pair<int, int> add2(50, 42);
	ft::pair<int, int> add3(4, 42);
	ft::pair<int, int> add4(2, 42);
	ft::pair<int, int> add5(999, 42);
	ft::pair<int, int> add6(7, 42);
	ft::pair<int, int> add7(12, 42);
	ft::pair<int, int> add8(-56, 42);
	ft::pair<int, int> add9(1, 42);

	mine.insert(add);
	mine.insert(add2);
	mine.insert(add3);
	mine.insert(add4);
	mine.insert(add5);
	mine.insert(add6);
	mine.insert(add7);
	mine.insert(add8);
	mine.insert(add9);


	ft::map<int, int>::iterator it = mine.begin();
	it++;
	it++;
	it++;
	it++;
	it++;
	it++;

	std::cout << " ERASE OF " << it->first << std::endl;

	mine.erase(it);
	// it++;
	// // mine.erase(it);
	// int i = 0;

	// for (ft::map<int, int>::iterator it = mine.begin(); i < 10; ++it)
	// {
	// 	std::cout << it->first << std::endl;
	// 	i++;
	// }
	// for (ft::map<int, int>::iterator it = mine.end(); it != mine.begin();)
	// {
	// 	--it;
	// 	std::cout << it->first << std::endl;
	// }
		std::cout << "===========" << std::endl;
	for (ft::map<int, int>::iterator it = mine.begin(); it != mine.end(); it++)
	{
		std::cout << it->first << std::endl;
	}

	// FIXME : mettre le dad a jour lors de rotation
	// ft::map<int, int>::iterator it = mine.end();
	// it--;
	// it--;
	// it--;
	// 	std::cout << it->first << std::endl;


	// mine.print_tree();


	// mine.rootKey();


	// mine::value_compare::operator(add, add2);

	// int x = 10;
	// int y = 1000;
	// std::less<int> test;

	// std::cout << test(x, y);;

}
