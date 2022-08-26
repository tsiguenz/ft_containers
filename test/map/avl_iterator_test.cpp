/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avl_iterator_test.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 15:10:25 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/08/26 17:53:57 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AVL_ITERATOR_TEST_HPP
# define AVL_ITERATOR_TEST_HPP

template<typename ftIterator, typename stdIterator>
void	AVLIteratorTest(ftIterator ftIt, stdIterator stdIt) {
# ifdef REAL
	namespace ft = std;
#endif

//	ftIt += 10;
//	stdIt += 10;
//	assertEq("Compare iterator value returned by begin()", *ftIt, *stdIt);
//	assertEq("*(it++)", *(ftIt++), *(stdIt++));
//	assertEq("*(++it)", *(++ftIt), *(++stdIt));
//	assertEq("*it", *ftIt, *stdIt);
//	assertEq("*(--it)", *(--ftIt), *(--stdIt));
//	assertEq("*(it--)", *(ftIt--), *(stdIt--));
//	assertEq("*it", *ftIt, *stdIt);
//	assertEq("*(it += 3)", *(ftIt += 3), *(stdIt += 3));
//	assertEq("*(it + 2)", *(ftIt + 2), *(stdIt + 2));
//	assertEq("*(it -= 1)", *(ftIt -= 1), *(stdIt -= 1));
//	assertEq("*(it - 2)", *(ftIt - 2), *(stdIt - 2));
//	ftIterator	tmpFtIt(ftIt);
//	stdIterator	tmpStdIt(stdIt);
//	for (int i = -1; i < 2; i++) {
//		std::cout << "i = " << i << std::endl;
//		assertEq("it + i == tmpIt and copy constructor", ftIt + i == tmpFtIt, stdIt + i == tmpStdIt);
//		assertEq("it + i != tmpIt", ftIt + i != tmpFtIt, stdIt + i != tmpStdIt);
//		assertEq("*(it + i)", *(ftIt + i), *(stdIt + i));
//		assertEq("it + i < tmpIt", ftIt + i < tmpFtIt, stdIt + i < tmpStdIt);
//		assertEq("it + i <= tmpIt", ftIt + i <= tmpFtIt, stdIt + i <= tmpStdIt);
//		assertEq("it + i > tmpIt", ftIt + i > tmpFtIt, stdIt + i > tmpStdIt);
//		assertEq("it + i >= tmpIt", ftIt + i >= tmpFtIt, stdIt + i >= tmpStdIt);
//	}
//	tmpFtIt = ftIt + 4;
//	tmpStdIt = stdIt + 4;
//	assertEq("operator = ", *tmpFtIt, *tmpStdIt);
}

#endif // AVL_ITERATOR_TEST_HPP
