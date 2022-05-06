/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 11:37:09 by fmonbeig          #+#    #+#             */
/*   Updated: 2022/05/06 17:25:34 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "stack.hpp"
#include <stack>

int main()
{
	std::stack<int>	real;
	ft::stack<int>	mine;

	ft::stack<int>	mine2;

	real.push(44);
	real.push(-34);

	mine.push(44);
	mine.push(-34);

	mine2.push(44);
	mine2.push(-32);

	if (mine <= mine2)
		std::cout << "OUI" <<std::endl;
	else
		std::cout << "NON" <<std::endl;

}
