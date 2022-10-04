/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_test.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 13:40:55 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/10/04 16:39:54 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include "iterator_generic_test.hpp"

#define FTMAP ft::map<int, int>
#define STDMAP std::map<int, int>

void	vector_iterator_test() {
# ifdef REAL
	namespace ft = std;
#endif
	ft::vector<int>	ftV(20);
	std::vector<int>	stdV(20);
	for (int i = 0; i < 20; i++) {
		ftV[i] = (i + 1) * 10;
		stdV[i] = (i + 1) * 10;
	}
	std::cout << "----------  RandomAccessIterator class : ----------" << std::endl;
	iteratorTest<ft::vector<int>::iterator, 
		std::vector<int>::iterator> (ftV.begin(), stdV.begin());

	std::cout << "----------  ConstRandomAccessIterator class : ----------" << std::endl;
	iteratorTest<ft::vector<int>::const_iterator,
		std::vector<int>::const_iterator> (ftV.begin(), stdV.begin());

	std::cout << "----------  reverse_iterator class : ----------" << std::endl;
	iteratorTest<ft::vector<int>::reverse_iterator,
		std::vector<int>::reverse_iterator> (ftV.rbegin(), stdV.rbegin());

	std::cout << "----------  const_reverse_iterator class : ----------" << std::endl;
	iteratorTest<ft::vector<int>::const_reverse_iterator,
		std::vector<int>::const_reverse_iterator> (ftV.rbegin(), stdV.rbegin());
}
