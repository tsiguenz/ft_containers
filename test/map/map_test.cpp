/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_test.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 16:27:59 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/09/09 17:48:24 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include "utils_test.hpp"
#include "map.hpp"
#include "map/pair_test.cpp"
#include "map/avl_test.cpp"
#include "avl_iterator_test.cpp"

#define FTMAP ft::map<int, int>
#define STDMAP std::map<int, int>

void	map_test() {
# ifdef REAL
	namespace ft = std;
#endif
//	avl_test();// TODO comment this line before push, its an internal test
//	pair_test();
	{
		FTMAP	ftM;
		STDMAP	stdM;

		ftM.insert(ft::pair<int, int>(0, 3));
		ftM.insert(ft::pair<int, int>(1, 56));
		ftM.insert(ft::pair<int, int>(2, 50));
		ftM.insert(ft::pair<int, int>(12, 200));
		ftM.insert(ft::pair<int, int>(15, 39));
		ftM.insert(ft::pair<int, int>(30, 12));
		stdM.insert(std::pair<int, int>(0, 3));
		stdM.insert(std::pair<int, int>(1, 56));
		stdM.insert(std::pair<int, int>(2, 50));
		stdM.insert(std::pair<int, int>(12, 200));
		stdM.insert(std::pair<int, int>(15, 39));
		stdM.insert(std::pair<int, int>(30, 12));
//		printPairBT(ftM.getData().getRoot());

		std::cout << "----------  AVLIterator test : ----------" << std::endl;
		AVLIteratorTest<FTMAP::iterator, STDMAP::iterator>(ftM.begin(), stdM.begin());

//		FTMAP::const_iterator	it = ftM.begin();
//		std::cout << "----------  const AVLIterator tests : ----------" << std::endl;
//		AVLIteratorTest<FTMAP::const_iterator, STDMAP::const_iterator>(ftM.begin(), stdM.begin());

		std::cout << "----------  ReverseIterator class : ----------" << std::endl;
		AVLIteratorTest<FTMAP::reverse_iterator, STDMAP::reverse_iterator>(ftM.rbegin(), stdM.rbegin());
	}
//
//		std::cout << "----------  ConstReverseIterator class : ----------" << std::endl;
//		mapIteratorTest<FTMAP::const_reverse_iterator,
//			STDMAP::const_reverse_iterator> (ftV.rbegin(), stdV.rbegin());
}
