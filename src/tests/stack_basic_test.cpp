/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_basic_test.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alorain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 14:22:03 by alorain           #+#    #+#             */
/*   Updated: 2022/10/20 14:49:23 by alorain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tests.hpp>

#define TESTED_TYPE int

void stack_basic_test()
{
	ft::Bench bench;

	std::cout << "\t\tSTACK BASIC TESTS" << std::endl;

	bench.start();

	NAMESPACE::stack<TESTED_TYPE> myStack;

	myStack.push(1);
	myStack.push(2);
	myStack.push(3);
	myStack.push(42);
	myStack.push(-25);

	std::cout << "---TOP" << std::endl << myStack.top() << std::endl;
	std::cout << "---SIZE" << std::endl << myStack.size() << std::endl;
	std::cout << "---EMPTY" << std::endl << myStack.empty() << std::endl;

	NAMESPACE::stack<TESTED_TYPE> myStack2 = myStack;
	
	std::cout << "---OPERATORS" << std::endl << std::boolalpha << (myStack == myStack2) << std::endl;

	myStack.pop();

	std::cout << std::boolalpha << (myStack <= myStack2) << std::endl;
	std::cout << std::boolalpha << (myStack > myStack2) << std::endl;

	myStack.pop();
	myStack.pop();
	myStack.pop();
	myStack.pop();

	std::cout << "---EMPTY" << std::endl << myStack.empty() << std::endl;

	bench.displayTime();
}
