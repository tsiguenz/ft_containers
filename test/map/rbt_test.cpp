/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbt_test.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 17:52:09 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/08/23 23:35:11 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "RedBlackTree.hpp"

void	rbt_test() {
#ifdef REAL
	namespace ft = std;
#endif
#ifndef REAL
	std::cout << "internal implementation of map can't be tested with real stl" << std::endl;
	ft::RedBlackTree<int> tree;
	tree.insert(42);
	std::cout << tree.getRoot()->data << std::endl;
	tree.insert(4);
	tree.insert(98);
	tree.insert(123);
	tree.insert(12);
	tree.insert(10);
	std::cout << tree.minimum()->data << std::endl;
	std::cout << tree.maximum()->data << std::endl;
	tree.inorderHelper(tree.getRoot());
	tree.deleteNode(12);
	std::cout << std::endl;
	tree.inorderHelper(tree.getRoot());
#endif
}
