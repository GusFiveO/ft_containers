/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_modifiers_test.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alorain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 12:13:01 by alorain           #+#    #+#             */
/*   Updated: 2022/10/03 15:23:30 by alorain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

void vector_modifiers_test(void)
{
	ft::Bench bench;


	bench.start();
	std::cout << std::endl << "\t\tMODIFIERS" << std::endl;

	NAMESPACE::vector<int> vect;
	NAMESPACE::vector<int> tested(6);

	std::cout << "---INSERT (on a empty vector)" << std::endl;
	vect.insert(vect.begin(), 42);
	printInfo(tested);
	vect.clear();
	vect.insert(vect.begin(), tested.begin(), tested.end() - 2);

	int tab[7] = {6, 2, 7, 4, 9, 14, 43};

	for (int i = 0; i < 5; i++)
		vect.push_back(tab[i]);

	
	std::cout << "---INSERT (iterators)" << std::endl;
	tested.insert(tested.begin() + 3, vect.begin(), vect.end());
	
	printContent(tested);
	printInfo(tested);

	std::cout << "---INSERT (reverse_iterators)" << std::endl;
	tested.insert(tested.end(), vect.rbegin(), vect.rend());
	
	printContent(tested);
	printInfo(tested);

	std::cout << "---CLEAR" << std::endl;
	tested.clear();

	printInfo(tested);

	std::cout << "---RESIZE (11, 42)" << std::endl;
	tested.resize(11, 42);

	printContent(tested);
	printInfo(tested);

	std::cout << "---INSERT (5, 24)" << std::endl;
	tested.insert(tested.begin() + 5, 5, 24);

	printContent(tested);
	printInfo(tested);

	std::cout << "---ERASE" << std::endl;
	tested.erase(tested.begin(), tested.end() - 13);
	
	printContent(tested);
	printInfo(tested);

	std::cout << "---SWAP" << std::endl;
	tested.swap(vect);


	printContent(tested);
	printContent(vect);
	printInfo(tested);
	printInfo(vect);

	bench.displayTime();
}
