/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_test.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 17:14:11 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/07/29 15:11:37 by tsiguenz         ###   ########.fr       */
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
//			std::cout << LINE << std::endl;
//			std::cout << "======================================= " 
//				<< typeid(T).name() << " ======================================" << std::endl;
//		
//			std::cout << LINE << std::endl;
//		
//			objectManagmentTest<T>();
//		
//			operatorsTest<T>();
//		
//		// iterators tests :
//			{
//				ft::vector<T>	ftV(20);
//				std::vector<T>	stdV(20);
//				for (int i = 0; i < 20; i++) {
//					ftV[i] = (i + 1) * 10;
//					stdV[i] = (i + 1) * 10;
//				}
//				std::cout << "----------  RandomAccessIterator class : ----------" << std::endl;
//				iteratorTest<T, typename ft::vector<T>::iterator, 
//					typename std::vector<T>::iterator> (ftV.begin(), stdV.begin());
//		
//				std::cout << "----------  ConstRandomAccessIterator class : ----------" << std::endl;
//				iteratorTest<T, typename ft::vector<T>::const_iterator,
//					typename std::vector<T>::const_iterator> (ftV.begin(), stdV.begin());
//		
//				std::cout << "----------  ReverseIterator class : ----------" << std::endl;
//				iteratorTest<T, typename ft::vector<T>::reverse_iterator,
//					typename std::vector<T>::reverse_iterator> (ftV.rbegin(), stdV.rbegin());
//		
//				std::cout << "----------  ConstReverseIterator class : ----------" << std::endl;
//				iteratorTest<T, typename ft::vector<T>::const_reverse_iterator,
//					typename std::vector<T>::const_reverse_iterator> (ftV.rbegin(), stdV.rbegin());
//			}
//			functionsTest<T>();

	std::cout << "start MLI" << std::endl;

	const int size = 5;
	typename TESTED_NAMESPACE::vector<TESTED_TYPE> vct(size);
	typename TESTED_NAMESPACE::vector<TESTED_TYPE>::reverse_iterator it = vct.rbegin();
	typename TESTED_NAMESPACE::vector<TESTED_TYPE>::const_reverse_iterator ite = vct.rbegin();

	for (int i = 0; i < size; ++i)
		it[i] = (size - i) * 5;

	printContainer(vct);

	std::cout << "---------- it[0] " << *it << std::endl;
	it = it + 5;
	it = 1 + it;
	std::cout << "---------- test " << *it << std::endl;
	it = it - 4;
	std::cout << "---------- test " << *it << std::endl;
	std::cout << *(it += 2) << std::endl;
	std::cout << *(it -= 1) << std::endl;

	*(it -= 2) = 42;
	*(it += 2) = 21;

	std::cout << "const_ite +=/-=: " << *(ite += 2) << " | " << *(ite -= 2) << std::endl;

	std::cout << "(it == const_it): " << (ite == it) << std::endl;
	std::cout << "(const_ite - it): " << (ite - it) << std::endl;
	std::cout << "(ite + 3 == it): " << (ite + 3 == it) << std::endl;

	std::cout << "end MLI" << std::endl;
}

#endif // VECTOR_TEST_HPP
