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
}

TEST(stack, PUSH_TOP)
{
	//INITIALIZE
	std::stack<int>	real;
	ft::stack<int>	mine;

	real.push(44);
	real.push(-34);
	real.push(42);

	mine.push(44);
	mine.push(-34);
	mine.push(42);

	//TOP & PUSH
	EXPECT_EQ(real.top(), mine.top());
	//SIZE
	EXPECT_EQ(real.size(), mine.size());
	//POP
	real.pop();
	mine.pop();
	EXPECT_EQ(real.top(), mine.top());
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

	//EMPTY
	EXPECT_EQ(real.empty(), mine.empty());
	real.pop();
	real.pop();
	real.pop();
	mine.pop();
	mine.pop();
	mine.pop();
	EXPECT_EQ(real.empty(), mine.empty());

}

TEST(stack, OPERATOR)
{
	//INITIALIZE
	std::stack<int>	real;
	ft::stack<int>	mine;

	real.push(44);
	real.push(-34);
	real.push(42);

	mine.push(44);
	mine.push(-34);
	mine.push(42);

	//OPERATOR (NO CHANGE)
	EXPECT_EQ(real == real, true);
	EXPECT_EQ(mine == mine, true);

	// //COPY CONSTRUCT + Operator =
	// std::stack<int>	real2(real);
	// ft::stack<int>	mine2(mine);

	// EXPECT_EQ();

}
