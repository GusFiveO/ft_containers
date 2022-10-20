/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: augustinlorain <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 20:55:31 by augustinlorai     #+#    #+#             */
/*   Updated: 2022/10/20 17:54:39 by alorain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BENCH_HPP
# define BENCH_HPP

# include <ctime>
# include <iostream>

namespace ft
{
	class Bench
	{
		private:
			clock_t	_ticks;

		public:
			Bench();
			~Bench();
			void start(void);
			void displayTime(void) const;
			void reset(void);
	};
}

#endif
