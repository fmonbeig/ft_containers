#include "gtest/gtest.h"
#include <iostream>
#include <vector>
#include "../vector.hpp"

//Put the include you need for the test

/* TEST(categorie, Title)

*/

TEST(vector, OPERATOR)
{
	std::vector<int>	real;
	ft::vector<int>		mine;

	real.push_back(44);
	real.push_back(-34);
	real.push_back(112);

	mine.push_back(44);
	mine.push_back(-34);
	mine.push_back(112);

	std::vector<int>::iterator it_real;
	ft::vector<int>::iterator  it_mine;

	//BEGIN()
	it_real = real.begin();
	it_mine = mine.begin();

	EXPECT_EQ(*it_real, *it_mine);
	//END()
	it_real = real.end();
	it_mine = mine.end();

	EXPECT_EQ(*it_real, *it_mine);
}
