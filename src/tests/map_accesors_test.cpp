/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_accesors_test.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alorain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 14:45:44 by alorain           #+#    #+#             */
/*   Updated: 2022/10/20 17:17:35 by alorain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

#define T1 int
#define T2 std::string


std::string
printPair(NAMESPACE::map<T1, T2>::const_iterator it)
{
	std::cout << "first " << it->first << ", second " << it->second << std::endl;
	return "false";
}

void
printSize(NAMESPACE::map<T1, T2>& Map)
{
	std::cout << "size: " << Map.size() << std::endl;
}

void	ft_find(NAMESPACE::map<T1, T2>& mp, T1 const &k, NAMESPACE::map<T1, T2>::iterator it)
{
	NAMESPACE::map<T1, T2>::iterator ret = mp.find(k);

	if (ret != it)
		printPair(ret);
	else
		std::cout << "map::find(" << k << ") returned end()" << std::endl;
}

void	ft_count(NAMESPACE::map<T1, T2>& mp, T1 const &k)
{
	std::cout << "map::count(" << k << ")\treturned [" << mp.count(k) << "]" << std::endl;
}

void map_accesors_test()
{
	ft::Bench bench;
	bench.start();

	NAMESPACE::map<T1, T2> mp;
	NAMESPACE::map<T1, T2>::iterator it = mp.end();
	std::cout << "\t\tMAP ACCESORS TEST" << std::endl;


	mp[42] = "fgzgxfn";
	mp[25] = "funny";
	mp[80] = "hey";
	mp[12] = "no";
	mp[27] = "bee";
	mp[90] = "8";
	printSize(mp);

	std::cout << "\t-- FIND --" << std::endl;
	ft_find(mp, 12, it);
	ft_find(mp, 3, it);
	ft_find(mp, 35, it);
	ft_find(mp, 90, it);
	ft_find(mp, 100, it);


	std::cout << "\t-- COUNT --" << std::endl;
	ft_count(mp, -3);
	ft_count(mp, 12);
	ft_count(mp, 3);
	ft_count(mp, 35);
	ft_count(mp, 90);
	ft_count(mp, 100);

	mp.find(27)->second = "newly inserted mapped_value";

	printSize(mp);

	NAMESPACE::map<T1, T2> const c_map(mp.begin(), mp.end());
	std::cout << "const map.find(" << 42 << ")->second: [" << c_map.find(42)->second << "]" << std::endl;
	std::cout << "const map.count(" << 80 << "): [" << c_map.count(80) << "]" << std::endl;

	bench.displayTime();
	
}
