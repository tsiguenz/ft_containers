/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RedBlackTree.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 17:38:11 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/08/04 19:05:34 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDBLACKTREE_HPP
# define REDBLACKTREE_HPP

# define UNDEFINED 0
# define RED_NODE 1
# define BLACK_NODE 2

namespace ft {

	template<typename T>
		struct node {
			T		value;
			node*	lChild;
			node*	rChild;
			node*	parent;
			int	color;

			node(T const& val = T()): value(val) {
				lChild = NULL;
				rChild = NULL;
				parent = NULL;
				color = UNDEFINED;
			}
		};

	template<typename T, class Alloc = std::allocator<T> >
		class RedBlackTree {

		};
}

#endif // REDBLACKTREE_HPP
