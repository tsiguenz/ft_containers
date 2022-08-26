/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_test.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 16:27:59 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/08/26 19:09:26 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include "utils_test.hpp"
#include "map.hpp"
#include "map/pair_test.cpp"
#include "map/avl_test.cpp"

#define FTMAP ft::map<int, std::string>
#define STDMAP std::map<int, std::string>

void	map_test() {
# ifdef REAL
	namespace ft = std;
#endif
	avl_test();// TODO comment this line before push, its an internal test
	pair_test();
	// iterators tests :
	{
		FTMAP	m1;
		(void) m1;
//		STDMAP	m2;

		m1.insert(ft::pair<int, std::string>(1, "hello"));
		m1.insert(ft::pair<int, std::string>(0, "yo"));
		m1.insert(ft::pair<int, std::string>(2, "world"));
		std::cout << m1[1] << std::endl;
//		m2.insert(std::pair<int, std::string>(1, "hello"));
//		m2.insert(std::pair<int, std::string>(0, "yo"));
//		m2.insert(std::pair<int, std::string>(2, "world"));
//		FTMAP::iterator	ftit = m1.begin();
//		STDMAP::iterator	stdit = m2.begin();
//		std::cout << ftdit->first << std::endl;
//		std::cout << stdit->first << std::endl;

//		std::cout << "----------  BidirectionalIterator class : ----------" << std::endl;
//		mapIteratorTest<int, FTMAP::iterator, 
//			STDMAP::iterator> (ftV.begin(), stdV.begin());
//
//		std::cout << "----------  ConstRandomAccessIterator class : ----------" << std::endl;
//		mapIteratorTest<FTMAP::const_iterator,
//			STDMAP::const_iterator> (ftV.begin(), stdV.begin());
//
//		std::cout << "----------  ReverseIterator class : ----------" << std::endl;
//		mapIteratorTest<FTMAP::reverse_iterator,
//			STDMAP::reverse_iterator> (ftV.rbegin(), stdV.rbegin());
//
//		std::cout << "----------  ConstReverseIterator class : ----------" << std::endl;
//		mapIteratorTest<FTMAP::const_reverse_iterator,
//			STDMAP::const_reverse_iterator> (ftV.rbegin(), stdV.rbegin());
	}
}
