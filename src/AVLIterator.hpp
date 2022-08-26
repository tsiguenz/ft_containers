/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AVLIterator.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 21:42:02 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/08/26 18:12:23 by tsiguenz         ###   ########.fr       */
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
				typedef typename ft::iterator_traits<T*>::difference_type	difference_type;
				typedef typename ft::iterator_traits<T*>::value_type		value_type;
				typedef typename ft::iterator_traits<T*>::pointer			pointer;
				typedef typename ft::iterator_traits<T*>::reference			reference;
				typedef std::bidirectional_iterator_tag						iterator_category;

			private:
				T*	_node;

			public:
				AVLIterator()
				: _node(NULL) { }

				AVLIterator(AVLIterator const& it)
				: _node(it._node) { }

				~AVLIterator() { }

		};
}
#endif // AVL_ITERATOR_HPP
