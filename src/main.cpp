/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alorain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 15:15:13 by alorain           #+#    #+#             */
/*   Updated: 2022/09/23 13:13:31 by alorain          ###   ########.fr       */
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
//
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

#include "Vector.hpp"
#include <vector>
#include "Iterator.hpp"
#include "is_integral.hpp"

int main(void)
{
	std::vector<int> myRVector(0);
	

	myRVector.push_back(1);
	myRVector.push_back(2);
	myRVector.push_back(3);
	myRVector.push_back(4);
	myRVector.push_back(5);
	
	std::cout <<  myRVector.size() << std::endl;
	std::cout <<  myRVector.capacity() << std::endl;

	ft::Vector<int> myVector3(0);

	myVector3.push_back(1);
	myVector3.push_back(2);
	myVector3.push_back(3);
	myVector3.push_back(4);
	myVector3.push_back(5);

	ft::Vector<int>::pointer ptr = myVector3.data();

	std::cout << "*ptr value " << *ptr << std::endl;

	std::cout << "size " <<  myVector3.size() << std::endl;
	std::cout << "capacity " << myVector3.capacity() << std::endl;

	ft::Vector<int> myVector2(myRVector.begin(), myRVector.end());
	std::vector<int> myRVector2(myRVector.begin(), myRVector.end());

	std::cout << "before insert capacity " << myRVector2.capacity() << std::endl;
	std::cout << "before insert size " << myRVector2.size() << std::endl;

	//myRVector2.insert(std::vector<int>::iterator(&myRVector2[1]), 3, 133);

	std::cout << "after insert capacity " << myRVector2.capacity() << std::endl;
	std::cout << "after insert size " << myRVector2.size() << std::endl;

	ft::Vector<int> myVector(myVector2);
	ft::Vector<int> test = myVector2;

	std::cout << "size " << test.size() << std::endl;
	std::cout << "max size " << test.max_size() << std::endl;
	std::cout << "capacity " << test.capacity() << std::endl;

	test.reserve(20);
	test.pop_back();
	test.resize(10, 10);

	std::cout << "back " << test.back() << std::endl;
	std::cout << "front " << test.front() << std::endl;

	std::cout << "size " << test.size() << std::endl;
	std::cout << "capacity " << test.capacity() << std::endl;

	myVector2 = test;
	ft::Vector<int>::iterator tmp;

	std::cout << "before insert size " << myVector2.size() << std::endl;
	std::cout << "before insert capacity " << myVector2.capacity() << std::endl;

	ft::Vector<int>::iterator ret =  myVector2.erase( ft::Vector<int>::iterator(&myVector2[3]), myVector2.end());

	std::cout << std::endl << std::boolalpha << (ret == myVector2.end()) << std::endl << std::endl;

	std::cout << "after insert capacity " << myVector2.capacity() << std::endl;
	std::cout << "after insert size " << myVector2.size() << std::endl;

	for (tmp = myVector2.begin(); tmp != myVector2.end(); tmp++)
		std::cout << *tmp << std::endl;

	std::cout << "capacity " << myVector2.capacity() << std::endl;

	myVector2.clear();

	std::cout << "clear done" << std::endl << std::endl;

	std::cout << "size " << myVector2.size() << std::endl;
	std::cout << "capacity " << myVector2.capacity() << std::endl << std::endl;

	myVector2.push_back(10);

	std::cout << "size " << myVector2.size() << std::endl;
	std::cout << "capacity " << myVector2.capacity() << std::endl;

	for (tmp = myVector2.begin(); tmp != myVector2.end(); tmp++)
		std::cout << *tmp << std::endl;

	std::cout << "REAL VECTOR" << std::endl;

	std::cout << "R capacity " << myRVector2.capacity() << std::endl;

	myRVector2.reserve(20);
	myRVector2.pop_back();
	myRVector2.resize(10, 10);


	std::cout << "R size " << myRVector2.size() << std::endl;
	std::cout << "back " << myRVector2.back() << std::endl;
	std::cout << "front " << myRVector2.front() << std::endl;

	std::cout << "R capacity " << myRVector2.capacity() << std::endl;
	
	myRVector2.erase(std::vector<int>::iterator(&myRVector2[3]), myRVector2.end());

	for (std::vector<int>::iterator tmp2 = myRVector2.begin(); tmp2 != myRVector2.end(); tmp2++)
		std::cout << *tmp2 << std::endl;
	
	try
	{
		myRVector2.at(11);
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		myVector2.at(10);
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
		
	return 0;
}
