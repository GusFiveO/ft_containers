/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: augustinlorain <augustinlorain@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 15:15:13 by alorain           #+#    #+#             */
/*   Updated: 2022/10/19 19:18:22 by alorain          ###   ########.fr       */
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
#include "Rb_tree.hpp"
#include <list>
#include <stack>
#include "map.hpp"
#include "set.hpp"

//template <class T>
//void	print(NAMESPACE::set<T>& lst)
//{
//	for (typename NAMESPACE::set<T>::iterator it = lst.begin(); it != lst.end(); it++)
//		std::cout << it->first << " => " << it->second << '\n';
//}
//
//int main ()
//{
//  NAMESPACE::set<int> myset;
//
//  NAMESPACE::set<int>::value_compare mycomp = myset.value_comp();
//
//  for (int i=0; i<=5; i++) myset.insert(i);
//
//  std::cout << "myset contains:";
//
//  int highest=*myset.rbegin();
//  NAMESPACE::set<int>::iterator it=myset.begin();
//  do {
//    std::cout << ' ' << *it;
//  } while ( mycomp(*(++it),highest) );
//
//  std::cout << '\n';
//
//  return 0;
//}

# include <set>

//std::string
//printPair(NAMESPACE::set<T1>::const_iterator it)
//{
//	std::cout << "first " << *it << std::endl;
//	return "false";
//}
//
//void
//printSize(NAMESPACE::set<T1>& S)
//{
//	std::cout << "size: " << S.size() << std::endl;
//}
//
//int		main(void)
//{
//	std::list<T1> lst;
//	unsigned int lst_size = 5;
//	for (unsigned int i = 0; i < lst_size; ++i)
//		lst.push_back(2.5 + i);
//
//	NAMESPACE::set<T1> st(lst.begin(), lst.end());
//	NAMESPACE::set<T1>::iterator it(st.begin());
//	NAMESPACE::set<T1>::const_iterator ite(st.begin());
//	printSize(st);
//
//	printPair(++ite);
//	printPair(ite++);
//	printPair(ite++);
//	printPair(++ite);
//
//	//it->m();
//	//ite->m();
//
//	printPair(++it);
//	printPair(it++);
//	printPair(it++);
//	printPair(++it);
//
//	printPair(--ite);
//	printPair(ite--);
//	printPair(--ite);
//	printPair(ite--);
//
//	//(*it).m();
//	//(*ite).m();
//
//	printPair(--it);
//	printPair(it--);
//	printPair(it--);
//	printPair(--it);
//
//	return (0);
//}

#define T1 int

int		main(void)
{
	NAMESPACE::set<T1> st;

	NAMESPACE::set<T1>::iterator ite = st.begin();
	*ite = 42; // < -- error as well ; T is always const, even with regular iterator
	return (0);
}

