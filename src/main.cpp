/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 10:53:55 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/06/29 19:18:50 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <vector.hpp>
#include <vector_test.hpp>
#include <utils_test.hpp>

int	main() {

	std::cout << VECTOR_ASCII << std::endl;
	tests_numeric<short>();
	tests_numeric<int>();
	tests_numeric<float>();
	tests_numeric<double>();
	return 0;
}

