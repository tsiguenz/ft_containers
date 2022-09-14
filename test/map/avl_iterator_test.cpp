/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avl_iterator_test.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 13:35:23 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/09/14 18:28:12 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include "map.hpp"
#include "avl_iterator_generic_test.hpp"

#define FTMAP ft::map<int, int>
#define STDMAP std::map<int, int>

void	avl_iterator_test() {
# ifdef REAL
	namespace ft = std;
#endif
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

	

	std::cout << "----------  AVLIterator test : ----------" << std::endl;
	AVLIteratorTest<FTMAP::iterator, STDMAP::iterator>(ftM.begin(), stdM.begin());

	FTMAP::const_iterator	it = ftM.begin();
	std::cout << "----------  const AVLIterator tests : ----------" << std::endl;
	AVLIteratorTest<FTMAP::const_iterator, STDMAP::const_iterator>(ftM.begin(), stdM.begin());

	std::cout << "----------  ReverseIterator class : ----------" << std::endl;
	AVLIteratorTest<FTMAP::reverse_iterator, STDMAP::reverse_iterator>(ftM.rbegin(), stdM.rbegin());

	std::cout << "----------  const ReverseIterator class : ----------" << std::endl;
	AVLIteratorTest<FTMAP::const_reverse_iterator, STDMAP::const_reverse_iterator>(ftM.rbegin(), stdM.rbegin());

	// TODO more tests for iterators
}
