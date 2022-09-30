/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_accesors_test.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alorain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 11:09:24 by alorain           #+#    #+#             */
/*   Updated: 2022/09/30 11:23:13 by alorain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

void vector_accesors_test(void)
{
	NAMESPACE::vector<int> vct(7);

	for (unsigned long int i = 0; i < vct.size(); ++i)
	{
		vct.at(i) = (vct.size() - i) * 3;
		std::cout << "vct[]: " << vct[i] << std::endl;
	}
	printInfo(vct);

	NAMESPACE::vector<int> const vct_c(vct);

	std::cout << "front(): " << vct.front() << " " << vct_c.front() << std::endl;
	std::cout << "back(): " << vct.back() << " " <<  vct_c.back() << std::endl;

	for (unsigned long int i = 0; i < vct_c.size(); ++i)
		std::cout << "vct_c.at(): " << vct_c.at(i) << std::endl;
	try {
		std::cout << vct_c.at(10) << std::endl;
	}
	catch (std::out_of_range &e) {
		std::cout << "Catch out_of_range exception!" << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Catch exception: " << e.what() << std::endl;
	}
	printInfo(vct_c);
	
}
