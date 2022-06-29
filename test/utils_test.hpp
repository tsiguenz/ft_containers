/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_test.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 12:36:10 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/06/29 12:37:52 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_TEST_HPP
# define UTILS_TEST_HPP

#define DEFAULT "\e[0m"
#define RED "\e[31m"
#define GREEN "\e[32m"

#define VECTOR_ASCII "  8b           d8 88888888888 ,ad8888ba, 888888888888 ,ad8888ba,   88888888ba \n  `8b         d8' 88         d8\"'    `\"8b     88     d8\"'    `\"8b  88      \"8b\n   `8b       d8'  88        d8'               88    d8'        `8b 88      ,8P\n    `8b     d8'   88aaaaa   88                88    88          88 88aaaaaa8P'\n     `8b   d8'    88\"\"\"\"\"   88                88    88          88 88\"\"\"\"88'  \n      `8b d8'     88        Y8,               88    Y8,        ,8P 88    `8b  \n       `888'      88         Y8a.    .a8P     88     Y8a.    .a8P  88     `8b \n        `8'       88888888888 `\"Y8888Y\"'      88      `\"Y8888Y\"'   88      `8b"

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

#endif // UTILS_TEST_HPP
