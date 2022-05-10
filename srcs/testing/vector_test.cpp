#include "gtest/gtest.h"
#include <iostream>
#include <vector>
#include "../vector.hpp"

//Put the include you need for the test

/* TEST(categorie, Title)

*/

TEST(vector, PUSH)
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

	try
	{
		mine.at(44);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
