/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 11:37:09 by fmonbeig          #+#    #+#             */
/*   Updated: 2022/06/10 13:45:15 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <functional>
#include "vector.hpp"
#include "stack.hpp"
#include "map.hpp"
#include <cstdio>
#include <iomanip>

/*
** This is a minimal set of ANSI/VT100 color codes
*/
# define _END			"\x1b[0m"
# define _BOLD			"\x1b[1m"
# define _UNDER			"\x1b[4m"
# define _REV			"\x1b[7m"

/*
** Colors
*/
# define _GREY			"\x1b[30m"
# define _RED			"\x1b[31m"
# define _GREEN			"\x1b[32m"
# define _YELLOW		"\x1b[33m"
# define _BLUE			"\x1b[34m"
# define _PURPLE		"\x1b[35m"
# define _CYAN			"\x1b[36m"
# define _WHITE			"\x1b[37m"

/*
** Inverted, i.e. colored backgrounds
*/
# define _IGREY			"\x1b[40m"
# define _IRED			"\x1b[41m"
# define _IGREEN		"\x1b[42m"
# define _IYELLOW		"\x1b[43m"
# define _IBLUE			"\x1b[44m"
# define _IPURPLE		"\x1b[45m"
# define _ICYAN			"\x1b[46m"
# define _IWHITE		"\x1b[47m"

template <class Key, class T>
void	print(ft::map<Key, T>& lst)
{
	std::cout << "printing a map : \n";
	for (typename ft::map<Key, T>::iterator it = lst.begin(); it != lst.end(); it++)
		std::cout << it->first << " => " << it->second << '\n';
}


// int main ()
// {
//   std::map<char,int> mymap;
//   std::map<char,int>::iterator itlow,itup;

//   mymap['a']=20;
//   mymap['b']=40;
//   mymap['c']=60;
//   mymap['d']=80;
//   mymap['e']=100;

//   itlow=mymap.lower_bound ('b');  // itlow points to b
//   itup=mymap.upper_bound ('d');   // itup points to e (not d!)

//   std::cout << "low : " << itlow->first << '\n';
//   std::cout << "up : " << itup->first << '\n';

//   mymap.erase(itlow,itup);        // erases [itlow,itup)


//   std::map<char,int>::iterator itr=mymap.begin();

//   // std::cout <<"BEGIN = " <<itr->first << " => " << itr->second << '\n';

//   // print content:
//   for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
//   {
//     std::cout << it->first << " => " << it->second << '\n';
//   }

//   return 0;
// }

