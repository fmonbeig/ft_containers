/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 11:37:09 by fmonbeig          #+#    #+#             */
/*   Updated: 2022/05/31 16:32:11 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "vector.hpp"
#include "stack.hpp"
#include "map.hpp"
#include "avl_tree.hpp"

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

	ft::map<std::string, int> mine;

	ft::pair<std::string, int> add("bonjour", 42);

	mine.insert(add);
	ft::pair<const std::string, int> *test = mine.rootKey();

	std::cout << test->first << std::endl;


}