//template <class T>
//void	print(NAMESPACE::vector<NAMESPACE::vector<T> >& lst)
//{
//	for (typename NAMESPACE::vector<NAMESPACE::vector<T> >::iterator it = lst.begin(); it != lst.end(); it++)
//	{
//		for (typename NAMESPACE::vector<T>::iterator it2 = it->begin(); it2 != it->end(); it2++)
//			std::cout << *it2 << ' ';
//		std::cout << '\n';
//	}
//}
//
//template <class T>
//void	print(NAMESPACE::vector<T>& lst)
//{
//	for (typename NAMESPACE::vector<T>::iterator it = lst.begin(); it != lst.end(); it++)
//		std::cout << *it << ' ';
//	std::cout << '\n';
//}
//class Awesome {
//
//	public:
//
//		Awesome( void ) : _n( 42 ) { std::cout << "Default constructor" << std::endl; } //should not happen too often or else there is a wrong use of allocator (which calls the copy constructor)
//		Awesome( int n ) : _n( n ) { std::cout << "Int constructor" << std::endl; (void)n; }
//		Awesome( Awesome const &rhs ) : _n( 42 ) { *this = rhs;}
//		virtual ~Awesome(void) {}
//
//		Awesome &operator=( Awesome const & rhs ) { this->_n = rhs._n; return (*this); }
//		bool operator==( Awesome const & rhs ) const { return (this->_n == rhs._n); }
//		bool operator!=( Awesome const & rhs ) const { return (this->_n != rhs._n); }
//		bool operator>( Awesome const & rhs ) const { return (this->_n > rhs._n); }
//		bool operator<( Awesome const & rhs ) const { return (this->_n < rhs._n); }
//		bool operator>=( Awesome const & rhs ) const { return (this->_n >= rhs._n); }
//		bool operator<=( Awesome const & rhs ) const { return (this->_n <= rhs._n); }
//		void operator+=(int rhs){ _n += rhs; }
//		int get( void ) const { return this->_n; }
//
//	private:
//
//		int _n;
//};
//
//std::ostream & operator<<( std::ostream & o, Awesome const & rhs ) { o << rhs.get(); return o; }
//
//template <class T>
//void	print_vector(NAMESPACE::vector<T> &test)
//{
//	typename NAMESPACE::vector<T>::iterator		beg = test.begin();
//	typename NAMESPACE::vector<T>::iterator		end = test.end();
//	std::cout << "size : " << test.size() << ", capacity : " << test.capacity() << std::endl;
//	for (typename NAMESPACE::vector<T>::iterator it = beg; it != end; it++)
//	{
//		std::cout << *it << " ";
//		if (((it - beg) % 10 == 9) && it > beg)
//			std::cout << std::endl;
//	}
//	std::cout << std::endl;
//}
//
//template <class T>
//void	push_pop_back_tests(void)
//{
//	std::cout << std::endl << "PUSH BACK & POP BACK TESTS" << std::endl;
//	NAMESPACE::vector<T> test;
//
//	std::cout << "Empty ? " << test.empty() << " / Capacity : " << test.capacity() << " / Size : " << test.size() << std::endl;
//	for (size_t i = 0; i < 51; i++)
//	{
//		test.push_back(i);
//		std::cout << test.size() << ": " << test.capacity() << " - ";
//		if (!(i % 10) && i != 0)
//			std::cout << std::endl;
//	}
//	print_vector<T>(test);
//	test.pop_back();
//	test.pop_back();
//	test.pop_back();
//	test.pop_back();
//	print_vector<T>(test);
//}
//
//template <class T>
//void	resize_tests(void)
//{
//	std::cout << std::endl << "RESIZE TESTS" << std::endl;
//	NAMESPACE::vector<T> test(12, 12);
//
//	test.resize(72);
//	std::cout << "s: " << test.size() << ", c: " << test.capacity() << std::endl;
//	test.resize(100);
//	std::cout << "s: " << test.size() << ", c: " << test.capacity() << std::endl;
//	test.resize(4170);
//	std::cout << "s: " << test.size() << ", c: " << test.capacity() << std::endl;
//	test.resize(171, 12);
//	std::cout << "s: " << test.size() << ", c: " << test.capacity() << std::endl;
//	test.resize(62);
//	std::cout << "s: " << test.size() << ", c: " << test.capacity() << std::endl;
//}
//
//template <class T>
//void	insert_tests()
//{
//	std::cout << std::endl << "INSERT TESTS" << std::endl;
//	NAMESPACE::vector<T> test(1, 1);
//	NAMESPACE::vector<T> test2(5, 5);
//
//	test.insert(test.begin(), 200, 12);
//	print_vector<T>(test);
//	test.insert(test.begin() + 12, 200, 30);
//	print_vector<T>(test);
//	test.insert(test.end(), 12, 50);
//	print_vector<T>(test);
//	test.insert(test.end() - 1, 0, 60);
//	print_vector<T>(test);
//	test.insert(test.end() - 1, 1, 70);
//	print_vector<T>(test);
//	test.insert(test.begin() + 412, test2.begin(), test2.end());
//	print_vector<T>(test);
//	test.insert(test.begin() + 6, test2.begin(), test2.end());
//	print_vector<T>(test);
//	test.insert(test.end(), test2.begin(), test2.end());
//	print_vector<T>(test);
//}
//
//template <class T>
//void	reserve_tests(void)
//{
//	std::cout << std::endl << "RESERVE TESTS" << std::endl;
//	NAMESPACE::vector<T> test(65, 7);
//	std::cout << "s: " << test.size() << ", c: " << test.capacity() << std::endl;
//	test.reserve(12);
//	std::cout << "s: " << test.size() << ", c: " << test.capacity() << std::endl;
//	test.reserve(66);
//	std::cout << "s: " << test.size() << ", c: " << test.capacity() << std::endl;
//	test.reserve(128);
//	std::cout << "s: " << test.size() << ", c: " << test.capacity() << std::endl;
//	test.reserve(1023);
//	std::cout << "s: " << test.size() << ", c: " << test.capacity() << std::endl;
//	test.reserve(10252);
//	std::cout << "s: " << test.size() << ", c: " << test.capacity() << std::endl;
//	try
//	{
//		test.reserve(test.max_size() + 1);
//	}
//	catch(std::length_error &le)
//	{
//		std::cout << "length error" << std::endl;
//	}
//	catch(std::exception &e)
//	{
//		std::cout << "error : " << e.what() << std::endl;
//	}
//	print_vector<T>(test);
//}
//
//template <class T>
//void	copy_swap_tests(void)
//{
//	std::cout << std::endl << "COPY && SWAP TESTS" << std::endl;
//	NAMESPACE::vector<T> test;
//	for (size_t i = 0; i < 50; i++) { test.push_back(i); }
//	NAMESPACE::vector<T> test_copy(test);
//	for (size_t i = 0; i < test_copy.size(); i++) { test_copy[i] += 100; }
//	print_vector<T>(test_copy);
//	NAMESPACE::vector<T> test_range(test.begin() + 20, test.begin() + 30);
//	print_vector<T>(test_range);
//	test_copy.swap(test);
//	print_vector<T>(test);
//	print_vector<T>(test_copy);
//	test_copy.swap(test_range);
//	print_vector<T>(test_range);
//	print_vector<T>(test_copy);
//	test.swap(test_copy);
//	print_vector<T>(test);
//	print_vector<T>(test_copy);
//}
//
//template <class T>
//void	reverse_it_tests(void)
//{
//	std::cout << std::endl << "REVERSE IT TESTS" << std::endl;
//	NAMESPACE::vector<T> test;
//	for (size_t i = 0; i < 12; i++) { test.push_back(i); }
//	typename NAMESPACE::vector<T>::reverse_iterator		revbeg = test.rbegin();
//	for (typename NAMESPACE::vector<T>::reverse_iterator it = revbeg; it != test.rend(); it++)
//	{
//		std::cout << *it << " ";
//		if (!((revbeg - it) % 10) && it != revbeg)
//			std::cout << std::endl;
//	}
//	std::cout << *(test.rbegin() + 2) << std::endl;
//	std::cout << *(test.rend() - 8) << std::endl;
//	std::cout << (test.rbegin() == revbeg) << std::endl;
//	revbeg++;
//	std::cout << *revbeg << std::endl;
//	std::cout << (test.rbegin() == test.rend()) << std::endl;
//	std::cout << (test.rbegin() <= test.rbegin()) << std::endl;
//	std::cout << (test.rbegin() < test.rend()) << std::endl;
//	std::cout << (test.rbegin() >= test.rend()) << std::endl;
//	revbeg += 3;
//	std::cout << *revbeg << std::endl;
//	std::cout << std::endl;
//}
//
//template <class T>
//void	erase_clear_tests(void)
//{
//	std::cout << std::endl << "ERASE && CLEAR TESTS" << std::endl;
//	NAMESPACE::vector<T> test(31, 12);
//	test.erase(test.begin(), test.begin() + 5);
//	print_vector<T>(test);
//	test.erase(test.begin() + 12, test.begin() + 16);
//	print_vector<T>(test);
//	test.clear();
//	print_vector<T>(test);
//}
//
//void	max_size_tests(void)
//{
//	std::cout << std::endl << "MAX SIZE TESTS" << std::endl;
//	NAMESPACE::vector<int> test(31, 12);
//	NAMESPACE::vector<std::string> test2;
//	NAMESPACE::vector<long long int> test3;
//	NAMESPACE::vector<Awesome> test4;
//	NAMESPACE::vector<unsigned int> test5(12, 340);
//	std::cout << test.max_size() << std::endl;
//	std::cout << test2.max_size() << std::endl;
//	std::cout << test3.max_size() << std::endl;
//	std::cout << test4.max_size() << std::endl;
//	std::cout << test5.max_size() << std::endl;
//}
//
//void	awesome_tests(void)
//{
//	std::cout << std::endl << "AWESOME TESTS" << std::endl;
//	NAMESPACE::vector<Awesome> test(21, 12);
//	print_vector<Awesome>(test);
//	NAMESPACE::vector<Awesome> test2;
//	print_vector<Awesome>(test2);
//	test2.push_back(12);
//	test2.push_back(8);
//	test2.push_back(16);
//	print_vector<Awesome>(test2);
//	std::cout << "SAME ?" << (test.begin() + 1 == test2.begin() + 1) << std::endl;
//	test.assign(test2.begin(), test2.end());
//	print_vector<Awesome>(test);
//	test = test2;
//	print_vector<Awesome>(test);
//	std::cout << "SAME ?" << (test.begin() + 1 == test2.begin() + 1) << std::endl;
//	test.insert(test.end(), test2.begin(), test2.end());
//	print_vector<Awesome>(test);
//	test.insert(test.begin(), test2.begin(), test2.end());
//	test2 = test;
//	print_vector<Awesome>(test);
//	std::cout << "end awesome test" << std::endl;
//}
//
//int main()
//{
//	push_pop_back_tests<int>();
//	resize_tests<int>();
//	insert_tests<int>();
//	reserve_tests<int>();
//	copy_swap_tests<int>();
//	reverse_it_tests<int>();
//	erase_clear_tests<int>();
//	max_size_tests();
//	awesome_tests();
//	push_pop_back_tests<Awesome>();
//	resize_tests<Awesome>();
//	insert_tests<Awesome>();
//	reserve_tests<Awesome>();
//	copy_swap_tests<Awesome>();
//	reverse_it_tests<Awesome>();
//	erase_clear_tests<Awesome>();
//	return 0;
//}
//
//int main(void)
//{
//	ft::Rb_tree<int, int, std::_Identity<int>, std::greater<int> > bst;
//	//ft::Rb_tree<int, ft::pair<int, int>, std::_Select1st<ft::pair<int, int> >, std::less<int> > bst;
//
//	bst.insertBalanced(1);
//	bst.insertBalanced(1);
//	bst.insertBalanced(1);
//	bst.insertBalanced(1);
//	bst.insertBalanced(1);
//	bst.insertBalanced(1);
//	bst.insertBalanced(1);
//	bst.insertBalanced(1);
//
//	bst.insertBalanced(41);
//	bst.insertBalanced(23);
//	bst.insertBalanced(43);
//	bst.insertBalanced(2);
//	bst.insertBalanced(1);
//	bst.insertBalanced(35);
//	bst.insertBalanced(42);
//	bst.insertBalanced(100);
//
//	//bst.insertBalanced(ft::make_pair<int, int>(41, 1));
//	//bst.insertBalanced(ft::make_pair<int, int>(23, 1));
//	//bst.insertBalanced(ft::make_pair<int, int>(43, 1));
//	//bst.insertBalanced(ft::make_pair<int, int>(2, 1));
//	//bst.insertBalanced(ft::make_pair<int, int>(1, 1));
//	//bst.insertBalanced(ft::make_pair<int, int>(35, 1));
//	//bst.insertBalanced(ft::make_pair<int, int>(42, 1));
//	//bst.insertBalanced(ft::make_pair<int, int>(100, 1));
//
//
//	std::cout << "size " << bst.size() << std::endl;
//	bst.displayTree();
//	bst.erase(++bst.begin(), --(--(--bst.end())));
//	//ft::Rb_tree<int, int, std::_Identity<int>, std::less<int> >::iterator it = bst.find(1);
//	std::cout << "size " << bst.size() << std::endl;
//	//std::cout << *(++it) << std::endl; 
//	bst.displayTree();
//	std::cout << bst.size() << std::endl;
//	bst.clear();
//	bst.displayTree();
//	std::cout << "max_size " << bst.max_size() << std::endl;
//	std::cout << "size " << bst.size() << std::endl;
//	return 0;
//
//}

