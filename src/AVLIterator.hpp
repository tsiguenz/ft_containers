/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AVLIterator.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 21:42:02 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/09/06 18:59:05 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AVL_ITERATOR_HPP
# define AVL_ITERATOR_HPP

# include <typeinfo>
# include "AVLTree.hpp"
# include "IteratorTraits.hpp"

namespace ft {
	template < typename _Node, typename _Pair, typename Compare >
		class AVLIterator { 
			public:
				// Types
				typedef size_t								difference_type;
				typedef _Node								value_type;
				typedef _Node*								pointer;
				typedef _Node&								reference;
				typedef std::bidirectional_iterator_tag	iterator_category;

			private:
				_Node*	_node;

			public:
				AVLIterator()
				: _node(NULL) { }

				AVLIterator(pointer node)
				: _node(node) { }

				AVLIterator(AVLIterator const& it)
				: _node(it._node) { }

				_Pair&	operator*() const
				{ return _node->data; }

				_Pair*	operator->()
				{ return &_node->data; }

				~AVLIterator() { }

		};
}
#endif // AVL_ITERATOR_HPP
