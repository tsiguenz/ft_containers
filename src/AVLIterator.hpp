/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AVLIterator.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 21:42:02 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/08/29 22:26:23 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AVL_ITERATOR_HPP
# define AVL_ITERATOR_HPP

# include <typeinfo>
# include "AVLTree.hpp"
# include "IteratorTraits.hpp"

namespace ft {
	template < typename T, typename Compare >
		class AVLIterator { 
			public:
				// Types
				typedef size_t							difference_type;
				typedef T								value_type;
				typedef T*								pointer;
				typedef T&								reference;
				typedef std::bidirectional_iterator_tag	iterator_category;

			private:
				T*	_node;

			public:
				AVLIterator()
				: _node(NULL) { }

				AVLIterator(T* node)
				: _node(node) { }

				AVLIterator(AVLIterator const& it)
				: _node(it._node) { }

				reference	operator*() const
				{ return this->_node->data; }

				pointer	operator->()
				{ return &_node->data; }

				~AVLIterator() { }

		};
}
#endif // AVL_ITERATOR_HPP
