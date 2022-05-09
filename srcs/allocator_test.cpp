/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocator_test.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 14:52:06 by fmonbeig          #+#    #+#             */
/*   Updated: 2022/05/09 17:58:21 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <vector>
#include <memory>

// 1 - On va créer notre object allocator avec le type que l'on veut
// 2 - On alloue l'espace souhaité avec .allocate
// 3 - On va créer les éléments a l'intérieur de l'espace alloué avec .construct(pointer, élément a créer)
// 4 - On va kill la memoire avec .deallocate(), bien mettre le meme chiffre que l'allocation


int main()
{
	// allocator for integer values
	std::allocator<int> myAllocator;

	// allocate space for five ints
	int* arr = myAllocator.allocate(5);

	// construct sert a construire un objet a l'emplacement pointé par arr(ici)
	myAllocator.construct(arr + 2, 100);
	// On peut faire arr[3] = 10;

	std::cout << arr[0] << std::endl;
	std::cout << arr[1] << std::endl;
	std::cout << arr[2] << std::endl;
	std::cout << arr[3] << std::endl;

	// deallocate space for five ints
	myAllocator.deallocate(arr, 5); // you have deallocate the same amount you allocate otherwise is undefined

	return 0;
}

