/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_modifiers_test.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alorain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 17:27:31 by alorain           #+#    #+#             */
/*   Updated: 2022/10/20 17:37:36 by alorain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

#define T1 int
#define T2 std::string

void printPair(NAMESPACE::pair<NAMESPACE::set<T1>::iterator, bool> pr)
{
	std::cout << "first: " << *(pr.first) << ", insered: "<< pr.second << std::endl;
}

void set_modifiers_test()
{
	ft::Bench bench;
	bench.start();

	NAMESPACE::set<T1> mp;
	NAMESPACE::pair<NAMESPACE::set<T1>::iterator, bool> pr;

	std::cout << "---INSERT RET (value_type)" << std::endl;

	pr = mp.insert(1);
	printPair(pr);
	pr = mp.insert(11);
	printPair(pr);
	pr = mp.insert(432);
	printPair(pr);
	pr = mp.insert(12);
	printPair(pr);
	pr = mp.insert(35);
	printPair(pr);
	pr = mp.insert(63);
	printPair(pr);
	pr = mp.insert(78);
	printPair(pr);
	pr = mp.insert(92);
	printPair(pr);

	std::cout << *(mp.insert(mp.begin()++, 5343)) << std::endl;

	std::cout << "---ERASE" << std::endl;


	std::cout << std::boolalpha << mp.erase(92) << std::endl;

	mp.erase(++(++mp.begin()), --mp.end());

	std::cout << "---COUNT" << std::endl;
	std::cout << mp.count(53) << std::endl;
	std::cout << mp.count(63) << std::endl;

	std::cout << "---FIND" << std::endl;

	pr = mp.insert(63);
	std::cout << *(mp.find(63)) << ", " << *(mp.find(63)) << std::endl;

	std::cout << std::boolalpha << (mp.find(1000) == mp.end()) << std::endl;

	


	bench.displayTime();
}
