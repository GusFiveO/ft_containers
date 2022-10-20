/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_modifiers_test.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alorain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 16:14:39 by alorain           #+#    #+#             */
/*   Updated: 2022/10/20 17:24:59 by alorain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

#define T1 int
#define T2 std::string

void printMapContent(NAMESPACE::map<T1, T2> mp)
{
	for (NAMESPACE::map<T1, T2>::iterator it = mp.begin(); it != mp.end(); it++)
	{
		std::cout << it->first << ", " << it->second;
		if (++it != mp.end())
			std::cout << "; ";
		it--;
	}
	std::cout << std::endl;
	std::cout << "size " << mp.size() << std::endl;
}

void printPair(NAMESPACE::pair<NAMESPACE::map<T1, T2>::iterator, bool> pr)
{
	std::cout << "first: " << pr.first->first << ", second: " << pr.first->second << std::boolalpha << ", insered: "<< pr.second << std::endl;
}

void map_modifiers_test()
{
	ft::Bench bench;
	bench.start();

	NAMESPACE::map<T1, T2> mp;
	NAMESPACE::pair<NAMESPACE::map<T1, T2>::iterator, bool> pr;

	std::cout << "---INSERT RET (value_type)" << std::endl;

	pr = mp.insert(NAMESPACE::make_pair(1, "lol"));
	printPair(pr);
	pr = mp.insert(NAMESPACE::make_pair(11, "lel"));
	printPair(pr);
	pr = mp.insert(NAMESPACE::make_pair(432, "fasl"));
	printPair(pr);
	pr = mp.insert(NAMESPACE::make_pair(12, "gsgdss"));
	printPair(pr);
	pr = mp.insert(NAMESPACE::make_pair(35, "sdaf"));
	printPair(pr);
	pr = mp.insert(NAMESPACE::make_pair(63, "allllo"));
	printPair(pr);
	pr = mp.insert(NAMESPACE::make_pair(78, "aled"));
	printPair(pr);
	pr = mp.insert(NAMESPACE::make_pair(92, "ca va ou pas"));
	printPair(pr);
	pr = mp.insert(NAMESPACE::make_pair(92, "ca va ou pas"));
	printPair(pr);

	std::cout << mp.insert(mp.begin()++, NAMESPACE::make_pair(43, "loliklol"))->first << std::endl;

	std::cout << "---ERASE" << std::endl;

	printMapContent(mp);

	std::cout << std::boolalpha << mp.erase(92) << std::endl;
	printMapContent(mp);

	mp.erase(++(++mp.begin()), --mp.end());
	printMapContent(mp);

	std::cout << "---COUNT" << std::endl;
	std::cout << mp.count(53) << std::endl;
	std::cout << mp.count(63) << std::endl;

	std::cout << "---FIND" << std::endl;

	pr = mp.insert(NAMESPACE::make_pair(63, "allllo"));
	std::cout << mp.find(63)->first << ", " << mp.find(63)->second << std::endl;

	std::cout << std::boolalpha << (mp.find(444444) == mp.end()) << std::endl;

	


	bench.displayTime();
}
