/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 11:37:09 by fmonbeig          #+#    #+#             */
/*   Updated: 2022/05/19 14:56:05 by fmonbeig         ###   ########.fr       */
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

	std::vector<int>::reverse_iterator it_real;

	std::cout << "-----REAL-----"<< std::endl << std::endl;;
	it_real = real.rbegin();
	std::cout << "BEGIN = "<< *it_real << std::endl;
	it_real = real.rend();
	std::cout << "END = "<< *it_real << std::endl;

	std::cout << "LIST " << std::endl;
	for(std::vector<int>::reverse_iterator it = real.rbegin(); it != real.rend(); it++ )
		std::cout << *it << std::endl;

	ft::vector<int>		mine;
	mine.push_back(44);
	mine.push_back(-34);
	mine.push_back(112);


	ft::vector<int>::const_reverse_iterator  it_mine;

	std::cout << "-----MINE-----"<< std::endl << std::endl;;
	it_mine = mine.rbegin();
	std::cout << "BEGIN = "<< *it_mine << std::endl;
	it_mine = mine.rend();
	std::cout << "END = "<< *it_mine << std::endl;

	std::cout << "LIST " << std::endl;
	for(ft::vector<int>::const_reverse_iterator it = mine.rbegin(); it != mine.rend(); it++ )
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