//#include <list>
//
//#define T1 char
//#define T2 int
//typedef ft::pair<const T1, T2> T3;
//
//template <class T>
//void	is_empty(T const &mp)
//{
//	std::cout << "is_empty: " << mp.empty() << std::endl;
//}
//
//void
//printSize(NAMESPACE::map<T1, T2>& Map)
//{
//	std::cout << "size: " << Map.size() << std::endl;
//}
//
//int		main(void)
//{
//	std::list<T3> lst;
//	unsigned int lst_size = 7;
//	for (unsigned int i = 0; i < lst_size; ++i)
//		lst.push_back(T3('a' + i, lst_size - i));
//
//	NAMESPACE::map<T1, T2> mp(lst.begin(), lst.end()), mp2;
//	NAMESPACE::map<T1, T2>::iterator it;
//
//	lst.clear();
//	is_empty(mp);
//	printSize(mp);
//
//	is_empty(mp2);
//	mp2 = mp;
//	is_empty(mp2);
//
//	it = mp.begin();
//	for (unsigned long int i = 3; i < mp.size(); ++i)
//		it++->second = i * 7;
//
//	printSize(mp);
//	printSize(mp2);
//
//	mp2.clear();
//	is_empty(mp2);
//	printSize(mp2);
//	return (0);
//}
//using namespace NAMESPACE;



//template <class T>
//void	print(NAMESPACE::vector<NAMESPACE::vector<T> >& lst)
//{
//	for (typename NAMESPACE::vector<NAMESPACE::vector<T> >::iterator it = lst.begin(); it != lst.end(); it++)
//	{
//		for (typename NAMESPACE::vector<T>::iterator it2 = it->begin(); it2 != it->end(); it2++)
//			std::cout << *it2 << ' ';
//		std::cout << '\n';
//	}
//}
//
//template <class T>
//void	print(NAMESPACE::vector<T>& lst)
//{
//	for (typename NAMESPACE::vector<T>::iterator it = lst.begin(); it != lst.end(); it++)
//		std::cout << *it << ' ';
//	std::cout << '\n';
//}
//
//
//int main ()
//{
//  NAMESPACE::vector<int> myvector (3,100);
//  NAMESPACE::vector<int>::iterator it;
//
//  it = myvector.begin();
//  it = myvector.insert ( it , 200 );
//
//  myvector.insert (it,2,300);
//
//  // "it" no longer valid, get a new one:
//  it = myvector.begin();
//
//  NAMESPACE::vector<int> anothervector (2,400);
//  myvector.insert (it+2,anothervector.begin(),anothervector.end());
//
//  int myarray [] = { 501,502,503 };
//  myvector.insert (myvector.begin(), myarray, myarray+3);
//
//  std::cout << "myvector contains:";
//  for (it=myvector.begin(); it<myvector.end(); it++)
//    std::cout << ' ' << *it;
//  std::cout << '\n';
//
//  return 0;
//}

