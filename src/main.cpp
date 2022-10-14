/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: augustinlorain <augustinlorain@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 15:15:13 by alorain           #+#    #+#             */
/*   Updated: 2022/10/14 15:24:24 by alorain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
//#include <deque>
//#if 1 //CREATE A REAL STL EXAMPLE
//	#include <map>
//	#include <stack>
//	#include <vector>
//	namespace ft = std;
//#else
//	#include <map.hpp>
//	#include <stack.hpp>
//	#include <vector.hpp>
//#endif
//
//#include <stdlib.h>
//
//#define MAX_RAM 4294967296
//#define BUFFER_SIZE 4096
//struct Buffer
//{
//	int idx;
//	char buff[BUFFER_SIZE];
//};
//
//
//#define COUNT (MAX_RAM / (int)sizeof(Buffer))
//
//template<typename T>
//class MutantStack : public ft::stack<T>
//{
//public:
//	MutantStack() {}
//	MutantStack(const MutantStack<T>& src) { *this = src; }
//	MutantStack<T>& operator=(const MutantStack<T>& rhs) 
//	{
//		this->c = rhs.c;
//		return *this;
//	}
//	~MutantStack() {}
//
//	typedef typename ft::stack<T>::container_type::iterator iterator;
//
//	iterator begin() { return this->c.begin(); }
//	iterator end() { return this->c.end(); }
//};
//
//int main(int argc, char** argv) {
//	if (argc != 2)
//	{
//		std::cerr << "Usage: ./test seed" << std::endl;
//		std::cerr << "Provide a seed please" << std::endl;
//		std::cerr << "Count value:" << COUNT << std::endl;
//		return 1;
//	}
//	const int seed = atoi(argv[1]);
//	srand(seed);
//
//	ft::vector<std::string> vector_str;
//	ft::vector<int> vector_int;
//	ft::stack<int> stack_int;
//	ft::vector<Buffer> vector_buffer;
//	ft::stack<Buffer, std::deque<Buffer> > stack_deq_buffer;
//	ft::map<int, int> map_int;

//	for (int i = 0; i < COUNT; i++)
//	{
//		vector_buffer.push_back(Buffer());
//	}
//
//	for (int i = 0; i < COUNT; i++)
//	{
//		const int idx = rand() % COUNT;
//		vector_buffer[idx].idx = 5;
//	}
//	ft::vector<Buffer>().swap(vector_buffer);
//
//	try
//	{
//		for (int i = 0; i < COUNT; i++)
//		{
//			const int idx = rand() % COUNT;
//			vector_buffer.at(idx);
//			std::cerr << "Error: THIS VECTOR SHOULD BE EMPTY!!" <<std::endl;
//		}
//	}
//	catch(const std::exception& e)
//	{
//		//NORMAL ! :P
//	}
//	
//	for (int i = 0; i < COUNT; ++i)
//	{
//		map_int.insert(ft::make_pair(rand(), rand()));
//	}
//
//	int sum = 0;
//	for (int i = 0; i < 10000; i++)
//	{
//		int access = rand();
//		sum += map_int[access];
//	}
//	std::cout << "should be constant with the same seed: " << sum << std::endl;
//
//	{
//		ft::map<int, int> copy = map_int;
//	}
//	MutantStack<char> iterable_stack;
//	for (char letter = 'a'; letter <= 'z'; letter++)
//		iterable_stack.push(letter);
//	for (MutantStack<char>::iterator it = iterable_stack.begin(); it != iterable_stack.end(); it++)
//	{
//		std::cout << *it;
//	}
//	std::cout << std::endl;
//	return (0);
//}

#include "vector.hpp"
#include "stack.hpp"
#include <vector>
#include "Iterator.hpp"
#include "is_integral.hpp"
#include "tests.hpp"
#include "bench.hpp"
#include "BST.hpp"
#include "Rb_tree.hpp"
#include <list>
#include <stack>
#include "map.hpp"

int main(void)
{
	ft::vector<ft::pair<int, int> > vect;
	vect.push_back(ft::make_pair<int, int >(1, 2));
	vect.push_back(ft::make_pair<int, int >(2, 3));
	vect.push_back(ft::make_pair<int, int >(3, 4));
	vect.push_back(ft::make_pair<int, int >(4, 5));
	ft::map<int, int> map1(vect.begin(), vect.end());
	ft::map<int, int> map2 = map1;
	for (ft::vector<ft::pair<int, int> >::iterator it = vect.begin(); it != vect.end(); it++)
	{
		std::cout << std::_Select1st<ft::pair<int, int> >()(*it) << std::endl;
	}
	map1.M_display();
	//ft::pair<ft::map<int, int>::iterator, bool> p = map2.insert(ft::make_pair<int, int>(6, 7));
	//std::cout << "iterator content " << p.first->first << std::boolalpha << "inserted : " << p.second << std::endl;
	ft::map<int, int>::iterator iti = map2.insert(map2.begin(), ft::make_pair<int, int>(6, 7));
	std::cout << "iterator content " << iti->first <<  std::endl;
	map2.M_display();
	map2[5];
	try
	{
	std::cout << map2.at(4) << std::endl;
	std::cout << map2.at(5) << std::endl;
	}
	catch(std::out_of_range& oor)
	{
		std::cout << oor.what() << std::endl;
	}
	for (ft::map<int, int>::iterator it = map2.begin(); it != map2.end(); it++)
		std::cout << it->second << " ";
	std::cout << std::endl;
	return 0;
}

//int main(void)
//{
//
//	vector_assign_test();
//	vector_assign_operator_test();
//	vector_resize_test();
//	vector_modifiers_test();
//	vector_accesors_test();
//	vector_incr_test();
//
//	return 0;
//}
