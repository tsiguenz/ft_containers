/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbt_test.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 17:52:09 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/08/04 19:08:58 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "RedBlackTree.hpp"

void	rbt_test() {
#ifdef REAL
	namespace ft = std;
#endif
// node cannot be tested with stl
#ifndef REAL
	std::cout << "internal implementation of map can't be tested with real stl" << std::endl;
	ft::node<int>	n;
	assertEq("node.value default constructor", n.value, int());
	assertEq("node.lChild default constructor", n.lChild, (ft::node<int>*) NULL);
	assertEq("node.rChild default constructor", n.rChild, (ft::node<int>*) NULL);
	assertEq("node.parent default constructor", n.parent, (ft::node<int>*) NULL);
	assertEq("node.color default constructor",  n.color, UNDEFINED);
#endif
}