/*
int main()
{
	NAMESPACE::vector<int>			test(3, 3);

	std::cout << "self assignation test\n";
	NAMESPACE::vector<NAMESPACE::vector<int> >	self_assign;
	NAMESPACE::vector<NAMESPACE::vector<int> >	*ptr = &self_assign;
	NAMESPACE::vector<NAMESPACE::vector<int> >	*ptr2 = &self_assign;

	self_assign.assign(4, test);
	*ptr = *ptr2;

	std::cout << std::boolalpha << (*ptr == *ptr2) << '\n';
//	self_assign = self_assign; //compiler doesn't like it!



	NAMESPACE::vector<NAMESPACE::vector<int> > JOHN;
	NAMESPACE::vector<NAMESPACE::vector<int> > BOB(5, test);
	std::cout << "BOB(5, test(test, 5)) : \n";
	for (size_t i = 0; i < BOB.size(); i++)
	{
		for (size_t j = 0; j < BOB[i].size(); j++)
			std::cout << BOB[i][j] << ' ';
		std::cout << '\n';
	}
	NAMESPACE::vector<NAMESPACE::vector<int> > MIKE(BOB);

	// CTORs
	std::cout << "\nCTORS\n";
	std::cout << "Empty is empty ? " << std::boolalpha << JOHN.empty() << '\n';
	std::cout << "BOB is empty? " << BOB.empty() << '\n';

	std::cout << "Size of JOHN " << JOHN.size() << std::endl;
	std::cout << "Size of BOB " << BOB.size() << std::endl;
	std::cout << "Size of MIKE " << MIKE.size() << std::endl;

	// RESIZE
	size_t	bob_resize = 2;
	std::cout << "\nRESIZE\n";
	BOB.resize(bob_resize);
	std::cout << "Size of JOHN " << JOHN.size() << std::endl;
	if (JOHN.capacity() >= JOHN.size())
		std::cout << "Capacity of JOHN is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 53\n";
	std::cout << "Size of BOB " << BOB.size() << std::endl;
	if (BOB.capacity() >= bob_resize)
		std::cout << "Capacity of BOB is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 58\n";
	std::cout << "Size of MIKE " << MIKE.size() << std::endl;
	if (MIKE.capacity() >= MIKE.size())
		std::cout << "Capacity of MIKE is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 63\n";

	size_t	mike_resize = 9;
	bob_resize = 0;
	
	BOB.resize(bob_resize);
	std::cout << "BOB is empty now ? " << BOB.empty() << '\n';
	MIKE.resize(mike_resize, test);
	std::cout << "Size of JOHN " << JOHN.size() << std::endl;
	if (JOHN.capacity() >= JOHN.size())
		std::cout << "Capacity of JOHN is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 86\n";
	std::cout << "Size of BOB " << BOB.size() << std::endl;
	if (BOB.capacity() >= bob_resize)
		std::cout << "Capacity of BOB is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 91\n";
	std::cout << "Size of MIKE " << MIKE.size() << std::endl;
	if (MIKE.capacity() >= mike_resize)
		std::cout << "Capacity of MIKE is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 96\n";
	for (size_t i = 0; i < MIKE.size(); i++)
	{
		for (size_t j = 0; j < MIKE[i].size(); j++)
		{
			std::cout << MIKE[i][j] << ' ';
		}
	std::cout << std::endl;
	}
	// RESERVE
	std::cout << "\nRESERVE\n";

	size_t	john_reserve = 0;
	size_t	bob_reserve = 3;
	size_t	mike_reserve = 4;

	JOHN.reserve(john_reserve);
	BOB.reserve(bob_reserve);
	MIKE.reserve(mike_reserve);
	std::cout << "Size of JOHN " << JOHN.size() << std::endl;
	if (JOHN.capacity() >= john_reserve)
		std::cout << "Capacity of JOHN is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 120\n";
	std::cout << "Size of BOB " << BOB.size() << std::endl;
	if (BOB.capacity() >= bob_reserve)
		std::cout << "Capacity of BOB is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 125\n";
	std::cout << "Size of MIKE " << MIKE.size() << std::endl;
	if (MIKE.capacity() >= mike_reserve)
		std::cout << "Capacity of MIKE is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 130\n";
	for (size_t i = 0; i < MIKE.size(); i++)
	{
		for (size_t j = 0; j < MIKE[i].size(); j++)
			std::cout << MIKE[i][j] << ' ';
	std::cout << std::endl;
	}

	//AT
	std::cout << "\nAT\n";
	try
	{
		std::cout << MIKE.at(2).front() << '\n';
		std::cout << MIKE.at(87).back() << '\n';
	}
	catch (std::out_of_range& oor)
	{
		(void)oor;
		std::cout << "OOR error caught\n";
	}

	// FRONT / BACK
	std::cout << "\nFRONT / BACK\n";
	std::cout << "front() of MIKE : " << MIKE.front().front() << '\n';
	std::cout << "back() of MIKE : " << MIKE.back().back() << '\n';

	//ASSIGN
	std::cout << "\nASSIGN\n";
	test.assign(3, 17);
	BOB.assign(3, test);

	//ASSIGN RANGE
	std::cout << "\nASSIGN RANGE\n";
	NAMESPACE::vector<NAMESPACE::vector<int> >	assign_range;
	assign_range.assign(8, test);
	assign_range.assign(BOB.begin() + 1, BOB.end() - 2);

	//EMPTY
	std::cout << "\nEMPTY\n";
	std::cout << "BOB is empty ? " << BOB.empty() << '\n';
	std::cout << "BOB at(1) : " << BOB.at(1).front() << '\n';

	//PUSH/POP_BACK
	std::cout << "\nPUSH/POP_BACK\n";
	test.assign(2, 42);
	BOB.push_back(test);
	std::cout << "last elem of BOB : " << BOB.back().back() << '\n';
	BOB.pop_back();
	std::cout << "last elem of BOB : " << BOB.back().back() << '\n';

	//INSERT
	std::cout << "\nINSERT\n";
	NAMESPACE::vector<NAMESPACE::vector<int> >	insert_in_me;
	for (int i = 0; i < 15; i++)
	{
		NAMESPACE::vector<int>	j(2, i);
		insert_in_me.push_back(j);
	}
	for (size_t i = 0; i < insert_in_me.size(); i++)
	{
		for (size_t j = 0; j < insert_in_me.at(i).size(); j++)
			std::cout << insert_in_me.at(i).at(j) << ' ';
		std::cout << '\n';
	}

	NAMESPACE::vector<NAMESPACE::vector<int> >::iterator	tmp;
	test.assign(23, 19);
	tmp = insert_in_me.begin() + 4;
	insert_in_me.insert(tmp, 8, test);
	for (size_t i = 0; i < insert_in_me.size(); i++)
	{
		for (size_t j = 0; j < insert_in_me.at(i).size(); j++)
			std::cout << insert_in_me.at(i).at(j) << ' ';
		std::cout << '\n';
	}

	NAMESPACE::vector<NAMESPACE::vector<int> >::const_iterator const_it(insert_in_me.begin());
	std::cout << "Const it.front() : " << std::endl;
	std::cout << (*const_it).front() << '\n';


	//INSERT
	std::cout << "\nINSERT\n";
	NAMESPACE::vector<NAMESPACE::vector<int> >	std_insert_in_me;
	for (int i = 0; i < 15; i++)
		std_insert_in_me.push_back(test);
	for (size_t i = 0; i < std_insert_in_me.size(); i++)
		std::cout << std_insert_in_me.at(i).front() << ' ';
	std::cout << '\n';

	NAMESPACE::vector<NAMESPACE::vector<int> >::iterator	std_tmp;
	std_tmp = std_insert_in_me.begin() + 4;
	std_insert_in_me.insert(std_tmp, 8, test);
	for (size_t i = 0; i < std_insert_in_me.size(); i++)
		std::cout << std_insert_in_me.at(i).back() << ' ';
	std::cout << '\n';


	//INSERT RANGE
	std::cout << "\nINSERT RANGE\n";
	NAMESPACE::vector<NAMESPACE::vector<int> >	insert_bis;
	for (int i = 0; i < 7; i++)
	{
		NAMESPACE::vector<int>	j(2, i * 3);
		insert_bis.push_back(j);
	}
	for (size_t i = 0; i < insert_bis.size(); i++)
		std::cout << insert_bis[i].back() << ' ';
	std::cout << '\n';

	insert_bis.insert(insert_bis.begin() + 5, insert_in_me.begin(), insert_in_me.end());
	for (size_t i = 0; i < insert_bis.size(); i++)
		std::cout << insert_bis[i].back() << ' ';
	std::cout << '\n';


	//ERASE
	std::cout << "\nERASE\n";
	NAMESPACE::vector<NAMESPACE::vector<int> >	erase_in_me;
	for (int i = 0; i < 15; i++)
	{
		NAMESPACE::vector<int>	j(1, i);
		erase_in_me.push_back(j);
	}
	for (size_t i = 0; i < erase_in_me.size(); i++)
		std::cout << erase_in_me.at(i).front() << ' ';
	std::cout << '\n';

	erase_in_me.erase(erase_in_me.begin() + 7);
	for (size_t i = 0; i < erase_in_me.size(); i++)
		std::cout << erase_in_me.at(i).front() << ' ';
	std::cout << '\n';
	erase_in_me.erase(erase_in_me.begin() + 2, erase_in_me.begin() + 6);
	for (size_t i = 0; i < erase_in_me.size(); i++)
		std::cout << erase_in_me.at(i).front() << ' ';
	std::cout << '\n';

	//SWAP
	std::cout << "\nSWAP\n";
	john_reserve = 4;
	JOHN.reserve(john_reserve);
	BOB.swap(MIKE);
	std::cout << "Size of JOHN " << JOHN.size() << std::endl;
	if (JOHN.capacity() >= JOHN.size())
		std::cout << "Capacity of JOHN is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 272\n";
	std::cout << "Size of BOB " << BOB.size() << std::endl;
	if (BOB.capacity() >= BOB.size())
		std::cout << "Capacity of BOB is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 277\n";
	std::cout << "Size of MIKE " << MIKE.size() << std::endl;
	if (MIKE.capacity() >= MIKE.size())
		std::cout << "Capacity of MIKE is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 282\n";
	for (size_t i = 0; i < MIKE.size(); i++)
	{
		for (size_t j = 0; j < MIKE[i].size(); j++)
			std::cout << MIKE[i][j] << ' ';
	std::cout << std::endl;
	}

	MIKE.swap(JOHN);
	std::cout << "Size of JOHN " << JOHN.size() << std::endl;
	if (JOHN.capacity() >= JOHN.size())
		std::cout << "Capacity of JOHN is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 298\n";
	std::cout << "Size of BOB " << BOB.size() << std::endl;
	if (BOB.capacity() >= BOB.size())
		std::cout << "Capacity of BOB is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 303\n";
	std::cout << "Size of MIKE " << MIKE.size() << std::endl;
	if (MIKE.capacity() >= MIKE.size())
		std::cout << "Capacity of MIKE is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 308\n";
	for (size_t i = 0; i < MIKE.size(); i++)
	{
		for (size_t j = 0; j < MIKE[i].size(); j++)
			std::cout << MIKE[i][j] << ' ';
	std::cout << std::endl;
	}

	//CLEAR
	std::cout << "\nCLEAR\n";
	JOHN.clear();
	MIKE.clear();
	std::cout << "Size of JOHN " << JOHN.size() << std::endl;
	if (JOHN.capacity() >= JOHN.size())
		std::cout << "Capacity of JOHN is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 327\n";
	std::cout << "Size of BOB " << BOB.size() << std::endl;
	if (BOB.capacity() >= BOB.size())
		std::cout << "Capacity of BOB is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 332\n";
	std::cout << "Size of MIKE " << MIKE.size() << std::endl;
	if (MIKE.capacity() >= MIKE.size())
		std::cout << "Capacity of MIKE is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 337\n";
	for (size_t i = 0; i < MIKE.size(); i++)
	{
		for (size_t j = 0; j < MIKE[i].size(); j++)
			std::cout << MIKE[i][j] << ' ';
	std::cout << std::endl;
	}

	//NON MEMBER Functions
	std::cout << "\nNON MEMBER functions\n";
	swap(BOB, MIKE);
	std::cout << "Size of JOHN " << JOHN.size() << std::endl;
	if (JOHN.capacity() >= JOHN.size())
		std::cout << "Capacity of JOHN is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 355\n";
	std::cout << "Size of BOB " << BOB.size() << std::endl;
	if (BOB.capacity() >= BOB.size())
		std::cout << "Capacity of BOB is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 360\n";
	std::cout << "Size of MIKE " << MIKE.size() << std::endl;
	if (MIKE.capacity() >= MIKE.size())
		std::cout << "Capacity of MIKE is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 365\n";
	for (size_t i = 0; i < MIKE.size(); i++)
	{
		for (size_t j = 0; j < MIKE[i].size(); j++)
			std::cout << MIKE[i][j] << ' ';
	std::cout << std::endl;
	}
	
	//RELATIONAL OPERATORS
	std::cout << "\nRELATIONAL OPERATORS\n";
	NAMESPACE::vector<NAMESPACE::vector<int> > MIKE_2(MIKE);
	std::cout << "MIKE and BOB are equal ? " << (MIKE == BOB) << '\n';
	std::cout << "MIKE and MIKE_2 are equal ? " << (MIKE == MIKE_2) << '\n';

	std::cout << "\nReal Vector\n";
	NAMESPACE::vector<NAMESPACE::vector<int> > real;
	real.assign(5, test);
	for (NAMESPACE::vector<NAMESPACE::vector<int> >::iterator it = real.begin(); it != real.end(); it++)
		std::cout << (*it).front() << " ";
	std::cout << '\n';

	std::cout << std::endl;
	return (0);
}*/

