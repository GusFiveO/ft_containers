/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_assign_test.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: augustinlorain <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 17:49:22 by augustinlorai     #+#    #+#             */
/*   Updated: 2022/09/30 16:03:54 by augustinlorai    ###   ########.fr       */
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

	NAMESPACE::vector<int> copy_range(vect.begin(), vect.end());

	printInfo(copy_range);
	printContent(copy_range);

	NAMESPACE::vector<int> vect_two;

	vect_two.assign(4, 21);

	printInfo(vect_two);
	printContent(vect_two);

	vect_two.assign(6, 21);

	printInfo(vect_two);
	printContent(vect_two);

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
