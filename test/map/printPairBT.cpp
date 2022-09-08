/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printPairBT.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 18:44:29 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/09/08 18:45:45 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AVLTree.hpp"
#include "pair.hpp"

void printPairBT(const std::string& prefix, const ft::Node<ft::pair< const int, int> >* node, bool isLeft) {
	if (node != NULL) {
		std::cout << prefix;
		std::cout << (isLeft ? "|--" : "L--");
		// print the value of the node
		std::cout << node->data.first << std::endl;
		// enter the next tree level - left and right branch
		printPairBT(prefix + (isLeft ? "|   " : "    "), node->right, true);
		printPairBT(prefix + (isLeft ? "|   " : "    "), node->left, false);
	}
}

void printPairBT(const ft::Node<ft::pair<const int, int> >* node) {
	printPairBT("", node, false);
}

