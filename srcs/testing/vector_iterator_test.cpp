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

TEST(vector, RevIteratorConst) //Pronlem sur le rev it const
{
	std::vector<int>	real;
	ft::vector<int>		mine;

	real.push_back(44);
	real.push_back(-34);
	real.push_back(112);

	mine.push_back(44);
	mine.push_back(-34);
	mine.push_back(112);

	std::vector< int>::const_reverse_iterator it_real;
	ft::vector< int>::const_reverse_iterator  it_mine;

	//BEGIN() CONST
	it_real = real.rbegin();
	it_mine = mine.rbegin();

	EXPECT_EQ(*it_real, *it_mine);

	//END() CONST
	it_real = real.rend();
	it_mine = mine.rend();

	EXPECT_EQ(*it_real, *it_mine);
}

// std::vector<int>	real;
// 	ft::vector<int>		mine;

// 	real.push_back(44);
// 	real.push_back(-34);
// 	real.push_back(112);

// 	std::cout << "REAL -- BEGIN" << std::endl;
// 	std::cout << *real.begin() << std::endl;
// 	std::cout << "REAL -- ALL VECTOR" << std::endl;
// 	for(std::vector<int>::const_iterator it = real.begin(); it != real.end(); it++ )
// 		std::cout << *it << std::endl;

// 	std::cout << "REAL -- Reverse IT" << std::endl;

// 	for(std::vector<int>::reverse_iterator it = real.rbegin(); it != real.rend(); it++ )
// 		std::cout << *it << std::endl;

// 	std::cout << "REAL -- CONST Reverse IT" << std::endl;
// 	std::vector<int>::const_reverse_iterator it2 = real.rbegin();
// 	std::cout << *it2 << std::endl;

// 	mine.push_back(44);
// 	mine.push_back(-34);
// 	mine.push_back(112);

// 	std::cout << "mine -- BEGIN" << std::endl;
// 	std::cout << *mine.begin() << std::endl;
// 	std::cout << "mine -- ALL VECTOR" << std::endl;

// 	for(ft::vector<int>::const_iterator it = mine.begin(); it != mine.end(); it++)
// 	{
// 		std::cout << *it << std::endl;
// 	}

// 	std::cout << "Mine -- Reverse IT" << std::endl;

// 	for(ft::vector<int>::reverse_iterator it = mine.rbegin(); it != mine.rend(); it++ )
// 		std::cout << *it << std::endl;

// 	std::cout << "REAL -- CONST Reverse IT" << std::endl;
// 	ft::vector<int>::const_reverse_iterator it = mine.rbegin();

// 	std::cout << *it << std::endl;
