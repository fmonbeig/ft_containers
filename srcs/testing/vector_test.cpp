#include "gtest/gtest.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include "../vector.hpp"

//Put the include you need for the test

/* TEST(categorie, Title)

*/

// std::equal ->
// It accepts two ranges and compare all the elements in range 1 i.e.
// [first1, last1) with all the elements in range 2 starting at first2.
// It returns true if all the range1 is equal to all the elements in range2.

TEST(vector, PUSHBACK)
{
	std::vector<int>	real;
	ft::vector<int>	mine;

	real.push_back(44);
	real.push_back(-34);
	real.push_back(42);
	mine.push_back(44);
	mine.push_back(-34);
	mine.push_back(42);
	EXPECT_EQ(real.at(1), mine.at(1));
}

TEST(vector, ASSIGN)
{
	std::vector<int>	real;
	ft::vector<int>		mine;

	real.assign(3,42);
	mine.assign(3,42);

	bool result = std::equal(real.begin(), real.end(), mine.begin());

	EXPECT_EQ(result, true);
}

TEST(vector, ASSIGNV2)
{
	std::vector<int>	real;
	std::vector<int>	temp_real;

	temp_real.push_back(44);
	temp_real.push_back(14);
	temp_real.push_back(98989);

	real.assign(temp_real.begin(),temp_real.end());

	ft::vector<int>		mine;
	ft::vector<int>		temp_mine;

	temp_mine.push_back(44);
	temp_mine.push_back(14);
	temp_mine.push_back(98989);

	mine.assign(temp_mine.begin(),temp_mine.end());

	bool result = ft::equal(mine.begin(), mine.end(), temp_real.begin());

	EXPECT_EQ(result, true);
}
