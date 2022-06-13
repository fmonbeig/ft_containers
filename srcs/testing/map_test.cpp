#include "gtest/gtest.h"
#include <iostream>
#include <map>
#include "../map.hpp"

#define OWN ft


TEST(MapTest, Constructors)
{
	OWN::map<char, int> first;

	first['a'] = 10;
	first['b'] = 30;
	first['c'] = 50;
	first['d'] = 70;

	OWN::map<char, int> second(first.begin(), first.end());
	OWN::map<char, int> third(second);

	EXPECT_EQ(first.size(), size_t(4));
	EXPECT_EQ(second.size(), size_t(4));
	EXPECT_EQ(third.size(), size_t(4));
}

TEST(MapTest, Assignment)
{
	OWN::map<char, int> first;
	OWN::map<char, int> second;

	first['x'] = 8;
	first['y'] = 16;
	first['z'] = 32;

	second = first;					// second now contains 3 ints
	first = OWN::map<char, int>();	// and mine is now empty

	EXPECT_EQ(first.size(), size_t(0));
	EXPECT_EQ(second.size(), size_t(3));
}

TEST(MapTest, Access)
{
	std::map<int, int> real;

	for (int i = 0; i < 50; i++)
		real.insert(std::pair<int, int>(i, i));

	OWN::map<int, int> mine;

	for (int i = 0; i < 50; i++)
		mine.insert(OWN::pair<int, int>(i, i));

	EXPECT_EQ(real[4], mine[4]);
	EXPECT_EQ(real[0], mine[0]);
	EXPECT_EQ(real[49], mine[49]);
	EXPECT_EQ(real.at(20), mine.at(20));
	EXPECT_EQ(real.at(37), mine.at(37));
}

TEST(MapTest, iterator)
{
	std::map<int, int> real;

	for (int i = 0; i < 50; i++)
		real.insert(std::pair<int, int>(i, i));

	std::map<int, int>::iterator r_it = real.begin();
	std::map<int, int>::iterator r_ite = real.end();
	r_ite--;
	std::map<int, int>::reverse_iterator r_revit = real.rbegin();
	r_revit++;
	std::map<int, int>::reverse_iterator r_revite = real.rend();
	r_revite--;

	OWN::map<int, int> mine;

	for (int i = 0; i < 50; i++)
		mine.insert(OWN::pair<int, int>(i, i));

	OWN::map<int, int>::iterator it = mine.begin();
	OWN::map<int, int>::iterator ite = mine.end();
	ite--;
	OWN::map<int, int>::reverse_iterator revit = mine.rbegin();
	revit++;
	OWN::map<int, int>::reverse_iterator revite = mine.rend();
	revite--;

	EXPECT_EQ(it->first, r_it->first);
	EXPECT_EQ(r_ite->first, ite->first);
	EXPECT_EQ(r_revit->first, revit->first);
	EXPECT_EQ(r_revite->first, revite->first);
}

TEST(MapTest, capacity)
{
	std::map<int, int> real;
	OWN::map<int, int> mine;

	EXPECT_EQ(real.size(), mine.size());
	EXPECT_EQ(real.empty(), mine.empty());

	for (int i = 0; i < 50; i++)
		real.insert(std::pair<int, int>(i, i));

	for (int i = 0; i < 50; i++)
		mine.insert(OWN::pair<int, int>(i, i));

	EXPECT_EQ(real.size(), mine.size());
	EXPECT_EQ(real.empty(), mine.empty());

	real.clear();
	mine.clear();

	EXPECT_EQ(real.size(), mine.size());
	EXPECT_EQ(real.empty(), mine.empty());
}


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

	OWN::map<int, int> mine;
	OWN::pair<int, int> madd(100, 42);
	OWN::pair<int, int> madd2(50, 42);
	OWN::pair<int, int> madd3(4, 42);
	OWN::pair<int, int> madd4(2, 42);
	OWN::pair<int, int> madd5(999, 48);
	OWN::pair<int, int> madd6(7, 42);
	OWN::pair<int, int> madd7(12, 42);
	OWN::pair<int, int> madd8(-56, 42);
	OWN::pair<int, int> madd9(1, 42);

	mine.insert(madd);
	mine.insert(madd2);
	mine.insert(madd3);
	mine.insert(madd4);
	mine.insert(madd5);
	mine.insert(madd6);

	OWN::map<int, int> mine2;
	mine.insert(madd7);
	mine.insert(madd8);
	mine.insert(madd9);

	mine.insert(mine2.begin(), mine2.end());

	std::map<int, int>::iterator it_real = real.begin();

	for (OWN::map<int, int>::iterator it = mine.begin(); it != mine.end();)
	{
		// std::cout << it->first << std::endl;
		EXPECT_EQ(it->first, it_real->first);
		it++;
		it_real++;
	}
}

