/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: augustinlorain <augustinlorain@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 15:15:13 by alorain           #+#    #+#             */
/*   Updated: 2022/09/27 16:35:34 by alorain          ###   ########.fr       */
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

#include "vector.hpp"
#include <vector>
#include "Iterator.hpp"
#include "is_integral.hpp"
#include "tests.hpp"
#include "bench.hpp"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

//#define TESTED_TYPE int
//#define TESTED_NAMESPACE ft
//
//int     main(void)
//{
//    TESTED_NAMESPACE::vector<TESTED_TYPE> vct(7);
//    TESTED_NAMESPACE::vector<TESTED_TYPE> vct_two(4);
//    TESTED_NAMESPACE::vector<TESTED_TYPE> vct_three;
//    TESTED_NAMESPACE::vector<TESTED_TYPE> vct_four;
//
//    for (unsigned long int i = 0; i < vct.size(); ++i)
//        vct[i] = (vct.size() - i) * 3;
//    for (unsigned long int i = 0; i < vct_two.size(); ++i)
//        vct_two[i] = (vct_two.size() - i) * 5;
//    printInfo(vct);
//    printInfo(vct_two);
//
//    vct_three.assign(vct.begin(), vct.end());
//    vct.assign(vct_two.begin(), vct_two.end());
//    vct_two.assign(2, 42);
//    vct_four.assign(4, 21);
//
//    std::cout << "\t### After assign(): ###" << std::endl;
//
//    printInfo(vct);
//    printInfo(vct_two);
//    printInfo(vct_three);
//    printInfo(vct_four);
//
//    vct_four.assign(6, 84);
//    printInfo(vct_four);
//
//    std::cout << "\t### assign() on enough capacity and low size: ###" << std::endl;
//
//    vct.assign(5, 53);
//    vct_two.assign(vct_three.begin(), vct_three.begin() + 3);
//
//    printInfo(vct);
//    printContent(vct);
//    printInfo(vct_two);
//    printContent(vct_two);
//
//    return (0);
//}


int main(void)
{

	int save_stdout = dup(STDOUT_FILENO);
	int fd = open(OUT_FILE, O_RDWR | O_CREAT, 0666);

	dup2(fd,STDOUT_FILENO);
	vector_assign_test();
	vector_assign_operator_test();
	vector_resize_test();

	//namespace ft = std;

	//fd = open("realVector.output", O_RDWR | O_CREAT, 0666);

	//close(STDOUT_FILENO);
	//dup2(fd,STDOUT_FILENO);
	//vector_assign_test();
	//vector_assign_operator_test();
	//vector_resize_test();

	//close(STDOUT_FILENO);
	dup2(save_stdout, STDOUT_FILENO);
	return 0;
}
