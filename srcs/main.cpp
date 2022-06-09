/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 11:37:09 by fmonbeig          #+#    #+#             */
/*   Updated: 2022/06/09 15:20:35 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <functional>
#include "vector.hpp"
#include "stack.hpp"
#include "map.hpp"

int main ()
{
	ft::map<char, int> mymap;
	ft::map<char, int>::iterator itlow,itup;

	mymap['a']=20;
	mymap['b']=40;
	mymap['c']=60;
	mymap['d']=80;
	mymap['e']=100;

	itlow = mymap.lower_bound ('b');  // itlow points to b
	itup =  mymap.upper_bound ('d');   // itup points to e (not d!)

	std::cout << "low : " << itlow->first << '\n';
	std::cout << "up : " << itup->first << '\n';

	// mymap.print_tree();

	mymap.erase(itlow,itup);        // erases [itlow,itup)

	// mymap.erase(itlow->first);        // erases [itlow,itup)

	// print content:
	for (ft::map<char,int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	return 0;
}

// int main()
// {
// 			+------------------------------------------+ //
// 			  REAL								        //
// 			+------------------------------------------+ //
// 	std::map<int, int> real;
// 	std::pair<int, int> add(100, 42);
// 	std::pair<int, int> add2(50, 42);
// 	std::pair<int, int> add3(4, 42);
// 	std::pair<int, int> add4(2, 42);
// 	std::pair<int, int> add5(999, 48);
// 	std::pair<int, int> add6(7, 42);



// 	std::map<int, int>::const_iterator ite = real.end();

// 	real.insert(add);
// 	real.insert(add2);
// 	real.insert(add3);
// 	real.insert(add4);
// 	real.insert(add5);
// 	real.insert(add6);

// 	ite--;

// 	std::cout << ite->first << std::endl;
// 	std::map<int, int>::const_iterator it = real.begin();




// 			+------------------------------------------+ //
// 			  MINE								        //
// 			+------------------------------------------+ //

	// ft::map<int, std::string> mine;
	// ft::pair<int, std::string> add(100, "42");

	// ft::pair<int, int> add(100, 42);
	// ft::pair<int, int> add2(50, 42);
	// ft::pair<int, int> add3(4, 42);
	// ft::pair<int, int> add4(2, 42);
	// ft::pair<int, int> add5(999, 48);
	// ft::pair<int, int> add6(7, 42);
	// ft::pair<int, int> add7(12, 42);
	// ft::pair<int, int> add8(-56, 42);
	// ft::pair<int, int> add9(1, 42);

	// mine.insert(add);
	// mine.insert(add2);
	// mine.insert(add3);
	// mine.insert(add4);
	// mine.insert(add5);
	// mine.insert(add6);
	// mine.insert(add7);
	// mine.insert(add8);
	// mine.insert(add9);

// 	ft::map<int, int> mine2;
// 	mine2.insert(add7);
// 	mine2.insert(add8);
// 	mine2.insert(add9);
// 	ft::map<int, int> mine2(mine);

// 	mine.insert(mine2.begin(), mine2.end());



// FIXME
// 	for (ft::map<int, int>::iterator it = mine.begin(); it != mine.end(); it++)
// 	{
// 		std::cout << it->first << std::endl;
// 	}

// 	mine.erase(mine.begin(), mine.end());

// 	std::cout <<mine.count(99) << std::endl;
// 	std::cout << "SIZE " <<mine.size() << std::endl;
// 	mine.insert(mine2.begin(), mine2.end());

// 	ft::map<int, int>::iterator it = mine.begin();
// 	it++;
// 	it++;
// 	it++;
// 	it++;
// 	it++;
// 	it++;

// 	std::cout << " ERASE OF " << it->first << std::endl;

// 	mine.erase(it);
// 	it++;
// 	// mine.erase(it);


// }
