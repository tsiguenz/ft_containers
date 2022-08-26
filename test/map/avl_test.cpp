/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avl_test.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 17:52:09 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/08/26 18:57:49 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AVLTree.hpp"
#include "pair.hpp"

void printBT(const std::string& prefix, const ft::Node<int>* node, bool isLeft) {
	if (node != NULL) {
		std::cout << prefix;
		std::cout << (isLeft ? "|--" : "L--");
		// print the value of the node
		std::cout << node->data << std::endl;
		// enter the next tree level - left and right branch
		printBT(prefix + (isLeft ? "|   " : "    "), node->right, true);
		printBT(prefix + (isLeft ? "|   " : "    "), node->left, false);
	}
}

void printBT(const ft::Node<int>* node) {
	printBT("", node, false);
}

void	avl_test() {
#ifdef REAL
	namespace ft = std;
#endif
#ifndef REAL
	std::cout << "internal implementation of map can't be tested with real stl" << std::endl;
	{
		ft::AVLTree<int> tree;

		tree.insert(42);
		tree.insert(4);
		tree.insert(98);
		tree.insert(123);
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
		tree.remove(42);
		assertEq("root value after deleting root", tree.getRoot()->data, 76);
	}
	// test with pair
	{
		ft::AVLTree< ft::pair<int, std::string> >	tree;

		tree.insert(ft::pair<int, std::string>(1, "hello"));
		assertEq("root value of pair", tree.getRoot()->data.second, std::string("hello"));
		tree.insert(ft::pair<int, std::string>(-12, "begin"));
		tree.insert(ft::pair<int, std::string>(2, "world"));
		assertEq("min value", tree.minimum()->data.second, std::string("begin"));
		assertEq("max value", tree.maximum()->data.second, std::string("world"));
		tree.remove(ft::pair<int, std::string>(2, "world"));
		assertEq("search deleted node", (long) tree.searchByKey(ft::pair<int, std::string>(2, "world")), NULL);
		tree.insert(ft::pair<int, std::string>(2, "WORLD"));
		assertEq("max value", tree.maximum()->data.second, std::string("WORLD"));
	}
#endif
}
