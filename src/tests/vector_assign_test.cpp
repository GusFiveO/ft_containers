/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_assign_test.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: augustinlorain <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 17:49:22 by augustinlorai     #+#    #+#             */
/*   Updated: 2022/09/27 19:04:42 by alorain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

void vector_assign_test(void)
{
	ft::Bench bench;

	std::cout << std::endl << "\t\tASSIGN" << std::endl;
	bench.start();

	NAMESPACE::vector<int> vect;
	int tab[5] = {6, 2, 7, 4, 9};

	for (int i = 0; i < 5; i++)
		vect.push_back(tab[i]);

	NAMESPACE::vector<int> tested;

	std::cout << "---RESERVE 20" << std::endl;
	tested.reserve(20);

	tested.assign(vect.begin(), vect.end());

	printContent(tested);
	printInfo(tested);

	tested.assign(13, 56);

	printContent(tested);
	printInfo(tested);

	bench.displayTime();
}
