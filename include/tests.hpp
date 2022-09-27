/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: augustinlorain <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 17:50:17 by augustinlorai     #+#    #+#             */
/*   Updated: 2022/09/27 23:01:22 by augustinlorai    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_CONTAINERS_HPP
# define TESTS_CONTAINERS_HPP

# include <vector>
# include <iostream>
# include <string>
# include "vector.hpp"
# include "Iterator.hpp"
# include "testUtils.hpp"
# include "bench.hpp"

# ifndef NAMESPACE
#  define NAMESPACE ft
# endif

//# ifndef OUT_FILE
//#  define OUT_FILE "myVector.output"
//# endif

void vector_assign_test(void);

void vector_assign_operator_test(void);

void vector_resize_test(void);

#endif
