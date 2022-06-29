/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_test.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 17:14:11 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/06/29 19:19:00 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_VECTOR_HPP
# define TEST_VECTOR_HPP

#include <utils_test.hpp>
#include <random_access_iterator_test.hpp>

template<typename T>
void	tests_numeric() {

#ifdef REAL
	namespace ft = std;
#endif
	std::cout << "================================================================================" << std::endl;
	std::cout << "====================================== " << typeid(T).name() << " =======================================" << std::endl;
	std::cout << "================================================================================" << std::endl;
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
	std::cout << "----------  Object managment : ----------" << std::endl;
	{
		ft::vector<T>	ftV(5);
		std::vector<T>	stdV(5);

		ftV[0] = 42;
		stdV[0] = 42;
		assertEq("[] operator", ftV[0], stdV[0]);
		assertEq("[] operator on uninitialise value", ftV[1], stdV[1]);
	}
	RandomAccessIteratorTest<T>();
//	std::cout << "----------  Member functions tests : ----------" << std::endl;
//	{
//		assertEq("front", ftV.front(), stdV.front());
//		assertEq("back", ftV.back(), stdV.back());
//		stdIt = stdV.end() - 1;
//		ftIt = ftV.end() - 1;
//		std::cout << *stdIt << std::endl;
//		std::cout << *ftIt << std::endl;
//	}
}

#endif // TEST_VECTOR_HPP
