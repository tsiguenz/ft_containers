/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MapIterator.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 21:42:02 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/09/26 19:03:53 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AVL_ITERATOR_HPP
# define AVL_ITERATOR_HPP

# include <typeinfo>
# include "AVLTree.hpp"
# include "IteratorTraits.hpp"
# include "pair.hpp"


namespace ft {
	template<typename _Pair, typename _Node>
		class MapIterator { 
			public:
				// Types
				typedef std::bidirectional_iterator_tag							iterator_category;
				typedef _Pair													iterator_type;
				typedef typename ft::iterator_traits<_Pair*>::difference_type	difference_type;
				typedef typename ft::iterator_traits<_Pair*>::value_type		value_type;
				typedef typename ft::iterator_traits<_Pair*>::pointer			pointer;
				typedef typename ft::iterator_traits<_Pair*>::reference			reference;

			private:
				_Node*	_node;

			public:
				// Object managment
				MapIterator(): _node(NULL) { }
				MapIterator(_Node* n): _node(n) { }
				MapIterator(MapIterator const& it): _node(it._node) { }
				virtual ~MapIterator() { }

				_Node*	base() const { return this->_node; }

				// Operators
				MapIterator&	operator=(MapIterator const& it){
					this->_node = it._node;
					return *this;
				}

				MapIterator&	operator++(){
					if (_node->right != NULL) {
						_node = _node->right;
						while (_node->left != NULL)
							_node = _node->left;
					}
					else {
						_Node*	tmp;
						do {
							tmp = _node;
							_node = _node->parent;
						}
						while (_node != NULL && _node->right == tmp);
					}
					return *this;
				}

				MapIterator	operator++(int) {
					MapIterator	tmp = *this;
					++(*this);
					return tmp;
				}

				MapIterator&	operator--(){
					if (_node->left != NULL) {
						_node = _node->left;
						while (_node->right != NULL)
							_node = _node->right;
					}
					else {
						_Node*	tmp;
						do {
							tmp = _node;
							_node = _node->parent;
						}
						while (_node != NULL && _node->left == tmp);
					}
					return *this;
				}

				MapIterator	operator--(int) {
					MapIterator	tmp = *this;
					--(*this);
					return tmp;
				}

				reference	operator*() const
				{ return _node->data; }

				pointer	operator->() const
				{ return &_node->data; }

				operator MapIterator<_Pair const, _Node>() const
				{ return MapIterator<_Pair const, _Node>(this->_node); }

		};

	// Non member operators

	template<typename T, typename U>
		bool	operator==(T const& it1,
			U const& it2)
		{ return it1.base() == it2.base(); }

	template<typename T, typename U>
		bool	operator!=(T const& it1,
			U const& it2)
		{ return !(it1.base() == it2.base()); }
}
#endif // AVL_ITERATOR_HPP
