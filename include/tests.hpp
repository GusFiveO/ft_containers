/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: augustinlorain <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 17:50:17 by augustinlorai     #+#    #+#             */
/*   Updated: 2022/10/20 17:44:38 by alorain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_CONTAINERS_HPP
# define TESTS_CONTAINERS_HPP

# include <iostream>
# include <vector>
# include <string>
# include <stack>
# include <map>
# include <set>
# include "vector.hpp"
# include "stack.hpp"
# include "map.hpp"
# include "set.hpp"
# include "Iterator.hpp"
# include "iterator_traits.hpp"
# include "testUtils.hpp"
# include "bench.hpp"

# ifndef NAMESPACE
#  define NAMESPACE ft
# endif

void vector_assign_test(void);

void vector_assign_operator_test(void);

void vector_resize_test(void);

void vector_modifiers_test(void);

void vector_accesors_test(void);

void vector_incr_test(void);

void stack_basic_test(void);

void map_accesors_test(void);

void map_modifiers_test(void);

void set_modifiers_test(void);

#endif
