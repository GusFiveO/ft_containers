/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alorain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 18:05:41 by alorain           #+#    #+#             */
/*   Updated: 2022/10/14 12:24:33 by alorain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

# include "Iterator.hpp"

namespace ft
{
	template<class Iterator>
	typename ft::iterator_traits<Iterator>::difference_type distance(Iterator first, Iterator last)
	{
		typename ft::iterator_traits<Iterator>::difference_type	dist = 0;

		if (first > last)
			return last - first;
		while (first + dist != last)
			dist++;
		return dist;
	}

}

#endif
