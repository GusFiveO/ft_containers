/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: augustinlorain <augustinlorain@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 15:15:13 by alorain           #+#    #+#             */
/*   Updated: 2022/10/18 19:31:57 by alorain          ###   ########.fr       */
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
#include <map>
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


#ifndef STD
# define NAMESPACE ft
#else
# define NAMESPACE std
#endif


template <class Key, class T>
void	print(NAMESPACE::map<Key, T>& lst)
{
	std::cout << "printing a map : \n";
	for (typename NAMESPACE::map<Key, T>::iterator it = lst.begin(); it != lst.end(); it++)
		std::cout << it->first << " => " << it->second << '\n';
}

int main()
{
	std::cout << _WHITE << "# test_map" << _END << std::endl;
	std::cout << _YELLOW <<  "/* ********************************************************************** */" << std::endl;
	std::cout << "/*                          "<< _WHITE << "BASIC TESTS" << _YELLOW << "                                   */" << std::endl;
	std::cout << "/* ********************************************************************** */" << _END << std::endl;
	std::cout << std::endl;


	NAMESPACE::map<std::string, int> mymap;
	print(mymap);


	std::cout << "mymap<" << _PURPLE << "std::string" << _END << ", " << _PURPLE << "int" << _END <<"> mymap;" << std::endl;

	std::cout << std::endl;
	std::cout << "mymap.max_size(): " << (mymap.max_size() > 10000) << std::endl;
	print(mymap);
	std::cout << std::endl;


	print(mymap);
	mymap.insert(ft::pair<std::string, int>("ft", 42));

	print(mymap);
	mymap.insert(ft::pair<std::string, int>("one", 1));


	std::cout << _WHITE << "# testing upper/lower_bound" << _END << std::endl;
	NAMESPACE::map<std::string, int>::iterator mit;
	NAMESPACE::map<std::string, int>::iterator it;
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
	NAMESPACE::map<std::string, int> map2;

	print(mymap);
	print(map2);
	std::cout << "mymap<" << _PURPLE << "std::string" << _END << ", " << _PURPLE << "int" << _END <<"> mymap2;" << std::endl;
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
