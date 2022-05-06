#include "gtest/gtest.h"
#include <iostream>
#include <stack>
#include "../stack.hpp"

//Put the include you need for the test

/* TEST(categorie, Title)

*/

TEST(stack, PUSH_TOP)
{
	std::stack<int>	real;
	ft::stack<int>	mine;

	real.push(44);
	real.push(-34);
	real.push(42);
	mine.push(44);
	mine.push(-34);
	mine.push(42);
	EXPECT_EQ(real.top(), mine.top());
	EXPECT_EQ(real.top(), 42);
	EXPECT_EQ(mine.top(), 42);
}

TEST(stack, SIZE)
{
	std::stack<int>	real;
	ft::stack<int>	mine;

	real.push(44);
	mine.push(44);
	//SIZE
	EXPECT_EQ(real.size(), mine.size());
}


TEST(stack, EMPTY)
{
	std::stack<int>	real;
	ft::stack<int>	mine;

	real.push(44);
	real.push(-34);
	real.push(42);

	mine.push(44);
	mine.push(-34);
	mine.push(42);

	EXPECT_EQ(real.empty(), mine.empty());
	real.pop();
	real.pop();
	real.pop();
	mine.pop();
	mine.pop();
	mine.pop();
	EXPECT_EQ(real.empty(), mine.empty());
}

TEST(stack, OPERATOR_WITH_EQUALITY)
{
	std::stack<int>	real;
	ft::stack<int>	mine;

	real.push(44);
	real.push(-34);
	mine.push(44);
	mine.push(-34);

	EXPECT_EQ(real == real, true);
	EXPECT_EQ(mine == mine, true);

	EXPECT_EQ(real != real, false);
	EXPECT_EQ(mine != mine, false);

	EXPECT_EQ(real <= real, true);
	EXPECT_EQ(mine <= mine, true);

	EXPECT_EQ(real >= real, true);
	EXPECT_EQ(mine >= mine, true);

	EXPECT_EQ(real < real, false);
	EXPECT_EQ(mine < mine, false);

	EXPECT_EQ(real > real, false);
	EXPECT_EQ(mine > mine, false);
}

TEST(stack, OPERATOR_NOT_EQUAL)
{
	std::stack<int>	real;
	std::stack<int>	real2;
	ft::stack<int>	mine;
	ft::stack<int>	mine2;

	real.push(44);
	real.push(-34);
	real2.push(44);
	real2.push(-32);

	mine.push(44);
	mine.push(-34);
	mine2.push(44);
	mine2.push(-32);

	EXPECT_EQ(real == real2, false);
	EXPECT_EQ(mine == mine2, false);

	EXPECT_EQ(real != real2, true);
	EXPECT_EQ(mine != mine2, true);

	EXPECT_EQ(real <= real2, true);
	EXPECT_EQ(mine <= mine2, true);

	EXPECT_EQ(real >= real2, false);
	EXPECT_EQ(mine >= mine2, false);

	EXPECT_EQ(real < real2, true);
	EXPECT_EQ(mine < mine2, true);

	EXPECT_EQ(real > real2, false);
	EXPECT_EQ(mine > mine2, false);
}

TEST(stack, COPY)
{
	std::stack<int>	real;
	ft::stack<int>	mine;

	real.push(44);
	real.push(42);
	mine.push(44);
	mine.push(42);

	std::stack<int>	real2(real);
	ft::stack<int>	mine2(mine);

	EXPECT_EQ(real2.top(), mine2.top());
	EXPECT_EQ(real2.top(), 42);
	EXPECT_EQ(mine2.top(), 42);

	std::stack<int>	real3 = real;
	ft::stack<int>	mine3 = mine;

	EXPECT_EQ(real3.top(), mine3.top());
	EXPECT_EQ(real3.top(), 42);
	EXPECT_EQ(mine3.top(), 42);
}
