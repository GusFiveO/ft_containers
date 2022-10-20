/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alorain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 17:52:01 by alorain           #+#    #+#             */
/*   Updated: 2022/10/20 17:55:42 by alorain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bench.hpp"

namespace ft
{

Bench::Bench()
{
	this->_ticks = 0;
}

Bench::~Bench() {}

void
Bench::start(void) {this->_ticks = clock();}

void 
Bench::displayTime(void) const 
{
	std::cout << "TIME: " << (static_cast<float>(clock() - this->_ticks) / CLOCKS_PER_SEC ) * 1000 << " ms"<< std::endl;
}

void
Bench::reset(void) 
{
	this->_ticks = clock();
}

}