//#include <map>
//
//#ifndef STD
//# define NAMESPACE ft
//#else
//# define NAMESPACE std
//#endif
//
//
//template <class Key, class T>
//void	print(NAMESPACE::map<Key, T>& lst)
//{
//	for (typename NAMESPACE::map<Key, T>::iterator it = lst.begin(); it != lst.end(); it++)
//		std::cout << it->first << " => " << it->second << '\n';
//}
//
//int main ()
//{
//  NAMESPACE::map<char,int> mymap;
//  char c;
//
//  mymap ['a']=101;
//  std::cout << "assigned 'a'\n";
//  mymap ['c']=202;
//  std::cout << "assiged 'c'\n";
//  mymap ['f']=303;
//  std::cout << "assigned 'f'\n";
//
//	std::cout << "end of assignations\n";
//  for (c='a'; c<'h'; c++)
//  {
//    std::cout << c;
//    if (mymap.count(c)>0)
//      std::cout << " is an element of mymap.\n";
//    else 
//      std::cout << " is not an element of mymap.\n";
//  }
//
//  return 0;
//}

//template <class Key, class T>
//void	print(NAMESPACE::map<Key, T>& lst)
//{
//	for (typename NAMESPACE::map<Key, T>::iterator it = lst.begin(); it != lst.end(); it++)
//		std::cout << it->first << " => " << it->second << '\n';
//}
//
//int main ()
//{
//  NAMESPACE::map<char,int> foo,bar;
//
//  foo['x']=100;
//  foo['y']=200;
//
//  bar['a']=11;
//  bar['b']=22;
//  bar['c']=33;
//
//
//  NAMESPACE::map<char, int>::const_iterator tmp = foo.begin(); //tmp iterates through foo
//  NAMESPACE::map<char, int>::const_iterator tmp2 = bar.begin(); //tmp2 iterates through bar
//
//
//  NAMESPACE::swap(bar, foo); //tmp iterates through bar
//				//tmp2 iterates through foo
//
//  NAMESPACE::map<char, int>	other;
//
//  other['1'] = 73;
//  other['2'] = 173;
//  other['3'] = 763;
//  other['4'] = 73854;
//  other['5'] = 74683;
//  other['6'] = 753;
//
//  NAMESPACE::map<char, int>::const_iterator tmp3 = other.begin(); // tmp3 iterates through other
//
//  std::cout << "foo contains:\n";
//  for (NAMESPACE::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
//   std:: cout << it->first << " => " << it->second << '\n';
//
//  std::cout << "bar contains:\n";
//  for (NAMESPACE::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
//    std::cout << it->first << " => " << it->second << '\n';
//
//	while(tmp != bar.end())
//	{
//		std::cout << tmp->first << " => " << tmp->second << '\n';
//		tmp++;
//	}
//	tmp--;
//
//	while(tmp2 != foo.end())
//	{
//		std::cout << tmp2->first << " => " << tmp2->second << '\n';
//		tmp2++;
//	}
//	tmp2--;
//
//	swap(other, foo); //tmp2 iterates through other
//					//tmp3 iterates throught foo
//	print(other);
//	print(foo);
//	print(bar);
//	while(tmp != bar.begin())
//	{
//		std::cout << tmp->first << " => " << tmp->second << '\n';
//		tmp--;
//	}
//	std::cout << tmp->first << " => " << tmp->second << '\n';
//
//	while(tmp2 != other.begin())
//	{
//		std::cout << tmp2->first << " => " << tmp2->second << '\n';
//		tmp2--;
//	}
//	std::cout << tmp2->first << " => " << tmp2->second << '\n';
//
//	while(tmp3 != foo.end())
//	{
//		std::cout << tmp3->first << " => " << tmp3->second << '\n';
//		tmp3++;
//	}
//	tmp3--;
//
//	swap(bar, foo);
//	swap(foo, bar);
//	swap(bar, foo); //tmp3 iterates through bar
//				//tmp iterates through foo
//
//	print(other);
//	print(foo);
//	print(bar);
//
//	while(tmp != foo.end())
//	{
//		std::cout << tmp->first << " => " << tmp->second << '\n';
//		tmp++;
//	}
//
//	while(tmp2 != other.end())
//	{
//		std::cout << tmp2->first << " => " << tmp2->second << '\n';
//		tmp2++;
//	}
//
//	while(tmp3 != bar.begin())
//	{
//		std::cout << tmp3->first << " => " << tmp3->second << '\n';
//		tmp3--;
//	}
//	std::cout << tmp3->first << " => " << tmp3->second << '\n';
//}

