/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 11:37:09 by fmonbeig          #+#    #+#             */
/*   Updated: 2022/05/15 19:21:34 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "vector.hpp"

int main()
{
	std::vector<int>	real;
	ft::vector<int>		mine;

	real.push_back(44);
	real.push_back(-34);
	real.push_back(112);

	std::cout << "REAL -- BEGIN" << std::endl;
	std::cout << *real.begin() << std::endl;
	std::cout << "REAL -- ALL VECTOR" << std::endl;
	for(std::vector<int>::const_iterator it = real.begin(); it != real.end(); it++ )
		std::cout << *it << std::endl;

	mine.push_back(44);
	mine.push_back(-34);
	mine.push_back(112);

	std::cout << "mine -- BEGIN" << std::endl;
	std::cout << *mine.begin() << std::endl;
	std::cout << "mine -- ALL VECTOR" << std::endl;
	for(ft::vector<int>::const_iterator it = mine.begin(); it != mine.end(); it++)
	{
		std::cout << *it << std::endl;
	}

}
