/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_assign_test.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: augustinlorain <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 17:49:22 by augustinlorai     #+#    #+#             */
/*   Updated: 2022/09/26 21:12:01 by augustinlorai    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

void vector_assign_test(void)
{
	ft::Bench bench;

	bench.start();

	std::cout << "\tMY VECTOR:" << std::endl;
	ft::vector<int> vect;
	int tab[5] = {6, 2, 7, 4, 9};

	for (int i = 0; i < 5; i++)
		vect.push_back(tab[i]);

	ft::vector<int> tested;

	tested.assign(vect.begin(), vect.end());

	printContent<int>(tested);

	tested.assign(13, 56);

	printContent(tested);
	printInfo(tested);

	bench.displayTime();

	namespace ft = std;
	
	bench.reset();

	std::cout << std::endl << "\tREAL VECTOR:" << std::endl;

	ft::vector<int> vectR;

	for (int i = 0; i < 5; i++)
		vectR.push_back(tab[i]);

	ft::vector<int> testedR;

	testedR.assign(vectR.begin(), vectR.end());

	printContent(testedR);

	testedR.assign(13, 56);

	printContent(testedR);
	printInfo(testedR);

	bench.displayTime();
}

