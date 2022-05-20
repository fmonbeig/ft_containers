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


TEST(vector, CONSTRUCTOR)
{
	ft::vector<int>		mine;

	mine.push_back(44);
	mine.push_back(-34);
	mine.push_back(112);

	ft::vector<int>	temp_mine(mine.begin(), mine.end());

	bool result = ft::equal(mine.begin(), mine.end(), temp_mine.begin());
	EXPECT_EQ(result, true);
}

TEST(vector, ACCESS)
{
	ft::vector<int>		mine;

	mine.push_back(44);
	mine.push_back(-34);
	mine.push_back(112);

	EXPECT_EQ(mine.at(1), mine[1]);
	EXPECT_EQ(mine[0], mine.front());
	EXPECT_EQ(mine[2], mine.back());

	int * tmp = mine.data();
	EXPECT_EQ(*tmp, mine.front());
}

TEST(vector, ASSIGN)
{
	std::vector<int>	real;
	ft::vector<int>		mine;

	real.assign(3,42);
	mine.assign(3,42);

	bool result = ft::equal(real.begin(), real.end(), mine.begin());

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

TEST(vector, CAPACITY)
{
	ft::vector<int>		mine;

	EXPECT_EQ(mine.empty(), true);

	mine.push_back(44);
	mine.push_back(-34);
	mine.push_back(112);

	EXPECT_EQ(mine.empty(), false);
	EXPECT_EQ(mine.size(), (size_t)3);
}


TEST(vector, INSERT)
{
	std::vector<int>		real;
	std::vector<int>		Radd;

	real.push_back(44);
	real.push_back(-34);
	real.push_back(112);

	Radd.push_back(777);
	Radd.push_back(778);
	Radd.push_back(779);
	Radd.push_back(800);

	real.insert(real.begin() + 1, 99);
	real.insert(real.begin() + 3, 5, 200);
	real.insert(real.begin() + 2, Radd.begin(), Radd.end());

	ft::vector<int>		mine;
	ft::vector<int>		Madd;

	mine.push_back(44);
	mine.push_back(-34);
	mine.push_back(112);

	Madd.push_back(777);
	Madd.push_back(778);
	Madd.push_back(779);
	Madd.push_back(800);

	mine.insert(mine.begin() + 1, 99);
	mine.insert(mine.begin() + 3, 5, 200);
	mine.insert(mine.begin() + 2, Madd.begin(), Madd.end());

	for (int i = 0; real.begin() + i != real.end(); i++)
		EXPECT_EQ(*(real.begin() + i), *(mine.begin() + i));

}

TEST(vector, ERASE)
{
	std::vector<int>		real;

	real.push_back(44);
	real.push_back(-34);
	real.push_back(112);
	real.push_back(560);
	real.push_back(610);
	real.push_back(9910);
	real.push_back(9910);
	real.push_back(9910);
	real.push_back(9910);
	real.pop_back();

	real.erase(real.begin());
	real.erase((real.begin() + 2), (real.begin() + 4));

	ft::vector<int>		mine;

	mine.push_back(44);
	mine.push_back(-34);
	mine.push_back(112);
	mine.push_back(560);
	mine.push_back(610);
	mine.push_back(9910);
	mine.push_back(9910);
	mine.push_back(9910);
	mine.push_back(9910);
	mine.pop_back();

	mine.erase(mine.begin());
	mine.erase((mine.begin() + 2), (mine.begin() + 4));

	for (int i = 0; real.begin() + i != real.end(); i++)
		EXPECT_EQ(*(real.begin() + i), *(mine.begin() + i));
}

TEST(vector, SWAP)
{
	std::vector<int>	real;
	std::vector<int>	real2;

	real.push_back(44);
	real.push_back(-34);
	real.push_back(112);

	real2.push_back(1);
	real2.push_back(2);
	real2.push_back(3);

	real.swap(real2);


	ft::vector<int>		mine;
	ft::vector<int>		mine2;

	mine.push_back(44);
	mine.push_back(-34);
	mine.push_back(112);

	mine2.push_back(1);
	mine2.push_back(2);
	mine2.push_back(3);

	mine.swap(mine2);

	for (int i = 0; real.begin() + i != real.end(); i++)
		EXPECT_EQ(*(real.begin() + i), *(mine.begin() + i));

}

TEST(vector, RESIZE)
{
	std::vector<int>	real;

	real.push_back(44);
	real.push_back(-34);
	real.push_back(112);

	real.resize(2);
	real.resize(5, 99);

	ft::vector<int>		mine;

	mine.push_back(44);
	mine.push_back(-34);
	mine.push_back(112);

	mine.resize(2);
	mine.resize(5, 99);

	for (int i = 0; real.begin() + i != real.end(); i++)
		EXPECT_EQ(*(real.begin() + i), *(mine.begin() + i));
}

TEST(vector, OPERATOR)
{
	std::vector<int>	real;
	std::vector<int>	real2;

	real.push_back(44);
	real.push_back(-34);
	real.push_back(112);

	real2.push_back(26);
	real2.push_back(25);
	real2.push_back(32);
	real2.push_back(32);

	ft::vector<int>	mine;
	ft::vector<int>	mine2;

	mine.push_back(44);
	mine.push_back(-34);
	mine.push_back(112);

	mine2.push_back(26);
	mine2.push_back(25);
	mine2.push_back(32);
	mine2.push_back(32);

	EXPECT_EQ((real == real2), (mine == mine2));
	EXPECT_EQ((real != real2), (mine != mine2));
	EXPECT_EQ((real >= real2), (mine >= mine2));
	EXPECT_EQ((real > real2), (mine > mine2));
	EXPECT_EQ((real <= real2), (mine <= mine2));
	EXPECT_EQ((real < real2), (mine < mine2));
}

