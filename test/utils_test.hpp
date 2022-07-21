/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_test.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 12:36:10 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/07/21 19:29:23 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_TEST_HPP
# define UTILS_TEST_HPP

#define DEFAULT "\e[0m"
#define RED "\e[31m"
#define GREEN "\e[32m"

#define VECTOR_ASCII "  8b           d8 88888888888 ,ad8888ba, 888888888888 ,ad8888ba,   88888888ba \n  `8b         d8' 88         d8\"'    `\"8b     88     d8\"'    `\"8b  88      \"8b\n   `8b       d8'  88        d8'               88    d8'        `8b 88      ,8P\n    `8b     d8'   88aaaaa   88                88    88          88 88aaaaaa8P'\n     `8b   d8'    88\"\"\"\"\"   88                88    88          88 88\"\"\"\"88'  \n      `8b d8'     88        Y8,               88    Y8,        ,8P 88    `8b  \n       `888'      88         Y8a.    .a8P     88     Y8a.    .a8P  88     `8b \n        `8'       88888888888 `\"Y8888Y\"'      88      `\"Y8888Y\"'   88      `8b"
#define LINE "================================================================================" 

template<typename T>
void	assertEq(std::string str, T a, T b) {
	bool	isEq = (a == b);

	if (isEq)
		std::cout << GREEN << "[OK] ";
	else
		std::cout << RED << "[KO] ";
	std::cout << str << " : a = " << a << " b = " << b << DEFAULT << std::endl;

}

template<typename T, typename U>
void	assertEqContainer(std::string const& str, T const& a, U const& b) {
	if (a.size() != b.size()) {
		std::cout << RED << "[KO] " << str << ", different size : a.size() = " << a.size() << " b.size() = " << b.size() << DEFAULT << std::endl;
		return ;
	}
	if (a.empty() != b.empty()) {
		std::cout << RED << "[KO] " << str << ", different empty result : a.empty() = " << a.empty() << " b.empty() = " << b.empty() << DEFAULT << std::endl;
		return ;
	}
	if (a.capacity() != b.capacity()) {
		std::cout << RED << "[KO] " << str << ", different capacity : a.capacity() = " << a.capacity() << " b.capacity() = " << b.capacity() << DEFAULT << std::endl;
		return ;
	}
	if (ft::distance(a.begin(), a.end()) != ft::distance(b.begin(), b.end())) {
		std::cout << RED << "[KO] " << str << ", different distance(begin, end) : a = " << ft::distance(a.begin(), a.end()) << " b = " << ft::distance(b.begin(), b.end()) << DEFAULT << std::endl;
		return ;
	}
	for (int i = 0; i < ft::distance(a.begin(), a.end()); i++) {
		if (a[i] != b[i]) {
			std::cout << RED << "[KO] " << str << ", difference in values : a[" << i << "] = " << a[i] << " b[" << i << "] = " << b[i] << DEFAULT << std::endl;
			return ;
		}
	}
	std::cout << GREEN << "[OK] " << str << DEFAULT << std::endl;
}

template<typename T, typename U>
void	diffContainers(T const& a, U const& b) {
	for (size_t i = 0; i < a.size(); i++)
		std::cout << "a[" << i << "] = " << a[i] << " b[" << i << "] = " << b[i] << std::endl;
	std::cout << "a.size() = " << a.size() << " b.size() = " << b.size() << std::endl;
	std::cout << "a.empty() = " << a.empty() << " b.empty() = " << b.empty() << std::endl;
	std::cout << "a.capacity() = " << a.capacity() << " b.capacity() = " << b.capacity()<< std::endl;
}

template<typename T>
void	printContainer(T const& a) {
	for (size_t i = 0; i < a.size(); i++)
		std::cout << "a[" << i << "] = " << a[i] << std::endl;
	std::cout << "a.size() = " << a.size() << std::endl;
	std::cout << "a.capacity() = " << a.capacity() << std::endl;
	std::cout << "a.empty() = " << a.empty() << std::endl;
}

#endif // UTILS_TEST_HPP
