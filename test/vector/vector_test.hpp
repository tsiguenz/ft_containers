/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_test.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 17:14:11 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/06/30 18:35:32 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_VECTOR_HPP
# define TEST_VECTOR_HPP

#include <utils_test.hpp>
#include <random_access_iterator_test.hpp>
#include <default_constructor_test.hpp>
#include <object_managment_test.hpp>

#define CONST true
#define NOT_CONST false

template<typename T>
void	tests_numeric() {
#ifdef REAL
	namespace ft = std;
#endif
	std::cout << LINE << std::endl;
	std::cout 	<< "======================================= " 
				<< typeid(T).name()
				<< " ======================================" << std::endl;
	std::cout << LINE << std::endl;
	defaultConstructorTest<T>();
	objectManagmentTest<T>();
	std::cout << "NON CONST" << std::endl;
	randomAccessIteratorTest
		<T, typename ft::vector<T>::iterator, typename std::vector<T>::iterator>();
	std::cout << "CONST" << std::endl;
	randomAccessIteratorTest
		<T, typename ft::vector<T>::const_iterator, typename std::vector<T>::const_iterator>();

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
