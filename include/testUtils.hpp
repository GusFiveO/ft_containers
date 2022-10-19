/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testUtils.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: augustinlorain <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 19:02:28 by augustinlorai     #+#    #+#             */
/*   Updated: 2022/10/19 15:43:31 by alorain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTUTILS_HPP
# define TESTUTILS_HPP

#include "tests.hpp"

template<typename T>
void printContent(ft::vector<T>& vect)
{
	std::cout << "CONTENT: ";
	std::cout << "{";
	for (typename ft::vector<T>::iterator tmp = vect.begin(); tmp != vect.end(); tmp++)
	{
		std::cout << *tmp ;
		if (tmp + 1 != vect.end())
			std::cout << ", ";
	}
	std::cout << "}" << std::endl; 
}

template<typename T>
void printContent(const ft::vector<T>& vect)
{
	std::cout << "CONTENT: ";
	std::cout << "{";
	for (typename ft::vector<T>::iterator tmp = vect.begin(); tmp != vect.end(); tmp++)
	{
		std::cout << *tmp ;
		if (tmp + 1 != vect.end())
			std::cout << ", ";
	}
	std::cout << "}" << std::endl; 
}

template<typename T>
void printContent(std::vector<T>& vect)
{
	std::cout << "CONTENT: ";
	std::cout << "{";
	for (typename std::vector<T>::iterator tmp = vect.begin(); tmp != vect.end(); tmp++)
	{
		std::cout << *tmp ;
		if (tmp + 1 != vect.end())
			std::cout << ", ";
	}
	std::cout << "}" << std::endl; 
}

template<typename T>
void printContent(const std::vector<T>& vect)
{
	std::cout << "CONTENT: ";
	std::cout << "{";
	for (typename std::vector<T>::iterator tmp = vect.begin(); tmp != vect.end(); tmp++)
	{
		std::cout << *tmp ;
		if (tmp + 1 != vect.end())
			std::cout << ", ";
	}
	std::cout << "}" << std::endl; 
}

template<typename T>
void printInfo(ft::vector<T>& vect)
{
	std::cout << "CAPACITY: " << vect.capacity() << std::endl;
	std::cout << "SIZE: " << vect.size() << std::endl;
	std::cout << "MAX_SIZE: " << vect.max_size() << std::endl;
}

template<typename T>
void printInfo(const ft::vector<T>& vect)
{
	std::cout << "CAPACITY: " << vect.capacity() << std::endl;
	std::cout << "SIZE: " << vect.size() << std::endl;
	std::cout << "MAX_SIZE: " << vect.max_size() << std::endl;
}

template<typename T>
void printInfo(std::vector<T>& vect)
{
	std::cout << "CAPACITY: " << vect.capacity() << std::endl;
	std::cout << "SIZE: " << vect.size() << std::endl;
	std::cout << "MAX_SIZE: " << vect.max_size() << std::endl;
}

template<typename T>
void printInfo(const std::vector<T>& vect)
{
	std::cout << "CAPACITY: " << vect.capacity() << std::endl;
	std::cout << "SIZE: " << vect.size() << std::endl;
	std::cout << "MAX_SIZE: " << vect.max_size() << std::endl;
}

#endif
