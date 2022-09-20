/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_test.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 16:27:59 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/09/20 16:35:32 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include "map.hpp"
#include "utils_test.hpp"
#include "pair_test.cpp"
#include "avl_test.cpp"
#include "avl_iterator_test.cpp"
#include "functions_test.cpp"
#include "operators_test.cpp"

#define FTMAP ft::map<int, int>
#define STDMAP std::map<int, int>

void	map_test() {
# ifdef REAL
	namespace ft = std;
#endif
	avl_test();// TODO comment this line before push, its an internal test
	pair_test();
	avl_iterator_test();
	map_operators_test();
	map_functions_test();
}
