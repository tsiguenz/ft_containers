/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avl_iterator_test.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 15:10:25 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/09/09 18:12:08 by tsiguenz         ###   ########.fr       */
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
	ftIterator	tmpFtIt(ftIt);
	stdIterator	tmpStdIt(stdIt);
	int			ctnNotEqualValue = 0;
	int			ctnEqualFt = 0;
	int			ctnEqualStd = 0;
	int			ctnNotEqualFt = 0;
	int			ctnNotEqualStd = 0;

	assertEq("Compare iterator value returned by begin()", ftIt->second, stdIt->second);
	assertEq("(*it++).second", (*ftIt++).second, (*stdIt++).second);
	assertEq("value after post ++", (*ftIt).second, (*stdIt).second);
	assertEq("(*++it).second", (*++ftIt).second, (*++stdIt).second);
	assertEq("(*it--).second", (*ftIt--).second, (*stdIt--).second);
	assertEq("value after post --", (*ftIt).second, (*stdIt).second);
	assertEq("(*--it).second", (*--ftIt).second, (*--stdIt).second);
	for (int i = 0; i < 6; i++) {
		ctnNotEqualValue += ftIt->second != stdIt->second;
		ctnEqualFt += tmpFtIt++ == ftIt++;
		ctnEqualStd += tmpStdIt++ == stdIt++;
		ctnEqualFt += tmpFtIt != ftIt;
		ctnEqualStd += tmpStdIt != stdIt;
	}
	assertEq("Compare data in map with ==", ctnEqualFt, ctnEqualStd);
	assertEq("Compare data in map with !=", ctnNotEqualFt, ctnNotEqualStd);
	assertEq("Check if values are same", ctnNotEqualValue, 0);
}

#endif // AVL_ITERATOR_TEST_HPP
