/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 10:53:55 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/08/03 19:08:02 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector/vector_test.hpp"
#include "stack/stack_test.hpp"
#include "utils_test.hpp"

using namespace ft;
void	test() {
}

int	main() {

	std::cout << RED << VECTOR_ASCII << LINE << DEFAULT << std::endl;
	vector_test();
	std::cout << RED << STACK_ASCII << LINE << DEFAULT << std::endl;
	stack_test();
	std::cout << RED << MAP_ASCII << LINE << DEFAULT << std::endl;
	test();
	return 0;
}