int main()
{
	std::cout << _WHITE << "# test_map" << _END << std::endl;
	std::cout << _YELLOW <<  "/* ********************************************************************** */" << std::endl;
	std::cout << "/*                          "<< _WHITE << "BASIC TESTS" << _YELLOW << "                                   */" << std::endl;
	std::cout << "/* ********************************************************************** */" << _END << std::endl;
	std::cout << std::endl;


	ft::map<std::string, int> mymap;
	print(mymap);


	std::cout << "mymap" << _PURPLE << "std::string" << _END << ", " << _PURPLE << "int" << _END <<"> mymap;" << std::endl;

	std::cout << std::endl;
	std::cout << "mymap.max_size(): " << (mymap.max_size() > 10000) << std::endl;
	print(mymap);
	std::cout << std::endl;


	print(mymap);
	mymap.insert(ft::pair<std::string, int>("ft", 42));

	print(mymap);
	mymap.insert(ft::pair<std::string, int>("one", 1));


	std::cout << _WHITE << "# testing upper/lower_bound" << _END << std::endl;
	ft::map<std::string, int>::iterator mit;
	ft::map<std::string, int>::iterator it;
	print(mymap);
	it = mymap.lower_bound("aaa");
	print(mymap);
	std::cout << std::setw(40) << "mymap.lower_bound(\"aaa\"): " << it->first << ":" << it->second << std::endl;
	std::cout << std::endl;
	print(mymap);
	it = mymap.lower_bound("one");
	print(mymap);
	std::cout << std::setw(40) << "mymap.lower_bound(\"one\"): " << it->first << ":" << it->second << std::endl;
	std::cout << std::endl;
	print(mymap);
	it = mymap.lower_bound("oae");
	print(mymap);
	std::cout << std::setw(40) << "mymap.lower_bound(\"oae\"): " << it->first << ":" << it->second << std::endl;
	std::cout << std::endl;
	print(mymap);
	it = mymap.lower_bound("ft");
	print(mymap);
	std::cout << std::setw(40) << "mymap.lower_bound(\"ft\"): " << it->first << ":" << it->second << std::endl;
	std::cout << std::endl;
	print(mymap);
	it = mymap.lower_bound("zzz");
	print(mymap);

	if (it == mymap.end())
		std::cout << std::setw(40) << "mymap.lower_bound(\"zzz\"): mymap.end()" << std::endl;
	std::cout << std::endl;
	print(mymap);
	it = mymap.upper_bound("aaa");

	print(mymap);
	std::cout << std::setw(40) << "mymap.upper_bound(\"aaa\"): " << it->first << ":" << it->second << std::endl;;
	std::cout << std::endl;
	print(mymap);
	it = mymap.upper_bound("oae");
	print(mymap);
	std::cout << std::setw(40) << "mymap.upper_bound(\"oae\"): " << it->first << ":" << it->second << std::endl;;
	std::cout << std::endl;
	print(mymap);
	it = mymap.upper_bound("one");

	if (it == mymap.end())
		std::cout << std::setw(40) << "mymap.upper_bound(\"one\"): mymap.end()" << std::endl;
	print(mymap);
	std::cout << std::endl;
	it = mymap.upper_bound("ft");
	print(mymap);
	std::cout << std::setw(40) << "mymap.upper_bound(\"ft\"): " << it->first << ":" << it->second << std::endl;;
	std::cout << std::endl;
	print(mymap);
	it = mymap.upper_bound("zzz");

	if (it == mymap.end())
		std::cout << std::setw(40) << "mymap.upper_bound(\"zzz\"): mymap.end()" << std::endl;
	print(mymap);
	std::cout << std::endl;

	print(mymap);
	mymap.erase("undefined");
	print(mymap);
	mymap.erase("ft");
	print(mymap);
	std::cout << _WHITE << "# double clear" << _END << std::endl;
	mymap.clear();
	print(mymap);
	mymap.clear();
	print(mymap);
	mymap["lol"];
	print(mymap);
	mymap.insert(ft::pair<std::string, int>("xD", 123));
	print(mymap);
	mymap.insert(mymap.end(), ft::pair<std::string, int>("uch", 442));
	print(mymap);
	mymap.insert(mymap.begin(), ft::pair<std::string, int>("uch", 22));
	print(mymap);
	mymap.insert(mymap.end(), ft::pair<std::string, int>("uch", 23));
	print(mymap);
	mymap.insert(ft::pair<std::string, int>("uch", 23));
	print(mymap);
	mymap["lol"] = 8;


	print(mymap);
	ft::map<std::string, int> map2;

	print(mymap);
	print(map2);
	std::cout << "mymap<" << _PURPLE << "string" << _END << ", " << _PURPLE << "int" << _END <<"> mymap2;" << std::endl;
	print(mymap);
	std::cout << "empty line\n";
	print(map2);
	std::cout << "empty line2\n";

	swap(mymap, map2);
	std::cout << "empty line3\n";
	print(mymap);
	std::cout << "empty line4\n";
	print(map2);
	std::cout << "empty line5\n";

	mymap = map2;
	print(mymap);
	print(map2);

	std::cout << std::setw(40) << "map == map2: " << (mymap == map2) << std::endl;
	print(mymap);
	print(map2);
	std::cout << std::endl;

	mymap.clear();
	print(mymap);
	print(map2);

	mymap["satan"] = 666;
	print(mymap);
	print(map2);
	std::cout << std::setw(40) << "mymap == map2: " << (mymap == map2) << std::endl;
	print(mymap);
	print(map2);
	std::cout << std::endl;
	std::cout << std::setw(40) << "mymap <= map2: " << (mymap <= map2) << std::endl;
	print(mymap);
	print(map2);
	std::cout << std::endl;
	std::cout << std::setw(40) << "mymap >= map2: " << (mymap >= map2) << std::endl;
	print(mymap);
	print(map2);
	std::cout << std::endl;
	std::cout << std::setw(40) << "mymap > map2: " << (mymap > map2) << std::endl;
	print(mymap);
	print(map2);
	std::cout << std::endl;
	std::cout << std::setw(40) << "mymap < map2: " << (mymap > map2) << std::endl;
	print(mymap);
	print(map2);
	std::cout << std::endl;

	return 0;
}

// int main()
// {
// 	ft::pair<int, std::string>			my_pair(8, "salut");
// 	ft::map<int, std::string>			test;
// 	ft::map<int, std::string>::iterator	it;

// 	test.insert(my_pair);
// 	test.insert(ft::pair<int, std::string>(-4, "bar"));
// 	test.insert(ft::pair<int, std::string>(2, "machin"));
// 	test.insert(ft::pair<int, std::string>(3, "foo"));
// 	test.insert(ft::pair<int, std::string>(746, "Marcel"));
// 	test.insert(ft::pair<int, std::string>(1, "truc"));
// 	it = test.begin();
// 	std::cout << '\n';

