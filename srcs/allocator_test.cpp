/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocator_test.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 14:52:06 by fmonbeig          #+#    #+#             */
/*   Updated: 2022/05/05 15:00:59 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <vector>
#include <memory>

int main()
{

	// allocator for integer values
	std::allocator<int> myAllocator;

	// allocate space for five ints
	int* arr = myAllocator.allocate(5);

	// construct arr[0] and arr[3]  // construct sert a construire un objet
	myAllocator.construct(arr, 100);
	arr[3] = 10;

	std::cout << arr[3] << std::endl;
	std::cout << arr[2] << std::endl;
	std::cout << arr[1] << std::endl;
	std::cout << arr[0] << std::endl;

	// deallocate space for five ints
	myAllocator.deallocate(arr, 5);

	return 0;
}

