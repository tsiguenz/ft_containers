/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avl_test.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 17:52:09 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/09/28 15:30:50 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	avl_test() {
#ifndef REAL
	std::cout << "----------  AVLTree test : ----------" << std::endl;
	std::cout << "Internal implementation of map can't be tested with real stl" << std::endl;
	{
		ft::AVLTree<int> tree;

		assertEq("size of empty tree", (int) tree.size(), 0);
		tree.insert(42);
		tree.insert(4);
		tree.insert(98);
		tree.insert(123);
		assertEq("size of tree", (int) tree.size(), 4);
		assertEq("root value after 4 insertions", tree.getRoot()->data, 42);
		tree.remove(42);
		assertEq("root value after remove root", tree.getRoot()->data, 98);
		tree.insert(12);
		tree.insert(10);
		tree.insert(76);
		assertEq("max tree", tree.maximum()->data, 123);
		assertEq("min tree", tree.minimum()->data, 4);
		tree.remove(123);
		assertEq("max after delete max tree", tree.maximum()->data, 98);
		tree.insert(123);
		tree.remove(98);
		tree.remove(4);
		assertEq("min after delete min tree", tree.minimum()->data, 10);
		tree.remove(12);
		tree.remove(9999);
		assertEq("root value after deleting root", tree.getRoot()->data, 76);
		assertEq("size of tree", (int) tree.size(), 3);
	}
	// test with pair like in map
	{
		ft::AVLTree< ft::pair<const int, std::string> >	tree;

		tree.insert(ft::pair<const int, std::string>(1, "hello"));
		assertEq("root value of pair", tree.getRoot()->data.second, std::string("hello"));
		tree.insert(ft::pair<const int, std::string>(-12, "begin"));
		tree.insert(ft::pair<const int, std::string>(2, "world"));
		assertEq("min value", tree.minimum()->data.second, std::string("begin"));
		assertEq("max value", tree.maximum()->data.second, std::string("world"));
		tree.remove(ft::pair<const int, std::string>(2, "world"));
		assertEq("search deleted node", (long) tree.searchByData(ft::pair<const int, std::string>(2, "world")), NULL);
		tree.insert(ft::pair<const int, std::string>(2, "WORLD"));
		assertEq("max value", tree.maximum()->data.second, std::string("WORLD"));
	}
	std::cout << "----------  End of AVLTree test ----------" << std::endl;
#endif
}
