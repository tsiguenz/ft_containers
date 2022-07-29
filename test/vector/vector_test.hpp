/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_test.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 17:14:11 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/07/29 16:19:30 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_TEST_HPP
# define VECTOR_TEST_HPP

#define TESTED_NAMESPACE ft
#define TESTED_TYPE	T
#include <list>

#include <utils_test.hpp>
#include <iterator_test.hpp>
#include <object_managment_test.hpp>
#include <functions_test.hpp>
#include <operators_test.hpp>

template<typename T>
void	tests_numeric() {
#ifdef REAL
	namespace ft = std;
#endif
			std::cout << LINE << std::endl;
			std::cout << "======================================= " 
				<< typeid(T).name() << " ======================================" << std::endl;
		
			std::cout << LINE << std::endl;
		
			objectManagmentTest<T>();
		
			operatorsTest<T>();
		
		// iterators tests :
			{
				ft::vector<T>	ftV(20);
				std::vector<T>	stdV(20);
				for (int i = 0; i < 20; i++) {
					ftV[i] = (i + 1) * 10;
					stdV[i] = (i + 1) * 10;
				}
				std::cout << "----------  RandomAccessIterator class : ----------" << std::endl;
				iteratorTest<T, typename ft::vector<T>::iterator, 
					typename std::vector<T>::iterator> (ftV.begin(), stdV.begin());
		
				std::cout << "----------  ConstRandomAccessIterator class : ----------" << std::endl;
				iteratorTest<T, typename ft::vector<T>::const_iterator,
					typename std::vector<T>::const_iterator> (ftV.begin(), stdV.begin());
		
				std::cout << "----------  ReverseIterator class : ----------" << std::endl;
				iteratorTest<T, typename ft::vector<T>::reverse_iterator,
					typename std::vector<T>::reverse_iterator> (ftV.rbegin(), stdV.rbegin());
		
				std::cout << "----------  ConstReverseIterator class : ----------" << std::endl;
				iteratorTest<T, typename ft::vector<T>::const_reverse_iterator,
					typename std::vector<T>::const_reverse_iterator> (ftV.rbegin(), stdV.rbegin());
			}
			functionsTest<T>();
}

#endif // VECTOR_TEST_HPP
