/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 11:37:09 by fmonbeig          #+#    #+#             */
/*   Updated: 2022/06/08 15:11:53 by fmonbeig         ###   ########.fr       */
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
			// +------------------------------------------+ //
			//   REAL								        //
			// +------------------------------------------+ //
	// std::map<int, int> real;
	// std::pair<int, int> add(100, 42);
	// std::pair<int, int> add2(50, 42);
	// std::pair<int, int> add3(4, 42);
	// std::pair<int, int> add4(2, 42);
	// std::pair<int, int> add5(999, 48);
	// std::pair<int, int> add6(7, 42);

	// std::pair<int, int> addx(101, 44);
	// std::pair<int, int> addy(102, 49);
	// std::pair<int, int> addz(103, 50);


	// std::map<int, int>::const_iterator ite = real.end();

	// real.insert(add);
	// real.insert(add2);
	// real.insert(add3);
	// real.insert(add4);
	// real.insert(add5);
	// real.insert(add6);

	// std::map<int, int>::const_iterator it = real.begin();


	// for (;it != ite;++it)
	// std::cout << it->first << "  " << it->second << std::endl;

	// std::cout << real.size() << std::endl;
	// real.erase(real.begin(), real.end());


	// std::cout << real[1000] << std::endl;

	// std::map<int, int> real2;
	// real2.insert(addx);
	// real2.insert(addy);
	// real2.insert(addz);

	// real.clear();

	// std::cout << real.size() << std::endl;


	// std::map<int, int>::iterator it = real.begin();
	// std::cout << it->first << std::endl;

	// real.insert(real2.begin(), real2.end());

	// std::map<int, int>::iterator it = real.begin();
	// std::cout << it->first << std::endl;

	// std::map<int, int>::iterator it = real.begin();

	// std::cout << it->first << std::endl;
	// int i = 0;

	// for (const std::map<int, int>::iterator it = real.begin(); i < 1; ++it)
	// {
	// 	std::cout << it->first << std::endl;
	// 	i++;
	// }

	// std::cout << real.empty() << std::endl;


	// for (std::map<int, int>::const_iterator it = real.begin();it != real.end();++it)
	// 	std::cout << it->first << "  " << it->second << std::endl;
	// std::cout << real.at(4)<< std::endl;
	//Returns a reference to the mapped value of the element with key equivalent to key
	// Ici 99 car std::pair<int, int> add4(4, 99);
	// std::cout << real[400]<< std::endl;
	//Returns a reference to the value that is mapped to a key equivalent to key,
	//performing an insertion if such key does not already exist.

			// +------------------------------------------+ //
			//   MINE								        //
			// +------------------------------------------+ //

	ft::map<int, int> mine;
	ft::pair<int, int> add(100, 42);
	ft::pair<int, int> add2(50, 42);
	ft::pair<int, int> add3(4, 42);
	ft::pair<int, int> add4(2, 42);
	ft::pair<int, int> add5(999, 48);
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

	ft::map<int, int>::iterator it = mine.upper_bound(999);

	std::cout << it->first << std::endl;

	it = mine.lower_bound(-56);
	std::cout << it->first << std::endl;

	// ft::map<int, int> mine2(mine);

	// if (mine == mine2 )
	// 	std::cout << 1 << std::endl;
	// ft::pair<int, int> addx(101, 44);
	// ft::pair<int, int> addy(102, 49);
	// ft::pair<int, int> addz(103, 50);

	// ft::map<int, int> mine2;
	// mine2.insert(addx);
	// mine2.insert(addy);
	// mine2.insert(addz);


	// mine.erase(mine.begin(), mine.end());

	// std::cout <<mine.count(99) << std::endl;
	// std::cout << "SIZE " <<mine.size() << std::endl;
	// mine.insert(mine2.begin(), mine2.end());

	// ft::map<int, int>::iterator it = mine.begin();
	// it++;
	// it++;
	// it++;
	// it++;
	// it++;
	// it++;

	// std::cout << " ERASE OF " << it->first << std::endl;

	// mine.erase(it);
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
	// 	std::cout << "===========" << std::endl;

	// mine.clear();
	// std::cout << "SIZE " <<mine.size() << std::endl;

	// ft::map<int, int>::iterator it = mine.find(17);

	// std::cout << it->first << std::endl;
	// try
	// {
	// std::cout << mine.at(17) << std::endl;

	// }
	// catch (const std::exception&e)
	// {
	// 	std::cerr << e.what() << std::endl;
	// }

	// for (ft::map<int, int>::iterator it = mine.begin(); it != mine.end(); it++)
	// {
	// 	std::cout << it->first << std::endl;
	// }

	// for (ft::map<int, int>::const_reverse_iterator it = mine.rbegin(); it != mine.rend(); it++)
	// {
	// 	std::cout << it->first << std::endl;
	// }

	// mine.print_tree();


	// mine.rootKey();


	// mine::value_compare::operator(add, add2);

	// int x = 10;
	// int y = 1000;
	// std::less<int> test;

	// std::cout << test(x, y);;

}
