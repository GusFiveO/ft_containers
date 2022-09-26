/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testUtils.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: augustinlorain <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 19:02:28 by augustinlorai     #+#    #+#             */
/*   Updated: 2022/09/26 19:27:50 by augustinlorai    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTUTILS_HPP
# define TESTUTILS_HPP

#include "tests.hpp"

template<typename T, typename Allocator>
void printContent(ft::vector<T, Allocator>& vect)
{
	std::cout << "CONTENT: ";
	std::cout << "{";
	for (ft::vector<int>::iterator tmp = vect.begin(); tmp != vect.end(); tmp++)
	{
		std::cout << *tmp ;
		if (tmp + 1 != vect.end())
			std::cout << ", ";
	}
	std::cout << "}" << std::endl; 
}

template<typename T, typename Allocator>
void printContent(std::vector<T, Allocator>& vect)
{
	std::cout << "CONTENT: ";
	std::cout << "{";
	for (std::vector<int>::iterator tmp = vect.begin(); tmp != vect.end(); tmp++)
	{
		std::cout << *tmp ;
		if (tmp + 1 != vect.end())
			std::cout << ", ";
	}
	std::cout << "}" << std::endl; 
}

template<typename T, typename Allocator>
void printInfo(ft::vector<T, Allocator>& vect)
{
	std::cout << "CAPACITY: " << vect.capacity() << std::endl;
	std::cout << "SIZE: " << vect.size() << std::endl;
	std::cout << "MAX_SIZE: " << vect.max_size() << std::endl;
}

template<typename T, typename Allocator>
void printInfo(std::vector<T, Allocator>& vect)
{
	std::cout << "CAPACITY: " << vect.capacity() << std::endl;
	std::cout << "SIZE: " << vect.size() << std::endl;
	std::cout << "MAX_SIZE: " << vect.max_size() << std::endl;
}

#endif