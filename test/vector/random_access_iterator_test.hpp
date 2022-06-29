/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator_test.hpp                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 19:09:13 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/06/29 19:14:46 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_ACCESS_ITERATOR_TEST_HPP
# define RANDOM_ACCESS_ITERATOR_TEST_HPP

template<typename T>
void	RandomAccessIteratorTest() {
	std::cout << "----------  RandomAccessIterator class : ----------" << std::endl;
	ft::vector<T>	ftV(10);
	std::vector<T>	stdV(10);
	for (int i = 0; i < 10; i++) {
		ftV[i] = (i + 1) * 10;
		stdV[i] = (i + 1) * 10;
	}
	typename ft::vector<T>::iterator	ftIt = ftV.begin();
	typename std::vector<T>::iterator	stdIt = stdV.begin();
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
	typename ft::vector<T>::iterator	tmpFtIt(ftIt);
	typename std::vector<T>::iterator	tmpStdIt(stdIt);
	assertEq("it == tmpIt and copy constructor", ftIt == tmpFtIt, stdIt == tmpStdIt);
	assertEq("it + 1 == tmpIt", ftIt + 1 == tmpFtIt, stdIt + 1 == tmpStdIt);
	assertEq("it != tmpIt", ftIt != tmpFtIt, stdIt != tmpStdIt);
	assertEq("it + 1 != tmpIt", ftIt + 1 != tmpFtIt, stdIt + 1 != tmpStdIt);
	for (int i = -1; i < 2; i++) {
		std::cout << "i = " << i << std::endl;
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
