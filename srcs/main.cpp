/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 11:37:09 by fmonbeig          #+#    #+#             */
/*   Updated: 2022/05/10 15:32:32 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "vector.hpp"
#include <vector>

int main()
{
	std::vector<int>	real;
	ft::vector<int>		mine;

	real.push_back(44);
	real.push_back(-34);

	mine.push_back(44);
	mine.push_back(-34);

	std::cout << "REAL : " << real[0] << std::endl << "MINE : " << mine[0] << std::endl;

}
