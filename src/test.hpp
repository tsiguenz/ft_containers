/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 17:14:11 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/06/28 21:32:42 by tsiguenz         ###   ########.fr       */
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

template<typename T>
void	tests_numeric() {
#ifdef REAL
	namespace ft = std;
#endif
	std::cout << "===========================================" << std::endl;
	std::cout << "==================== " << typeid(T).name() << " ====================" << std::endl;
	std::cout << "---------- Default constructor tests : ----------" << std::endl;
	{
		int	ftExceptions = 0;
		int	stdExceptions = 0;
		ft::vector<T>	ftV;
		std::vector<T>	stdV;

		assertEq("data()", ftV.data(), stdV.data());

		try { ftV.at(0); } catch (std::exception const& e) { ftExceptions++; }
		try { stdV.at(0); } catch (std::exception const& e) { stdExceptions++; }

		assertEq("at() exceptions", ftExceptions, stdExceptions);
	}
	std::cout << std::endl;
	std::cout << "----------  Constructor by size tests : ----------" << std::endl;
	{
		ft::vector<T>	ftV(5);
		std::vector<T>	stdV(5);

		ftV[0] = 42;
		stdV[0] = 42;
		assertEq("[] operator", ftV[0], stdV[0]);
		assertEq("[] operator on uninitialise value", ftV[1], stdV[1]);
	}
	std::cout << "----------  Iterators tests : ----------" << std::endl;
	{
		ft::vector<T>	ftV(10);
		std::vector<T>	stdV(10);
		for (int i = 0; i < 10; i++) {
			ftV[i] = (i + 1) * 10;
			stdV[i] = (i + 1) * 10;
		}
		typename ft::vector<T>::iterator	ftIt = ftV.begin();
		typename std::vector<T>::iterator	stdIt = stdV.begin();
		assertEq("Compare iterator value returned by begin()", *ftIt, *stdIt);
		assertEq("it++", *(ftIt++), *(stdIt++));
		assertEq("++it", *(++ftIt), *(++stdIt));
		assertEq("it", *ftIt, *stdIt);
		assertEq("--it", *(--ftIt), *(--stdIt));
		assertEq("it--", *(ftIt--), *(stdIt--));
		assertEq("it", *ftIt, *stdIt);
		//		stdIt = stdV.end() - 1;
		//		ftIt = ftV.end() - 1;
		//		std::cout << *stdIt << std::endl;
		//		std::cout << *ftIt << std::endl;
		assertEq("front", ftV.front(), stdV.front());
		assertEq("back", ftV.back(), stdV.back());
	}
}

#endif