// 	// test.print_tree();

// 	while (it != test.end())
// 	{
// 		// std::cout << "start of while\n";
// 		std::cout << it->first << ", " << it->second << '\n';
// 		it++;
// 		std::cout << "iterator incremented\n";

// #ifndef STD
// 		std::cout << it.getPointer() << '\n';
// 		std::cout << test.end().getPointer() << '\n';
// #endif

// 	}
// 	std::cout << "End of display loop\n";
// }

// int main ()
// {
// 	ft::map<char, int> mymap;
// 	ft::map<char, int>::iterator itlow,itup;

// 	mymap['a']=20;
// 	mymap['b']=40;
// 	mymap['c']=60;
// 	mymap['d']=80;
// 	mymap['e']=100;

// 	itlow = mymap.lower_bound ('b');  // itlow points to b
// 	itup =  mymap.upper_bound ('d');   // itup points to e (not d!)

// 	std::cout << "low : " << itlow->first << '\n';
// 	std::cout << "up : " << itup->first << '\n';

// 	// mymap.print_tree();

// 	mymap.erase(itlow,itup);        // erases [itlow,itup)

// 	// mymap.erase(itlow->first);        // erases [itlow,itup)

// 	// print content:
// 	for (ft::map<char,int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
// 		std::cout << it->first << " => " << it->second << '\n';

// 	return 0;
// }

// int main()
// {
// 			+------------------------------------------+ //
// 			  REAL								        //
// 			+------------------------------------------+ //
// 	std::map<int, int> real;
// 	std::pair<int, int> add(100, 42);
// 	std::pair<int, int> add2(50, 42);
// 	std::pair<int, int> add3(4, 42);
// 	std::pair<int, int> add4(2, 42);
// 	std::pair<int, int> add5(999, 48);
// 	std::pair<int, int> add6(7, 42);



// 	std::map<int, int>::const_iterator ite = real.end();

// 	real.insert(add);
// 	real.insert(add2);
// 	real.insert(add3);
// 	real.insert(add4);
// 	real.insert(add5);
// 	real.insert(add6);

// 	ite--;

// 	std::cout << ite->first << std::endl;
// 	std::map<int, int>::const_iterator it = real.begin();




// 			+------------------------------------------+ //
// 			  MINE								        //
// 			+------------------------------------------+ //

	// ft::map<int, std::string> mine;
	// ft::pair<int, std::string> add(100, "42");

	// ft::pair<int, int> add(100, 42);
	// ft::pair<int, int> add2(50, 42);
	// ft::pair<int, int> add3(4, 42);
	// ft::pair<int, int> add4(2, 42);
	// ft::pair<int, int> add5(999, 48);
	// ft::pair<int, int> add6(7, 42);
	// ft::pair<int, int> add7(12, 42);
	// ft::pair<int, int> add8(-56, 42);
	// ft::pair<int, int> add9(1, 42);

	// mine.insert(add);
	// mine.insert(add2);
	// mine.insert(add3);
	// mine.insert(add4);
	// mine.insert(add5);
	// mine.insert(add6);
	// mine.insert(add7);
	// mine.insert(add8);
	// mine.insert(add9);

// 	ft::map<int, int> mine2;
// 	mine2.insert(add7);
// 	mine2.insert(add8);
// 	mine2.insert(add9);
// 	ft::map<int, int> mine2(mine);

// 	mine.insert(mine2.begin(), mine2.end());



// FIXME
// 	for (ft::map<int, int>::iterator it = mine.begin(); it != mine.end(); it++)
// 	{
// 		std::cout << it->first << std::endl;
// 	}

// 	mine.erase(mine.begin(), mine.end());

// 	std::cout <<mine.count(99) << std::endl;
// 	std::cout << "SIZE " <<mine.size() << std::endl;
// 	mine.insert(mine2.begin(), mine2.end());

// 	ft::map<int, int>::iterator it = mine.begin();
// 	it++;
// 	it++;
// 	it++;
// 	it++;
// 	it++;
// 	it++;

// 	std::cout << " ERASE OF " << it->first << std::endl;

// 	mine.erase(it);
// 	it++;
// 	// mine.erase(it);


// }

  // third insert function version (range insertion):


// candidate function not viable: no known conversion from
// '     std::pair<iterator, bool>' (aka 'pair<map_iterator<std::less<char>, node<pair<const char, int> >, pair<const char, int> >, bool>') to
// 'const ft::pair<ft::map_iterator<std::less<char>, ft::node<ft::pair<const char, int> >, ft::pair<const char, int> >, bool>' for 1st argument
