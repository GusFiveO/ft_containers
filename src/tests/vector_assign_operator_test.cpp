/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_assign_operator_test.cpp                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alorain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 14:32:18 by alorain           #+#    #+#             */
/*   Updated: 2022/09/27 16:36:08 by alorain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

void vector_assign_operator_test(void)
{
	ft::Bench bench;

	std::cout << std::endl << "\t\tASSIGN OPERATOR" << std::endl;
	bench.start();

	NAMESPACE::vector<int> vect(4);

	printContent(vect);
	printInfo(vect);

	bench.displayTime();
}
