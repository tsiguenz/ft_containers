/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 17:14:11 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/06/20 18:35:29 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_HPP
# define TEST_HPP

#define DEFAULT "\e[0m"
#define RED "\e[31m"
#define GREEN "\e[32m"

template<typename T>
void	assertEq(std::string str, T a, T b) {
	if (str.empty() == 0)
		std::cout << str << " : " << std::endl;
	if (a != b)
		std::cout << RED << "NOT EQUAL";
	else
		std::cout << GREEN << "EQUAL    ";
	std::cout << " : a = " << a << " b = " << b << DEFAULT << std::endl;

}

#endif