//#include <list>
//
//#define T1 float
//#define T2 int
//typedef ft::pair<const T1, T2> T3;
//
//std::string
//printPair(NAMESPACE::map<T1, T2>::const_reverse_iterator it)
//{
//	std::cout << "first " << it->first << ", second " << it->second << std::endl;
//	return "false";
//}
//
//void
//printSize(NAMESPACE::map<T1, T2>& Map)
//{
//	std::cout << "size: " << Map.size() << std::endl;
//}
//
//int		main(void)
//{
//	std::list<T3> lst;
//	unsigned int lst_size = 5;
//	for (unsigned int i = 0; i < lst_size; ++i)
//		lst.push_back(T3(2.5 - i, (i + 1) * 7));
//
//	NAMESPACE::map<T1, T2> mp(lst.begin(), lst.end());
//	NAMESPACE::map<T1, T2>::reverse_iterator it(mp.rbegin());
//	NAMESPACE::map<T1, T2>::const_reverse_iterator ite(mp.rbegin());
//	printSize(mp);
//
//	printPair(++ite);
//	printPair(ite++);
//	printPair(ite++);
//	printPair(++ite);
//
//	it->second.m();
//	ite->second.m();
//
//	printPair(++it);
//	printPair(it++);
//	printPair(it++);
//	printPair(++it);
//
//	printPair(--ite);
//	printPair(ite--);
//	printPair(--ite);
//	printPair(ite--);
//
//	(*it).second.m();
//	(*ite).second.m();
//
//	printPair(--it);
//	printPair(it--);
//	printPair(it--);
//	printPair(--it);
//
//	return (0);
//}

