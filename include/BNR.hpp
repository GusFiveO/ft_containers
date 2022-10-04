/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BNR.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alorain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 18:25:10 by alorain           #+#    #+#             */
/*   Updated: 2022/10/04 18:49:03 by alorain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BNR_HPP
# define BNR_HPP

namespace ft
{

struct base_node
{
	typedef base_node* 			pointer;
	typedef const base_node*	const_pointer;
	
	pointer _parent;
	pointer _right;
	pointer _left;
};

template<typename T>
struct BNR_node : public base_node
{
	typedef BNR_node*	link_type;
	T 					value_field;

};



}

#endif
