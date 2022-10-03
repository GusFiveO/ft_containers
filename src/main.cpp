/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: augustinlorain <augustinlorain@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 15:15:13 by alorain           #+#    #+#             */
/*   Updated: 2022/10/03 18:46:27 by alorain          ###   ########.fr       */
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
#include <list>
#include <stack>

//#define TESTED_TYPE int
//
//template <typename Ite_1, typename Ite_2>
//void ft_eq_ope(const Ite_1 &first, const Ite_2 &second, const bool redo = 1)
//{
//	std::cout << (first < second) << std::endl;
//	std::cout << (first <= second) << std::endl;
//	std::cout << (first > second) << std::endl;
//	std::cout << (first >= second) << std::endl;
//	if (redo)
//		ft_eq_ope(second, first, 0);
//}
//
//int		main(void)
//{
//	const int size = 5;
//	NAMESPACE::vector<TESTED_TYPE> vct(size);
//	NAMESPACE::vector<TESTED_TYPE>::reverse_iterator it_0(vct.rbegin());
//	NAMESPACE::vector<TESTED_TYPE>::reverse_iterator it_1(vct.rend());
//	NAMESPACE::vector<TESTED_TYPE>::reverse_iterator it_mid;
//
//	NAMESPACE::vector<TESTED_TYPE>::const_reverse_iterator cit_0 = vct.rbegin();
//	NAMESPACE::vector<TESTED_TYPE>::const_reverse_iterator cit_1;
//	NAMESPACE::vector<TESTED_TYPE>::const_reverse_iterator cit_mid;
//
//	for (int i = size; it_0 != it_1; --i)
//		*it_0++ = i;
//	printInfo(vct);
//	it_0 = vct.rbegin();
//	cit_1 = vct.rend();
//	it_mid = it_0 + 3;
//	cit_mid = it_0 + 3; cit_mid = cit_0 + 3; cit_mid = it_mid;
//
//	std::cout << std::boolalpha;
//	std::cout << ((it_0 + 3 == cit_0 + 3) && (cit_0 + 3 == it_mid)) << std::endl;
//
//	std::cout << "\t\tft_eq_ope:" << std::endl;
//	// regular it
//	ft_eq_ope(it_0 + 3, it_mid);
//	ft_eq_ope(it_0, it_1);
//	ft_eq_ope(it_1 - 3, it_mid);
//	// const it
//	ft_eq_ope(cit_0 + 3, cit_mid);
//	ft_eq_ope(cit_0, cit_1);
//	ft_eq_ope(cit_1 - 3, cit_mid);
//	// both it
//	ft_eq_ope(it_0 + 3, cit_mid);
//	ft_eq_ope(it_mid, cit_0 + 3);
//	ft_eq_ope(it_0, cit_1);
//	ft_eq_ope(it_1, cit_0);
//	ft_eq_ope(it_1 - 3, cit_mid);
//	ft_eq_ope(it_mid, cit_1 - 3);
//
//	return (0);
//}
#define TESTED_TYPE int
#define t_stack_ NAMESPACE::stack<TESTED_TYPE, ft::vector<TESTED_TYPE> >
typedef t_stack_::container_type container_type;

template <class T_STACK>
void	cmp(const T_STACK &lhs, const T_STACK &rhs)
{
	static int i = 0;

	std::cout << "############### [" << i++ << "] ###############"  << std::endl;
	std::cout << "eq: " << (lhs == rhs) << " | ne: " << (lhs != rhs) << std::endl;
	std::cout << "lt: " << (lhs <  rhs) << " | le: " << (lhs <= rhs) << std::endl;
	std::cout << "gt: " << (lhs >  rhs) << " | ge: " << (lhs >= rhs) << std::endl;
}

int		main(void)
{
	container_type vect(6);

	printInfo(vect);
	vect.push_back(3);
	printInfo(vect);




	container_type	ctnr;

	ctnr.push_back(21);
	ctnr.push_back(42);
	ctnr.push_back(1337);
	ctnr.push_back(19);
	ctnr.push_back(0);
	ctnr.push_back(183792);

	t_stack_	stck(ctnr);
	t_stack_	stck2(ctnr);

	cmp(stck, stck);  // 0
	cmp(stck, stck2); // 1

	stck2.push(60);
	stck2.push(61);
	stck2.push(62);

	cmp(stck, stck2); // 2
	cmp(stck2, stck); // 3

	stck.push(42);

	cmp(stck, stck2); // 4
	cmp(stck2, stck); // 5

	stck.push(100);

	cmp(stck, stck2); // 6
	cmp(stck2, stck); // 7
	return (0);
}


//#define TESTED_TYPE int
//
//void	is_empty(NAMESPACE::vector<TESTED_TYPE> const &vct)
//{
//	std::cout << "is_empty: " << vct.empty() << std::endl;
//}
//
//int		main(void)
//{
//
//	const int start_size = 7;
//	NAMESPACE::vector<TESTED_TYPE> vct(start_size, 20);
//	NAMESPACE::vector<TESTED_TYPE> vct2;
//	NAMESPACE::vector<TESTED_TYPE>::iterator it = vct.begin();
//
//	ft::stack<int> s(vct);
//
//	s.push(12);
//
//
//	for (int i = 2; i < start_size; ++i)
//		it[i] = (start_size - i) * 3;
//	printInfo(vct);
//
//	vct.resize(10, 42);
//	printInfo(vct);
//
//	vct.resize(13, 43);
//	printInfo(vct);
//	vct.resize(18, 43);
//	printInfo(vct);
//	vct.resize(10);
//	printInfo(vct);
//	vct.resize(23, 44);
//	printInfo(vct);
//	vct.resize(5);
//	printInfo(vct);
//	vct.reserve(5);
//	vct.reserve(3);
//	printInfo(vct);
//	vct.resize(87);
//	vct.resize(5);
//	printInfo(vct);
//
//	is_empty(vct2);
//	vct2 = vct;
//	is_empty(vct2);
//	vct.reserve(vct.capacity() + 1);
//	printInfo(vct);
//	printInfo(vct2);
//
//	vct2.resize(0);
//	is_empty(vct2);
//	printInfo(vct2);
//	return (0);
//}


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