//#define T1 int
//#define T2 int
//
//int		main(void)
//{
//	NAMESPACE::map<T1, T2> mp;
//	NAMESPACE::map<T1, T2>::iterator it = mp.begin();
//	NAMESPACE::map<T1, T2>::const_iterator cit = mp.begin();
//
//	NAMESPACE::map<T1, T2>::reverse_iterator rit(it);
//
//	NAMESPACE::map<T1, T2>::const_reverse_iterator crit(rit);
//	NAMESPACE::map<T1, T2>::const_reverse_iterator crit_(it);
//	NAMESPACE::map<T1, T2>::const_reverse_iterator crit_2(cit);
//
//	/* error expected
//	TESTED_NAMESPACE::map<T1, T2>::reverse_iterator rit_(crit);
//	TESTED_NAMESPACE::map<T1, T2>::reverse_iterator rit2(cit);
//	TESTED_NAMESPACE::map<T1, T2>::iterator it2(rit);
//	TESTED_NAMESPACE::map<T1, T2>::const_iterator cit2(crit);
//	*/
//
//	std::cout << "OK" << std::endl;
//	return (0);
//}
// #define T1 char
// #define T2 int
// typedef ft::pair<const T1, T2> T3;
// 
// template <class MAP>
// void    cmp(const MAP &lhs, const MAP &rhs)
// {
//     static int i = 0;
// 
//     std::cout << "############### [" << i++ << "] ###############"  << std::endl;
//     std::cout << "eq: " << (lhs == rhs) << " | ne: " << (lhs != rhs) << std::endl;
//     std::cout << "lt: " << (lhs <  rhs) << " | le: " << (lhs <= rhs) << std::endl;
//     std::cout << "gt: " << (lhs >  rhs) << " | ge: " << (lhs >= rhs) << std::endl;
// }
// 
// int     main(void)
// {
//     NAMESPACE::map<T1, T2> mp1;
//     NAMESPACE::map<T1, T2> mp2;
// 
//     mp1['a'] = 2; mp1['b'] = 3; mp1['c'] = 4; mp1['d'] = 5;
//     mp2['a'] = 2; mp2['b'] = 3; mp2['c'] = 4; mp2['d'] = 5;
// 
//     cmp(mp1, mp1); // 0
//     cmp(mp1, mp2); // 1
// 
//     mp2['e'] = 6; mp2['f'] = 7; mp2['h'] = 8; mp2['h'] = 9;
// 
//     cmp(mp1, mp2); // 2
//     cmp(mp2, mp1); // 3
// 
//     (++(++mp1.begin()))->second = 42;
// 
//     cmp(mp1, mp2); // 4
//     cmp(mp2, mp1); // 5
// 
//     swap(mp1, mp2);
// 
//     cmp(mp1, mp2); // 6
//     cmp(mp2, mp1); // 7
// 
//     return (0);
// }
//#include <map>
//
//#define T1 int
//#define T2 std::string
//
//NAMESPACE::map<T1, T2> mp;
//NAMESPACE::map<T1, T2>::iterator it = mp.end();
//
//std::string
//printPair(NAMESPACE::map<T1, T2>::const_iterator it)
//{
//	std::cout << "first " << it->first << ", second " << it->second << std::endl;
//	return "false";
//}
//
//void
//printSize(NAMESPACE::map<T1, T2>& Map)
//{
//	std::cout << "size: " << Map.size() << std::endl;
//}
//
//void	ft_find(T1 const &k)
//{
//	NAMESPACE::map<T1, T2>::iterator ret = mp.find(k);
//
//	if (ret != it)
//		printPair(ret);
//	else
//		std::cout << "map::find(" << k << ") returned end()" << std::endl;
//}
//
//void	ft_count(T1 const &k)
//{
//	std::cout << "map::count(" << k << ")\treturned [" << mp.count(k) << "]" << std::endl;
//}
//
//int		main(void)
//{
//	mp[42] = "fgzgxfn";
//	mp[25] = "funny";
//	mp[80] = "hey";
//	mp[12] = "no";
//	mp[27] = "bee";
//	mp[90] = "8";
//	printSize(mp);
//
//	std::cout << "\t-- FIND --" << std::endl;
//	ft_find(12);
//	ft_find(3);
//	ft_find(35);
//	ft_find(90);
//	ft_find(100);
//
//
//	std::cout << "\t-- COUNT --" << std::endl;
//	ft_count(-3);
//	ft_count(12);
//	ft_count(3);
//	ft_count(35);
//	ft_count(90);
//	ft_count(100);
//
//	mp.find(27)->second = "newly inserted mapped_value";
//
//	printSize(mp);
//
//	NAMESPACE::map<T1, T2> const c_map(mp.begin(), mp.end());
//	std::cout << "const map.find(" << 42 << ")->second: [" << c_map.find(42)->second << "]" << std::endl;
//	std::cout << "const map.count(" << 80 << "): [" << c_map.count(80) << "]" << std::endl;
//	return (0);
//}