TEST(map, Erase)
{
	std::map<std::string, int> real;

	real["bonjour"] = 42;
	real["je"] = 42;
	real["suis"] = 42;
	real["un"] = 42;
	real["dinosaure"] = 42;
	real["lol"] = 42;
	real["."] = 42;

	OWN::map<std::string, int> mine;

	mine["bonjour"] = 42;
	mine["je"] = 42;
	mine["suis"] = 42;
	mine["un"] = 42;
	mine["dinosaure"] = 42;
	mine["lol"] = 42;
	mine["."] = 42;

	real.erase(real.begin());
	mine.erase(mine.begin());
	real.erase("lol");
	mine.erase("lol");

	std::map<std::string, int>::iterator it_real = real.begin();

	for (OWN::map<std::string, int>::iterator it = mine.begin(); it != mine.end();)
	{
		EXPECT_EQ(it->first, it_real->first);
		it++;
		it_real++;
	}

	real.erase(real.begin(), real.end());
	mine.erase(mine.begin(), mine.end());

	EXPECT_EQ(real.empty(), true);
	EXPECT_EQ(mine.empty(), true);
}


TEST(map, Swap)
{
	OWN::map<std::string, int> mine;

	mine["je suis"] = 42;
	mine["un"] = 42;
	mine["arbre"] = 100;

	OWN::map<std::string, int> mine2;

	mine2["je suis"] = 42;
	mine2["un"] = 42;
	mine2["elephant"] = 9;

	EXPECT_EQ(mine["arbre"], 100);
	EXPECT_EQ(mine2["elephant"], 9);

	mine.swap(mine2);

	EXPECT_EQ(mine2["arbre"], 100);
	EXPECT_EQ(mine["elephant"], 9);
}

TEST(map, count_and_find)
{
	OWN::map<std::string, int> mine;

	mine["je suis"] = 42;
	mine["un"] = 42;
	mine["arbre"] = 100;

	EXPECT_EQ(mine.count("arbre"), true);
	EXPECT_EQ(mine.count("rien"), false);

	EXPECT_EQ(mine.find("arbre")->second, 100);
}

TEST(map, Bound)
{
	std::map<std::string, int> real;

	real["bonjour"] = 42;
	real["je"] = 42;
	real["suis"] = 42;
	real["un"] = 42;
	real["dinosaure"] = 42;
	real["lol"] = 42;
	real["."] = 42;

	OWN::map<std::string, int> mine;

	mine["bonjour"] = 42;
	mine["je"] = 42;
	mine["suis"] = 42;
	mine["un"] = 42;
	mine["dinosaure"] = 42;
	mine["lol"] = 42;
	mine["."] = 42;

	std::map<std::string, int>::iterator it_real = real.upper_bound("Jupiter");
	OWN::map<std::string, int>::iterator it_mine = mine.upper_bound("Jupiter");

	EXPECT_EQ(it_real->first, it_mine->first);

	it_real = real.lower_bound("Jupiter");
	it_mine = mine.lower_bound("Jupiter");

	EXPECT_EQ(it_real->first, it_mine->first);

}

TEST(map, Operator)
{
	std::map<std::string, int> real;
	std::map<std::string, int> real2;

	real["bonjour"] = 42;
	real["je"] = 42;
	real["suis"] = 42;
	real["un"] = 42;
	real["dinosaure"] = 42;
	real["lol"] = 42;
	real["."] = 42;

	real2 = real;

	OWN::map<std::string, int> mine;
	OWN::map<std::string, int> mine2;

	mine["bonjour"] = 42;
	mine["je"] = 42;
	mine["suis"] = 42;
	mine["un"] = 42;
	mine["dinosaure"] = 42;
	mine["lol"] = 42;
	mine["."] = 42;

	mine2 = mine;

	EXPECT_EQ((real == real2), (mine == mine2));
	EXPECT_EQ((real != real2), (mine != mine2));
	EXPECT_EQ((real >= real2), (mine >= mine2));
	EXPECT_EQ((real > real2), (mine > mine2));
	EXPECT_EQ((real <= real2), (mine <= mine2));
	EXPECT_EQ((real < real2), (mine < mine2));

}

TEST(MapTest, Time_ft)
{
	OWN::map<int, int> mine;

	for (int i = 0; i < 1000000; i++)
		mine.insert(OWN::pair<int, int>(i, i));

	mine.find(9999);
	mine.find(48949);
	mine.find(1);
	mine.find(48);

	mine.clear();
}

TEST(MapTest, Time_std)
{
	std::map<int, int> real;

	for (int i = 0; i < 1000000; i++)
		real.insert(std::pair<int, int>(i, i));

	real.find(9999);
	real.find(48949);
	real.find(1);
	real.find(48);

	real.clear();
}



