/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AVLIterator.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 21:42:02 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/09/14 18:19:06 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AVL_ITERATOR_HPP
# define AVL_ITERATOR_HPP

# include <typeinfo>
# include "AVLTree.hpp"
# include "IteratorTraits.hpp"

namespace ft {
	template<typename _Pair, typename _Node>
		class AVLIterator { 
			public:
				// Types
				typedef _Pair													iterator_type;
				typedef typename ft::iterator_traits<_Pair*>::difference_type	difference_type;
				typedef typename ft::iterator_traits<_Pair*>::value_type		value_type;
				typedef typename ft::iterator_traits<_Pair*>::pointer			pointer;
				typedef typename ft::iterator_traits<_Pair*>::reference			reference;
				typedef std::bidirectional_iterator_tag							iterator_category;

			private:
				_Node*	_node;

			public:
				// Object managment
				AVLIterator(): _node(NULL) { }

				AVLIterator(_Node* n): _node(n) { }

				AVLIterator(AVLIterator const& it): _node(it._node) { }

				template<typename Iterator>
				AVLIterator(Iterator it): _node(it.base()) { }

				virtual ~AVLIterator() { }

				_Node*	base() const { return this->_node; }

				// Operators
				AVLIterator&	operator=(AVLIterator const& it){
					this->_node = it._node;
					return *this;
				}

				AVLIterator&	operator++(){
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

				AVLIterator	operator++(int) {
					AVLIterator	tmp = *this;
					++(*this);
					return tmp;
				}

				AVLIterator&	operator--(){
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

				AVLIterator	operator--(int) {
					AVLIterator	tmp = *this;
					--(*this);
					return tmp;
				}

				reference	operator*() const
				{ return _node->data; }

				pointer	operator->() const
				{ return &_node->data; }

				operator AVLIterator<_Pair const, _Node>() const
				{ return AVLIterator<_Pair const, _Node>(this->_node); }

		};

	template<typename T, typename U, typename Node>
		bool	operator==(AVLIterator<T, Node> const& it1,
			AVLIterator<U, Node> const& it2)
		{ return it1.base() == it2.base(); }

	template<typename T, typename U, typename Node>
		bool	operator!=(AVLIterator<T, Node> const& it1,
			AVLIterator<U, Node> const& it2)
		{ return !(it1.base() == it2.base()); }
}
#endif // AVL_ITERATOR_HPP
