#include "gtest/gtest.h"
#include <iostream>
#include <map>
#include "../map.hpp"


//Put the include you need for the test

/* TEST(categorie, Title)

*/

// std::equal ->
// It accepts two ranges and compare all the elements in range 1 i.e.
// [first1, last1) with all the elements in range 2 starting at first2.
// It returns true if all the range1 is equal to all the elements in range2.


TEST(map, insert)
{
	std::map<int, int> real;
	std::pair<int, int> radd(100, 42);
	std::pair<int, int> radd2(50, 42);
	std::pair<int, int> radd3(4, 42);
	std::pair<int, int> radd4(2, 42);
	std::pair<int, int> radd5(999, 48);
	std::pair<int, int> radd6(7, 42);
	std::pair<int, int> radd7(12, 42);
	std::pair<int, int> radd8(-56, 42);
	std::pair<int, int> radd9(1, 42);

	real.insert(radd);
	real.insert(radd2);
	real.insert(radd3);
	real.insert(radd4);
	real.insert(radd5);
	real.insert(radd6);

	std::map<int, int> real2;
	real.insert(radd7);
	real.insert(radd8);
	real.insert(radd9);

	real.insert(real2.begin(), real2.end());

	ft::map<int, int> mine;
	ft::pair<int, int> madd(100, 42);
	ft::pair<int, int> madd2(50, 42);
	ft::pair<int, int> madd3(4, 42);
	ft::pair<int, int> madd4(2, 42);
	ft::pair<int, int> madd5(999, 48);
	ft::pair<int, int> madd6(7, 42);
	ft::pair<int, int> madd7(12, 42);
	ft::pair<int, int> madd8(-56, 42);
	ft::pair<int, int> madd9(1, 42);

	mine.insert(madd);
	mine.insert(madd2);
	mine.insert(madd3);
	mine.insert(madd4);
	mine.insert(madd5);
	mine.insert(madd6);

	ft::map<int, int> mine2;
	mine.insert(madd7);
	mine.insert(madd8);
	mine.insert(madd9);

	mine.insert(mine2.begin(), mine2.end());

	std::map<int, int>::iterator it_real = real.begin();

	for (ft::map<int, int>::iterator it = mine.begin(); it != mine.end();)
	{
		std::cout << it->first << std::endl;
		EXPECT_EQ(it->first, it_real->first);
		it++;
		it_real++;
	}
}
