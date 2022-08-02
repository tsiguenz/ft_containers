/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_test.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 17:14:11 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/08/02 23:54:46 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_TEST_HPP
# define VECTOR_TEST_HPP

# define TESTED_NAMESPACE ft
# define TESTED_TYPE	T

# include <list>
# include <vector>

# include <vector.hpp>
# include "utils_test.hpp"
# include "vector/iterator_test.hpp"
# include "vector/object_managment_test.hpp"
# include "vector/functions_test.hpp"
# include "vector/operators_test.hpp"

void	vector_test() {
# ifdef REAL
	namespace ft = std;
#endif
	objectManagmentTest<int>();
	operatorsTest<int>();
	// iterators tests :
	{
		ft::vector<int>	ftV(20);
		std::vector<int>	stdV(20);
		for (int i = 0; i < 20; i++) {
			ftV[i] = (i + 1) * 10;
			stdV[i] = (i + 1) * 10;
		}
		std::cout << "----------  RandomAccessIterator class : ----------" << std::endl;
		iteratorTest<int, ft::vector<int>::iterator, 
			std::vector<int>::iterator> (ftV.begin(), stdV.begin());

		std::cout << "----------  ConstRandomAccessIterator class : ----------" << std::endl;
		iteratorTest<int, ft::vector<int>::const_iterator,
			std::vector<int>::const_iterator> (ftV.begin(), stdV.begin());

		std::cout << "----------  ReverseIterator class : ----------" << std::endl;
		iteratorTest<int, ft::vector<int>::reverse_iterator,
			std::vector<int>::reverse_iterator> (ftV.rbegin(), stdV.rbegin());

		std::cout << "----------  ConstReverseIterator class : ----------" << std::endl;
		iteratorTest<int, ft::vector<int>::const_reverse_iterator,
			std::vector<int>::const_reverse_iterator> (ftV.rbegin(), stdV.rbegin());
	}
	functionsTest<int>();
}

#endif // VECTOR_TEST_HPP
