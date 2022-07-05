/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 10:53:55 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/07/05 13:45:11 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

// mandatory
#include <vector>
#include <vector.hpp>
#include <vector>
#include <EnableIf.hpp>

// test
#include <vector_test.hpp>
#include <utils_test.hpp>

int	main() {

	std::cout << VECTOR_ASCII << std::endl;
	tests_numeric<int>();
//	tests_numeric<int const>();
//	tests_numeric<short>();
//	tests_numeric<float>();
//	tests_numeric<double>();
	return 0;
}

