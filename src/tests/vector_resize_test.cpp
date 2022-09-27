/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_resize_test.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alorain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 15:36:03 by alorain           #+#    #+#             */
/*   Updated: 2022/09/27 16:36:15 by alorain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

void vector_resize_test(void)
{
	ft::Bench bench;

	std::cout << std::endl << "\t\tRESIZE" << std::endl;
	bench.start();

	NAMESPACE::vector<int> vect;

	int tab[5] = {6, 2, 7, 4, 9};

	for (int i = 0; i < 5; i++)
		vect.push_back(tab[i]);
	
	printInfo(vect);

	vect.resize(10, 63);

	printContent(vect);
	printInfo(vect);
	
	bench.displayTime();
}
