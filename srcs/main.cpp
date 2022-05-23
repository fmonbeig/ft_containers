/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 11:37:09 by fmonbeig          #+#    #+#             */
/*   Updated: 2022/05/23 15:54:13 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "vector.hpp"
#include "stack.hpp"
#include <string>


template <class T>
void	print(ft::vector<ft::vector<T> >& lst)
{
	for (typename ft::vector<ft::vector<T> >::iterator it = lst.begin(); it != lst.end(); it++)
	{
		for (typename ft::vector<T>::iterator it2 = it->begin(); it2 != it->end(); it2++)
			std::cout << *it2 << ' ';
		std::cout << '\n';
	}
}

template <class T>
void	print(ft::vector<T>& lst)
{
	for (typename ft::vector<T>::iterator it = lst.begin(); it != lst.end(); it++)
		std::cout << *it << ' ';
	std::cout << '\n';
}

template <class T>
void	print(std::vector<std::vector<T> >& lst)
{
	for (typename std::vector<std::vector<T> >::iterator it = lst.begin(); it != lst.end(); it++)
	{
		for (typename std::vector<T>::iterator it2 = it->begin(); it2 != it->end(); it2++)
			std::cout << *it2 << ' ';
		std::cout << '\n';
	}
}

template <class T>
void	print(std::vector<T>& lst)
{
	for (typename std::vector<T>::iterator it = lst.begin(); it != lst.end(); it++)
		std::cout << *it << ' ';
	std::cout << '\n';
}



class Awesome {

	public:

		Awesome( void ) : _n( 42 ) { std::cout << "Default constructor" << std::endl; } //should not happen too often or else there is a wrong use of allocator (which calls the copy constructor)
		Awesome( int n ) : _n( n ) { std::cout << "Int constructor" << std::endl; (void)n; }
		Awesome( Awesome const &rhs ) : _n( 42 ) { *this = rhs;}
		virtual ~Awesome(void) {}

		Awesome &operator=( Awesome const & rhs ) { this->_n = rhs._n; return (*this); }
		bool operator==( Awesome const & rhs ) const { return (this->_n == rhs._n); }
		bool operator!=( Awesome const & rhs ) const { return (this->_n != rhs._n); }
		bool operator>( Awesome const & rhs ) const { return (this->_n > rhs._n); }
		bool operator<( Awesome const & rhs ) const { return (this->_n < rhs._n); }
		bool operator>=( Awesome const & rhs ) const { return (this->_n >= rhs._n); }
		bool operator<=( Awesome const & rhs ) const { return (this->_n <= rhs._n); }
		void operator+=(int rhs){ _n += rhs; }
		int get( void ) const { return this->_n; }

	private:

		int _n;
};

std::ostream & operator<<( std::ostream & o, Awesome const & rhs ) { o << rhs.get(); return o; }

template <class T>
void	print_vector(ft::vector<T> &test)
{
	typename ft::vector<T>::iterator		beg = test.begin();
	typename ft::vector<T>::iterator		end = test.end();
	std::cout << "size : " << test.size() << ", capacity : " << test.capacity() << std::endl;
	for (typename ft::vector<T>::iterator it = beg; it != end; it++)
	{
		std::cout << *it << " ";
		if (((it - beg) % 10 == 9) && it > beg)
			std::cout << std::endl;
	}
	std::cout << std::endl;
}

template <class T>
void	print_vector(std::vector<T> &test)
{
	typename std::vector<T>::iterator		beg = test.begin();
	typename std::vector<T>::iterator		end = test.end();
	std::cout << "size : " << test.size() << ", capacity : " << test.capacity() << std::endl;
	for (typename std::vector<T>::iterator it = beg; it != end; it++)
	{
		std::cout << *it << " ";
		if (((it - beg) % 10 == 9) && it > beg)
			std::cout << std::endl;
	}
	std::cout << std::endl;
}

template <class T>
void	push_pop_back_tests(void)
{
	std::cout << std::endl << "PUSH BACK & POP BACK TESTS" << std::endl;
	ft::vector<T> test;

	std::cout << "Empty ? " << test.empty() << " / Capacity : " << test.capacity() << " / Size : " << test.size() << std::endl;
	for (size_t i = 0; i < 51; i++)
	{
		test.push_back(i);
		std::cout << test.size() << ": " << test.capacity() << " - ";
		if (!(i % 10) && i != 0)
			std::cout << std::endl;
	}
	print_vector<T>(test);
	test.pop_back();
	test.pop_back();
	test.pop_back();
	test.pop_back();
	print_vector<T>(test);
}

template <class T>
void	resize_tests(void)
{
	std::cout << std::endl << "RESIZE REAL" << std::endl;
	std::vector<T> REAL(12, 12);

	std::cout << "s: " << REAL.size() << ", c: " << REAL.capacity() << std::endl;
	REAL.resize(72);
	std::cout << "s: " << REAL.size() << ", c: " << REAL.capacity() << std::endl;
	REAL.resize(100);
	std::cout << "s: " << REAL.size() << ", c: " << REAL.capacity() << std::endl;
	REAL.resize(4170);
	std::cout << "s: " << REAL.size() << ", c: " << REAL.capacity() << std::endl;
	REAL.resize(171, 12);
	std::cout << "s: " << REAL.size() << ", c: " << REAL.capacity() << std::endl;
	REAL.resize(62);
	std::cout << "s: " << REAL.size() << ", c: " << REAL.capacity() << std::endl;

	std::cout << std::endl << "RESIZE MINE" << std::endl;
	ft::vector<T> test(12, 12);

	std::cout << "s: " << test.size() << ", c: " << test.capacity() << std::endl;
	test.resize(72);
	std::cout << "s: " << test.size() << ", c: " << test.capacity() << std::endl;
	test.resize(100);
	std::cout << "s: " << test.size() << ", c: " << test.capacity() << std::endl;
	test.resize(4170);
	std::cout << "s: " << test.size() << ", c: " << test.capacity() << std::endl;
	test.resize(171, 12);
	std::cout << "s: " << test.size() << ", c: " << test.capacity() << std::endl;
	test.resize(62);
	std::cout << "s: " << test.size() << ", c: " << test.capacity() << std::endl;


}

template <class T>
void	insert_tests()
{
	std::cout << std::endl << "INSERT TESTS - REAL" << std::endl;
	std::vector<T> test(1, 1);
	std::vector<T> test2(5, 5);

	test.insert(test.begin(), 200, 12);
	// print_vector<T>(test);
	std::cout << test.capacity() << std::endl;
	test.insert(test.begin() + 12, 200, 30);
	// print_vector<T>(test);
	std::cout << test.capacity() << std::endl;
	test.insert(test.end(), 12, 50);
	std::cout << test.capacity() << std::endl;
	// print_vector<T>(test);
	test.insert(test.end() - 1, 0, 60);
	std::cout << test.capacity() << std::endl;
	// print_vector<T>(test);
	test.insert(test.end() - 1, 1, 70);
	std::cout << test.capacity() << std::endl;
	// print_vector<T>(test);
	test.insert(test.begin() + 412, test2.begin(), test2.end());
	std::cout << test.capacity() << std::endl;
	// print_vector<T>(test);
	test.insert(test.begin() + 6, test2.begin(), test2.end());
	std::cout << test.capacity() << std::endl;
	// print_vector<T>(test);
	test.insert(test.end(), test2.begin(), test2.end());
	std::cout << test.capacity() << std::endl;
	// print_vector<T>(test);


	std::cout << std::endl << "INSERT TESTS - MINE" << std::endl;
	ft::vector<T> mine(1, 1);
	ft::vector<T> mine2(5, 5);

	mine.insert(mine.begin(), 200, 12);
	// print_vector<T>(mine);
	std::cout << mine.capacity() << std::endl;
	mine.insert(mine.begin() + 12, 200, 30);
	// print_vector<T>(mine);
	std::cout << mine.capacity() << std::endl;
	mine.insert(mine.end(), 12, 50);
	std::cout << test.capacity() << std::endl;
	// print_vector<T>(mine);
	mine.insert(mine.end() - 1, 0, 60);
	std::cout << test.capacity() << std::endl;
	// print_vector<T>(mine);
	mine.insert(mine.end() - 1, 1, 70);
	std::cout << test.capacity() << std::endl;
	// print_vector<T>(mine);
	mine.insert(mine.begin() + 412, mine2.begin(), mine2.end());
	std::cout << test.capacity() << std::endl;
	// print_vector<T>(mine);
	mine.insert(mine.begin() + 6, mine2.begin(), mine2.end());
	std::cout << test.capacity() << std::endl;
	// print_vector<T>(mine);
	mine.insert(mine.end(), mine2.begin(), mine2.end());
	std::cout << test.capacity() << std::endl;
	// print_vector<T>(mine);
}

template <class T>
void	reserve_tests(void)
{
	std::cout << std::endl << "REAL TESTS" << std::endl;
	std::vector<T> test(65, 7);
	std::cout << "s: " << test.size() << ", c: " << test.capacity() << std::endl;
	test.reserve(12);
	std::cout << "s: " << test.size() << ", c: " << test.capacity() << std::endl;
	test.reserve(66);
	std::cout << "s: " << test.size() << ", c: " << test.capacity() << std::endl;
	test.reserve(128);
	std::cout << "s: " << test.size() << ", c: " << test.capacity() << std::endl;
	test.reserve(1023);
	std::cout << "s: " << test.size() << ", c: " << test.capacity() << std::endl;
	test.reserve(10252);
	std::cout << "s: " << test.size() << ", c: " << test.capacity() << std::endl;
	try
	{
		test.reserve(test.max_size() + 1);
	}
	catch(std::length_error &le)
	{
		std::cout << "length error" << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << "error : " << e.what() << std::endl;
	}
	print(test);

	std::cout << std::endl << "MINE TESTS" << std::endl;
	ft::vector<T> mine(65, 7);
	std::cout << "s: " << mine.size() << ", c: " << mine.capacity() << std::endl;
	mine.reserve(12);
	std::cout << "s: " << mine.size() << ", c: " << mine.capacity() << std::endl;
	mine.reserve(66);
	std::cout << "s: " << mine.size() << ", c: " << mine.capacity() << std::endl;
	mine.reserve(128);
	std::cout << "s: " << mine.size() << ", c: " << mine.capacity() << std::endl;
	mine.reserve(1023);
	std::cout << "s: " << mine.size() << ", c: " << mine.capacity() << std::endl;
	mine.reserve(10252);
	std::cout << "s: " << mine.size() << ", c: " << mine.capacity() << std::endl;
	try
	{
		mine.reserve(mine.max_size() + 1);
	}
	catch(std::length_error &le)
	{
		std::cout << "length error" << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << "error : " << e.what() << std::endl;
	}
	print<T>(mine);
}

template <class T>
void	copy_swap_tests(void)
{
	std::cout << std::endl << "REAL - COPY && SWAP TESTS" << std::endl;
	std::vector<T> test;
	for (size_t i = 0; i < 50; i++) { test.push_back(i); }
	std::vector<T> test_copy(test);
	for (size_t i = 0; i < test_copy.size(); i++) { test_copy[i] += 100; }
	print_vector<T>(test_copy);
	std::vector<T> test_range(test.begin() + 20, test.begin() + 30);
	print_vector<T>(test_range);
	test_copy.swap(test);
	print_vector<T>(test);
	print_vector<T>(test_copy);
	test_copy.swap(test_range);
	print_vector<T>(test_range);
	print_vector<T>(test_copy);
	test.swap(test_copy);
	print_vector<T>(test);
	print_vector<T>(test_copy);


	std::cout << std::endl << "MINE - COPY && SWAP TESTS" << std::endl;
	ft::vector<T> mine;
	for (size_t i = 0; i < 50; i++) { mine.push_back(i); }
	ft::vector<T> mine_copy(mine);
	for (size_t i = 0; i < mine_copy.size(); i++) { mine_copy[i] += 100; }
	print_vector<T>(mine_copy);
	ft::vector<T> mine_range(mine.begin() + 20, mine.begin() + 30);
	print_vector<T>(mine_range);
	mine_copy.swap(mine);
	print_vector<T>(mine);
	print_vector<T>(mine_copy);
	mine_copy.swap(mine_range);
	print_vector<T>(mine_range);
	print_vector<T>(mine_copy);
	mine.swap(mine_copy);
	print_vector<T>(mine);
	print_vector<T>(mine_copy);
}

template <class T>
void	reverse_it_tests(void)
{
	std::cout << std::endl << "REVERSE IT TESTS" << std::endl;
	ft::vector<T> test;
	for (size_t i = 0; i < 12; i++) { test.push_back(i); }
	typename ft::vector<T>::reverse_iterator		revbeg = test.rbegin();
	for (typename ft::vector<T>::reverse_iterator it = revbeg; it != test.rend(); it++)
	{
		std::cout << *it << " ";
		if (!((revbeg - it) % 10) && it != revbeg)
			std::cout << std::endl;
	}
	std::cout << *(test.rbegin() + 2) << std::endl;
	std::cout << *(test.rend() - 8) << std::endl;
	std::cout << (test.rbegin() == revbeg) << std::endl;
	revbeg++;
	std::cout << *revbeg << std::endl;
	std::cout << (test.rbegin() == test.rend()) << std::endl;
	std::cout << (test.rbegin() <= test.rbegin()) << std::endl;
	std::cout << (test.rbegin() < test.rend()) << std::endl;
	std::cout << (test.rbegin() >= test.rend()) << std::endl;
	revbeg += 3;
	std::cout << *revbeg << std::endl;
	std::cout << std::endl;
}

template <class T>
void	erase_clear_tests(void)
{
	std::cout << std::endl << "ERASE && CLEAR TESTS" << std::endl;
	ft::vector<T> test(31, 12);
	test.erase(test.begin(), test.begin() + 5);
	print_vector<T>(test);
	test.erase(test.begin() + 12, test.begin() + 16);
	print_vector<T>(test);
	test.clear();
	print_vector<T>(test);
}

void	max_size_tests(void)
{
	std::cout << std::endl << "MAX SIZE TESTS" << std::endl;
	ft::vector<int> test(31, 12);
	ft::vector<std::string> test2;
	ft::vector<long long int> test3;
	ft::vector<Awesome> test4;
	ft::vector<unsigned int> test5(12, 340);
	std::cout << test.max_size() << std::endl;
	std::cout << test2.max_size() << std::endl;
	std::cout << test3.max_size() << std::endl;
	std::cout << test4.max_size() << std::endl;
	std::cout << test5.max_size() << std::endl;
}

void	awesome_tests(void)
{
	std::cout << std::endl << "AWESOME TESTS" << std::endl;
	ft::vector<Awesome> test(21, 12);
	print_vector<Awesome>(test);
	ft::vector<Awesome> test2;
	print_vector<Awesome>(test2);
	test2.push_back(12);
	test2.push_back(8);
	test2.push_back(16);
	print_vector<Awesome>(test2);
	std::cout << "SAME ?" << (test.begin() + 1 == test2.begin() + 1) << std::endl;
	test.assign(test2.begin(), test2.end());
	print_vector<Awesome>(test);
	test = test2;
	print_vector<Awesome>(test);
	std::cout << "SAME ?" << (test.begin() + 1 == test2.begin() + 1) << std::endl;
	test.insert(test.end(), test2.begin(), test2.end());
	print_vector<Awesome>(test);
	test.insert(test.begin(), test2.begin(), test2.end());
	test2 = test;
	print_vector<Awesome>(test);
	std::cout << "end awesome test" << std::endl;
}

int main()
{
	// push_pop_back_tests<int>();
	// resize_tests<int>();
	// insert_tests<int>();
	// reserve_tests<int>();
	// copy_swap_tests<int>();
	// reverse_it_tests<int>();
	// erase_clear_tests<int>();
	// max_size_tests();
	// awesome_tests();
	// push_pop_back_tests<Awesome>();
	// resize_tests<Awesome>();
	// insert_tests<Awesome>();
	// reserve_tests<Awesome>();
	copy_swap_tests<Awesome>();
	// reverse_it_tests<Awesome>();
	// erase_clear_tests<Awesome>();
}
