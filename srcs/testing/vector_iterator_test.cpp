#include "gtest/gtest.h"
#include <iostream>
#include <vector>
#include "../vector.hpp"

//Put the include you need for the test
/* TEST(categorie, Title)
*/

TEST(vector, Iterator)
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

TEST(vector, IteratorConst)
{
	std::vector<int>	real;
	ft::vector<int>		mine;

	real.push_back(44);
	real.push_back(-34);
	real.push_back(112);

	mine.push_back(44);
	mine.push_back(-34);
	mine.push_back(112);

	std::vector< int>::const_iterator it_real;
	ft::vector< int>::const_iterator  it_mine;

	//BEGIN() CONST
	it_real = real.begin();
	it_mine = mine.begin();

	EXPECT_EQ(*it_real, *it_mine);

	//END() CONST
	it_real = real.end();
	it_mine = mine.end();

	EXPECT_EQ(*it_real, *it_mine);
}

TEST(vector, RevIterator)
{
	std::vector<int>	real;
	ft::vector<int>		mine;

	real.push_back(44);
	real.push_back(-34);
	real.push_back(112);

	mine.push_back(44);
	mine.push_back(-34);
	mine.push_back(112);

	std::vector< int>::reverse_iterator it_real;
	ft::vector< int>::reverse_iterator  it_mine;

	//BEGIN() CONST
	it_real = real.rbegin();
	it_mine = mine.rbegin();

	EXPECT_EQ(*it_real, *it_mine);

	//END() CONST
	it_real = real.rend();
	it_mine = mine.rend();

	EXPECT_EQ(*it_real, *it_mine);
}

TEST(vector, RevIteratorConst)
{
	std::vector<int>	real;
	ft::vector<int>		mine;

	real.push_back(44);
	real.push_back(-34);
	real.push_back(112);

	mine.push_back(44);
	mine.push_back(-34);
	mine.push_back(112);

	std::vector<int>::const_reverse_iterator it_real;

	ft::vector<int>::reverse_iterator  it_mine;

	//BEGIN() CONST
	it_real = real.rbegin();
	it_mine = mine.rbegin();

	EXPECT_EQ(*it_real, *it_mine);

	//END() CONST
	it_real = real.rend();
	it_mine = mine.rend();

	EXPECT_EQ(*it_real, *it_mine);
}
