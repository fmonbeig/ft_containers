#include "gtest/gtest.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include "../pair.hpp"
#include <string>

//Put the include you need for the test

/* TEST(categorie, Title)

*/

// std::equal ->
// It accepts two ranges and compare all the elements in range 1 i.e.
// [first1, last1) with all the elements in range 2 starting at first2.
// It returns true if all the range1 is equal to all the elements in range2.


TEST(vector, PAIR)
{
	std::string s1 = "Hello";
	std::pair<std::string, int>	test(std::make_pair(s1 , 99));
	// std::pair<std::string, int>	test2("bonjour", 42);


	ft::pair<std::string, int>	mine(ft::make_pair(s1 , 99));
	// ft::pair<std::string, int>	mine2("bonjour", 42);
	// EXPECT_EQ(test.first , mine.first);
	// EXPECT_EQ(test.second , mine.second);
	// EXPECT_EQ(test2.first , mine2.first);
	// EXPECT_EQ(test2.second , mine2.second);
}
