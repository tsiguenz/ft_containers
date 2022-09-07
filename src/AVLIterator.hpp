/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AVLIterator.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 21:42:02 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/09/07 18:36:27 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AVL_ITERATOR_HPP
# define AVL_ITERATOR_HPP

# include <typeinfo>
# include "AVLTree.hpp"
# include "IteratorTraits.hpp"

namespace ft {
	template<typename _Node, typename _Pair, typename Compare>
		class AVLIterator { 
			public:
				// Types
				typedef typename ft::iterator_traits<_Pair*>::difference_type	difference_type;
				typedef typename ft::iterator_traits<_Pair*>::value_type		value_type;
				typedef typename ft::iterator_traits<_Pair*>::pointer			pointer;
				typedef typename ft::iterator_traits<_Pair*>::reference			reference;
				typedef std::bidirectional_iterator_tag							iterator_category;

			private:
				_Node*	_node;
				Compare	_comp;

			public:
				// Object managment
				AVLIterator()
				: _node(NULL) { }

				AVLIterator(_Node* node)
				: _node(node) { }

				AVLIterator(AVLIterator const& it)
				: _node(it._node) { }

				virtual ~AVLIterator() { }

				_Node*	base() const { return this->_node; }

				// Operators
				reference	operator*() const
				{ return _node->data; }

				AVLIterator&	operator=(AVLIterator const& it){
					this->_node = it._node;
					this->_comp = it._comp;
					return *this;
				}

				AVLIterator&	operator++(){
					std::cout << _node->parent->data.first << std::endl;
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

				pointer	operator->()
				{ return &_node->data; }

				operator AVLIterator<_Node, _Pair const, Compare>() const
				{ return AVLIterator<_Node, _Pair const, Compare>(this->_ptr); }

		};
	template<typename _Node, typename _Pair, typename Compare>
		bool	operator==(AVLIterator<_Node, _Pair, Compare> const& it1,
			AVLIterator<_Node, _Pair, Compare> const& it2)
		{ return it1.base() == it2.base(); }

	template<typename _Node, typename _Pair, typename Compare>
		bool	operator!=(AVLIterator<_Node, _Pair, Compare> const& it1,
			AVLIterator<_Node, _Pair, Compare> const& it2)
		{ return !(it1.base() == it2.base()); }
}
#endif // AVL_ITERATOR_HPP
