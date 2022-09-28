/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_assign_operator_test.cpp                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alorain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 14:32:18 by alorain           #+#    #+#             */
/*   Updated: 2022/09/28 12:18:04 by alorain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

void vector_assign_operator_test(void)
{
	ft::Bench bench;

	std::cout << std::endl << "\t\tASSIGN OPERATOR" << std::endl;
	bench.start();

	NAMESPACE::vector<int> vect(4);
	NAMESPACE::vector<int> tested = vect;

	printContent(vect);
	printInfo(vect);

	printContent(tested);
	printInfo(tested);

	bench.displayTime();
}
