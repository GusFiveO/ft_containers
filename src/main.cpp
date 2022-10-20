/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: augustinlorain <augustinlorain@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 15:15:13 by alorain           #+#    #+#             */
/*   Updated: 2022/10/20 16:26:02 by alorain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "vector.hpp"
#include "stack.hpp"
#include <vector>
#include "Iterator.hpp"
#include "is_integral.hpp"
#include "tests.hpp"
#include "bench.hpp"
#include <iostream>
#include <list>
#include <stack>
#include <map>
#include "map.hpp"
#include "set.hpp"

int main(void)
{

	vector_assign_test();
	vector_assign_operator_test();
	vector_resize_test();
	vector_modifiers_test();
	vector_accesors_test();
	vector_incr_test();
	stack_basic_test();
	map_accesors_test();
	map_modifiers_test();
	return 0;
}
