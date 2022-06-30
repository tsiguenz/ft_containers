/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator_test.hpp                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 19:09:13 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/06/30 18:36:32 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_ACCESS_ITERATOR_TEST_HPP
# define RANDOM_ACCESS_ITERATOR_TEST_HPP

template<typename T, typename ftIterator, typename stdIterator>
void	randomAccessIteratorTest() {
#ifdef REAL
	namespace ft = std;
#endif
	std::cout << "----------  RandomAccessIterator class : ----------" << std::endl;
	ft::vector<T>	ftV(10);
	std::vector<T>	stdV(10);
	for (int i = 0; i < 10; i++) {
		ftV[i] = (i + 1) * 10;
		stdV[i] = (i + 1) * 10;
	}
	ftIterator	ftIt = ftV.begin();
	stdIterator	stdIt = stdV.begin();
	std::cout << *ftIt << std::endl;
	assertEq("Compare iterator value returned by begin()", *ftIt, *stdIt);
	assertEq("Compare iterator value returned by end() -1", *(ftV.end() - 1), *(stdV.end() - 1));
	assertEq("*(it++)", *(ftIt++), *(stdIt++));
	assertEq("*(++it)", *(++ftIt), *(++stdIt));
	assertEq("*it", *ftIt, *stdIt);
	assertEq("*(--it)", *(--ftIt), *(--stdIt));
	assertEq("*(it--)", *(ftIt--), *(stdIt--));
	assertEq("*it", *ftIt, *stdIt);
	assertEq("*(it += 5)", *(ftIt += 5), *(stdIt += 5));
	assertEq("*(it + 2)", *(ftIt + 2), *(stdIt + 2));
	assertEq("*(it -= 1)", *(ftIt -= 1), *(stdIt -= 1));
	assertEq("*(it - 2)", *(ftIt - 2), *(stdIt - 2));
	ftIterator	tmpFtIt(ftIt);
	stdIterator	tmpStdIt(stdIt);
	for (int i = -1; i < 2; i++) {
		std::cout << "i = " << i << std::endl;
		assertEq("it + i == tmpIt and copy constructor", ftIt + i == tmpFtIt, stdIt + i == tmpStdIt);
		assertEq("it + i != tmpIt", ftIt + i != tmpFtIt, stdIt + i != tmpStdIt);
		assertEq("*(it + i)", *(ftIt + i), *(stdIt + i));
		assertEq("it + i < tmpIt", ftIt + i < tmpFtIt, stdIt + i < tmpStdIt);
		assertEq("it + i <= tmpIt", ftIt + i <= tmpFtIt, stdIt + i <= tmpStdIt);
		assertEq("it + i > tmpIt", ftIt + i > tmpFtIt, stdIt + i > tmpStdIt);
		assertEq("it + i >= tmpIt", ftIt + i >= tmpFtIt, stdIt + i >= tmpStdIt);
	}
	tmpFtIt = ftIt + 4;
	tmpStdIt = stdIt + 4;
	assertEq("operator = ", *tmpFtIt, *tmpStdIt);
}

#endif // RANDOM_ACCESS_ITERATOR_TEST_HPP
