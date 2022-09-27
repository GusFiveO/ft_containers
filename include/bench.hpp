/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: augustinlorain <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 20:55:31 by augustinlorai     #+#    #+#             */
/*   Updated: 2022/09/27 19:09:52 by alorain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BENCH_HPP
# define BENCH_HPP

#include <ctime>

namespace ft
{
	class Bench
	{
		private:
			clock_t	_ticks;

		public:
			Bench() {this->_ticks = 0;}
			~Bench() {}
			void start(void) {this->_ticks = clock();}
			void displayTime(void) const 
			{
				std::cout << "TIME: " << (static_cast<float>(clock() - this->_ticks) / CLOCKS_PER_SEC ) * 1000 << " ms"<< std::endl;
			}
			void reset(void) {this->_ticks = clock();}
	};
}

#endif
