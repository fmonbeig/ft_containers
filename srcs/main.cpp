/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 11:37:09 by fmonbeig          #+#    #+#             */
/*   Updated: 2022/05/06 14:38:37 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "stack.hpp"
#include <stack>

int main()
{
	std::stack<int>	real;
	ft::stack<int>	mine;

	real.push(44);
	real.push(42);

	mine.push(44);
	mine.push(42);

	std::cout << "REAL " << real.top() << " MINE " << mine.top() <<std::endl;

	if (mine == mine)
		std::cout << "HELLO" <<std::endl;

}