//#include <list>
//
//#define T1 int
//#define T2 int
//
//typedef NAMESPACE::map<T1, T2>::value_type T3;
//typedef NAMESPACE::map<T1, T2>::iterator ft_iterator;
//typedef NAMESPACE::map<T1, T2>::const_iterator ft_const_iterator;
//
//std::string
//printPair(NAMESPACE::map<T1, T2>::const_iterator it, bool b)
//{
//	(void)b;
//	std::cout << "first " << it->first << ", second " << it->second << std::endl;
//	return "false";
//}
//
//static int iter = 0;
//
//template <typename MAP>
//void	ft_bound(MAP &mp, const T1 &param)
//{
//	NAMESPACE::map<T1, T2>::iterator ite = mp.end(), it[2];
//	ft::pair<NAMESPACE::map<T1, T2>::iterator, NAMESPACE::map<T1, T2>::iterator> ft_range;
//
//	std::cout << "\t-- [" << iter++ << "] --" << std::endl;
//	std::cout << "with key [" << param << "]:" << std::endl;
//	it[0] = mp.lower_bound(param); it[1] = mp.upper_bound(param);
//	ft_range = mp.equal_range(param);
//	std::cout << "lower_bound: " << (it[0] == ite ? "end()" : printPair(it[0], false)) << std::endl;
//	std::cout << "upper_bound: " << (it[1] == ite ? "end()" : printPair(it[1], false)) << std::endl;
//	std::cout << "equal_range: " << (ft_range.first == it[0] && ft_range.second == it[1]) << std::endl;
//}
//
//template <typename MAP>
//void	ft_const_bound(const MAP &mp, const T1 &param)
//{
//	NAMESPACE::map<T1, T2>::const_iterator ite = mp.end(), it[2];
//	ft::pair<NAMESPACE::map<T1, T2>::const_iterator, NAMESPACE::map<T1, T2>::const_iterator> ft_range;
//
//	std::cout << "\t-- [" << iter++ << "] (const) --" << std::endl;
//	std::cout << "with key [" << param << "]:" << std::endl;
//	it[0] = mp.lower_bound(param); it[1] = mp.upper_bound(param);
//	ft_range = mp.equal_range(param);
//	std::cout << "lower_bound: " << (it[0] == ite ? "end()" : printPair(it[0], false)) << std::endl;
//	std::cout << "upper_bound: " << (it[1] == ite ? "end()" : printPair(it[1], false)) << std::endl;
//	std::cout << "equal_range: " << (ft_range.first == it[0] && ft_range.second == it[1]) << std::endl;
//}
//
//int		main(void)
//{
//	std::list<T3> lst;
//	unsigned int lst_size = 10;
//	for (unsigned int i = 0; i < lst_size; ++i)
//		lst.push_back(T3(i + 1, (i + 1) * 3));
//	NAMESPACE::map<T1, T2> mp(lst.begin(), lst.end());
//	//printSize(mp);
//
//	ft_const_bound(mp, -10);
//	ft_const_bound(mp, 1);
//	ft_const_bound(mp, 5);
//	ft_const_bound(mp, 10);
//	ft_const_bound(mp, 50);
//
//	//printSize(mp);
//
//	mp.lower_bound(3)->second = 404;
//	mp.upper_bound(7)->second = 842;
//	ft_bound(mp, 5);
//	ft_bound(mp, 7);
//
//	//printSize(mp);
//	return (0);
//}

//#include <map>
//
//int main(void)
//{
//	std::vector<ft::pair<int, int> > vect;
//	vect.push_back(ft::make_pair<int, int>(1, 4)); 
//    vect.push_back(ft::make_pair<int, int>(16, 5));
//	vect.push_back(ft::make_pair<int, int>(4, 5)); 
//	vect.push_back(ft::make_pair<int, int>(2, 4)); 
//	vect.push_back(ft::make_pair<int, int>(3, 4)); 
//    vect.push_back(ft::make_pair<int, int>(64, 5));
//    vect.push_back(ft::make_pair<int, int>(23, 5));
//
//	ft::map<int, int> map1(vect.begin(), vect.end());
//	ft::map<int, int> map2 /*= map1*/;
//	for (std::vector<ft::pair<int, int> >::iterator it = vect.begin(); it != vect.end(); it++)
//	{
//		std::cout << std::_Select1st<ft::pair<int, int> >()(*it) << std::endl;
//	}
//	map1.M_display();
//	map2.M_display();
//	//map2.swap(map1);
//	map2.M_display();
//	map1.M_display();
//	std::cout << "equal_rang"<< std::endl; 
//	std::cout << map1.equal_range(12).first->first << std::endl;
//	for (ft::map<int, int>::iterator itit = map1.equal_range(12).first; itit != map1.equal_range(12).second; itit++)
//		std::cout << itit->first << ", ";
//	std::cout << std::endl;
//
//	map2.M_display();
//	try
//	{
//	std::cout << map2.at(4) << std::endl;
//	std::cout << map2.at(5) << std::endl;
//	}
//	catch(std::out_of_range& oor)
//	{
//		std::cout << oor.what() << std::endl;
//	}
//	for (ft::map<int, int>::iterator it = map2.begin(); it != map2.end(); it++)
//		std::cout << it->second << " ";
//	std::cout << std::endl;
//	return 0;
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
