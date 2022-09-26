/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_assign_test.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: augustinlorain <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 17:49:22 by augustinlorai     #+#    #+#             */
/*   Updated: 2022/09/26 19:33:15 by augustinlorai    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

void vector_assign_test(void)
{
	std::cout << "\tMY VECTOR:" << std::endl;
	ft::vector<int> vect;
	int tab[5] = {6, 2, 7, 4, 9};

	for (int i = 0; i < 5; i++)
		vect.push_back(tab[i]);

	ft::vector<int> tested;

	tested.assign(vect.begin(), vect.end());

	printContent<int>(tested);

	tested.assign(13, 56);

	printContent<int>(tested);
	printInfo<int>(tested);

	namespace ft = std;

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
}

