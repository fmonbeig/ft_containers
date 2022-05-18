/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 11:37:09 by fmonbeig          #+#    #+#             */
/*   Updated: 2022/05/18 16:04:18 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "vector.hpp"


int main()
{
	std::vector<int>	real;

	real.push_back(44);
	real.push_back(-34);
	real.push_back(112);
	real.push_back(550);
	real.push_back(610);

	std::cout << "REAL -- ERASE IT" << std::endl;

	std::vector<int>::const_iterator it3 = real.erase(real.begin() + 1, real.begin() + 3);
	std::cout << *it3 << std::endl;

	std::ptrdiff_t count = (real.begin() + 3) - (real.begin() + 1);

	std::cout << count << std::endl;

	std::cout << "LIST REAL" << std::endl;

	for(std::vector<int>::const_iterator it = real.begin(); it != real.end(); it++ )
		std::cout << *it << std::endl;

	ft::vector<int>		mine;

	mine.push_back(44);
	mine.push_back(-34);
	mine.push_back(112);
	mine.push_back(550);
	mine.push_back(610);

	std::cout << "MINE -- ERASE IT" << std::endl;

	ft::vector<int>::const_iterator it2 = mine.erase(mine.begin() + 1, mine.begin() + 3);
	std::cout << *it2 << std::endl;

	std::cout << "LIST" << std::endl;

	for(ft::vector<int>::const_iterator it = mine.begin(); it != mine.end(); it++ )
		std::cout << *it << std::endl;

}


// int main()
// {
// 	std::vector<int>	real;
// 	ft::vector<int>		mine;

// 	real.push_back(44);
// 	real.push_back(-34);
// 	real.push_back(112);

// 	// std::cout << "REAL -- BEGIN" << std::endl;
// 	// std::cout << *real.begin() << std::endl;
// 	// std::cout << "REAL -- ALL VECTOR" << std::endl;
// 	// for(std::vector<int>::const_iterator it = real.begin(); it != real.end(); it++ )
// 	// 	std::cout << *it << std::endl;

// 	// std::cout << "REAL -- Reverse IT" << std::endl;

// 	// for(std::vector<int>::reverse_iterator it = real.rbegin(); it != real.rend(); it++ )
// 	// 	std::cout << *it << std::endl;

// 	std::cout << "REAL -- CONST Reverse IT" << std::endl;
// 	std::vector<int>::const_reverse_iterator it2 = real.rbegin();
// 	std::cout << *it2 << std::endl;



// 	mine.push_back(44);
// 	mine.push_back(-34);
// 	mine.push_back(112);

// 	// std::cout << "mine -- BEGIN" << std::endl;
// 	// std::cout << *mine.begin() << std::endl;
// 	// std::cout << "mine -- ALL VECTOR" << std::endl;

// 	// for(ft::vector<int>::const_iterator it = mine.begin(); it != mine.end(); it++)
// 	// {
// 	// 	std::cout << *it << std::endl;
// 	// }

// 	// std::cout << "Mine -- Reverse IT" << std::endl;

// 	// for(ft::vector<int>::reverse_iterator it = mine.rbegin(); it != mine.rend(); it++ )
// 	// 	std::cout << *it << std::endl;

// 	std::cout << "REAL -- CONST Reverse IT" << std::endl;
// 	ft::vector<int>::const_reverse_iterator it = mine.rbegin();

// 	std::cout << *it << std::endl;
// }
