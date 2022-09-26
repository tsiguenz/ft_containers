/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 11:22:37 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/09/26 13:42:27 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

# include <iostream>
# include <list>
# include <vector>
# include <map>

# include "vector.hpp"
# include "map.hpp"
# include "utils_test.hpp"

void	vector_test();
void	vector_object_managment_test();
void	vector_iterator_test();
void	vector_functions_test();
void	vector_operators_test();

void	pair_test();
void	avl_test();
void	map_iterators_test();
void	map_functions_test();
void	map_operators_test();

#endif // TEST_H
