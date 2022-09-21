/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_test.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 16:27:59 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/09/21 16:08:02 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

#define FTMAP ft::map<int, int>
#define STDMAP std::map<int, int>

void	map_test() {
# ifdef REAL
	namespace ft = std;
#endif
	pair_test();
	avl_test();
	map_iterators_test();
	map_operators_test();
	map_functions_test();
}
