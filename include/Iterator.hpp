# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    iterator.tpp                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alorain <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/13 15:37:01 by alorain           #+#    #+#              #
#    Updated: 2022/09/13 16:36:54 by alorain          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#ifndef ITERATOR_TPP
# define ITERATOR_TPP

namespace ft
{

template<typename T, typename Container>
class iterator
{
	public:
		//MEMBER TYPES
		typedef typename Container::value_type value_type;
		typedef typename Container::difference_type difference_type;
		typedef typename Container::pointer pointer;
		typedef typename Container::reference reference;

		pointer _ptr;

}

}

#endif
