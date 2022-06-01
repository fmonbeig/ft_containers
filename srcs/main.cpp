/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 11:37:09 by fmonbeig          #+#    #+#             */
/*   Updated: 2022/06/01 18:06:36 by fmonbeig         ###   ########.fr       */
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
	// std::map<std::string, int> real;

	// std::pair<std::string, int> add("bonjour", 42);
	// std::pair<std::string, int> add2("bonjour", 99);

	// real.insert(add2);
	// real.insert(add);
	// real.insert(add);
	// real.insert(add);

	// std::map<std::string, int>::iterator it = real.find("bofnjour");
	// std::cout << it->second << std::endl;

	ft::map<int, int> mine;

	ft::pair<int, int> add(100, 42);
	ft::pair<int, int> add2(50, 42);
	ft::pair<int, int> add3(10, 42);
	ft::pair<int, int> add4(2, 42);
	ft::pair<int, int> add5(6, 42);
	ft::pair<int, int> add6(7, 42);

	mine.insert(add);
	mine.insert(add2);
	mine.insert(add3);
	mine.insert(add4);
	mine.insert(add5);
	mine.insert(add6);

	mine.print_tree();


	// mine.rootKey();


	// mine::value_compare::operator(add, add2);

	// int x = 10;
	// int y = 1000;
	// std::less<int> test;

	// std::cout << test(x, y);;

}
