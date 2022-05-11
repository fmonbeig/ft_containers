/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocator_test.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 14:52:06 by fmonbeig          #+#    #+#             */
/*   Updated: 2022/05/11 12:06:11 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "iterator_traits.hpp"

// 1 - On va créer notre object allocator avec le type que l'on veut
// 2 - On alloue l'espace souhaité avec .allocate
// 3 - On va créer les éléments a l'intérieur de l'espace alloué avec .construct(pointer, élément a créer)
// 4 - On va kill la memoire avec .deallocate(), bien mettre le meme chiffre que l'allocation


int main()
{
	ft::iterator_traits<int*>::value_type i;

	i = 10;

	std::cout << i << std::endl;

	return 0;
}

