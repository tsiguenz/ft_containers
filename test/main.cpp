/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 10:53:55 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/09/28 15:30:35 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include "stack/stack_test.cpp"
#include "map/map_test.cpp"

int	main() {
	std::cout << RED << VECTOR_ASCII << LINE << DEFAULT << std::endl;
	vector_test();
	std::cout << RED << STACK_ASCII << LINE << DEFAULT << std::endl;
	stack_test();
	std::cout << RED << MAP_ASCII << LINE << DEFAULT << std::endl;
	map_test();
	return 0;
}
