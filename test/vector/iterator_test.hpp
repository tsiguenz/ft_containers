/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_test.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 19:09:13 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/08/03 16:22:47 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TEST_HPP
# define ITERATOR_TEST_HPP

template<typename T, typename ftIterator, typename stdIterator>
void	iteratorTest(ftIterator ftIt, stdIterator stdIt) {
# ifdef REAL
	namespace ft = std;
#endif
	ftIt += 10;
	stdIt += 10;
	assertEq("Compare iterator value returned by begin()", *ftIt, *stdIt);
	assertEq("*(it++)", *(ftIt++), *(stdIt++));
	assertEq("*(++it)", *(++ftIt), *(++stdIt));
	assertEq("*it", *ftIt, *stdIt);
	assertEq("*(--it)", *(--ftIt), *(--stdIt));
	assertEq("*(it--)", *(ftIt--), *(stdIt--));
	assertEq("*it", *ftIt, *stdIt);
	assertEq("*(it += 3)", *(ftIt += 3), *(stdIt += 3));
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

#endif // ITERATOR_TEST_HPP
