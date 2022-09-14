/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_test.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 17:14:11 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/09/14 13:43:50 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list>
#include <vector>

#include "vector.hpp"
#include "utils_test.hpp"
#include "vector/iterator_test.cpp"
#include "vector/object_managment_test.hpp"
#include "vector/functions_test.hpp"
#include "vector/operators_test.hpp"

void	vector_test() {
#ifdef REAL
	namespace ft = std;
#endif
	objectManagmentTest<int>();
	operatorsTest<int>();
	iterator_test();
	functionsTest<int>();
}
