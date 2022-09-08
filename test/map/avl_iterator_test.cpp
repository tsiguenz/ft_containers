/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avl_iterator_test.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 15:10:25 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/09/08 15:20:47 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AVL_ITERATOR_TEST_HPP
# define AVL_ITERATOR_TEST_HPP

template<typename ftIterator, typename stdIterator>
void	AVLIteratorTest(ftIterator ftIt, stdIterator stdIt) {
# ifdef REAL
	namespace ft = std;
#endif
	// iterators tests :
	assertEq("Compare iterator value returned by begin()", ftIt->second, stdIt->second);
	assertEq("(*it++).second", (*ftIt++).second, (*stdIt++).second);
	std::cout << "debug\n";
	assertEq("value after post ++", (*ftIt).second, (*stdIt).second);
	assertEq("(*++it).second", (*++ftIt).second, (*++stdIt).second);
	assertEq("(*it--).second", (*ftIt--).second, (*stdIt--).second);
	assertEq("value after post --", (*ftIt).second, (*stdIt).second);
	assertEq("(*--it).second", (*--ftIt).second, (*--stdIt).second);
	ftIterator	tmpFtIt(ftIt);
	stdIterator	tmpStdIt(stdIt);

	int	ctnEqualFt = 0;
	int	ctnEqualStd = 0;
	int	ctnNotEqualFt = 0;
	int	ctnNotEqualStd = 0;

	for (int i = 0; i < 6; i++) {
		ctnEqualFt += (tmpFtIt++ == ftIt++) ? 1 : 0;
		ctnEqualStd += (tmpStdIt++ == stdIt++) ? 1 : 0;
		ctnEqualFt += (tmpFtIt++ != ftIt++) ? 1 : 0;
		ctnEqualStd += (tmpStdIt++ != stdIt++) ? 1 : 0;
	}
	assertEq("compare data in map with ==", ctnEqualFt, ctnEqualStd);
	assertEq("compare data in map with !=", ctnNotEqualFt, ctnNotEqualStd);
			
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
