/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 19:40:02 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/08/26 19:09:03 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

#include <iterator> // std::random_access_iterator_tag
#include <memory> // std::allocator
#include <cstddef> // std::ptrdiff_t
#include <stdexcept> // std::out_of_range and std::length_error
#include "ReverseIterator.hpp"
#include "Utils.hpp"
#include "TypeTraits.hpp"
#include "AVLTree.hpp"
#include "pair.hpp"

namespace ft {
	template < class Key, class T,
		class Compare = std::less<Key>,
		class Alloc = std::allocator<ft::pair<Key,T> > >
			class map {
				public:
					// Types

					typedef Key													key_type;
					typedef T													mapped_type;
					typedef ft::pair<Key, T>									value_type;
					typedef std::size_t											size_type;
					typedef ptrdiff_t											difference_type;
					typedef Compare												key_compare;
					typedef Alloc												allocator_type;
					typedef value_type&											reference;
					typedef value_type const&									const_reference;
					typedef typename Alloc::pointer								pointer;
					typedef typename Alloc::const_pointer						const_pointer;
//					typedef AVLIterator<ft::Node<value_type >, Compare>			iterator;
//					typedef BidirectionnalIterator<const AVLTree>				const_iterator;
//					typedef ft::reverse_iterator<iterator>				reverse_iterator;
//					typedef ft::reverse_iterator<const iterator>		const_reverse_iterator;
				private:

					AVLTree<value_type>	_tree;

				public:

					map()
					: _tree() { }

					void	insert(value_type const& pair) {
						_tree.insert(pair);
					}

					mapped_type&	operator[](key_type const& k) {
						ft::Node<value_type>*	tmp = _tree.getRoot();

//						if (tmp == NULL)
//							return mapped_type();
						while (tmp->data.first != k) {
							if (tmp->data.first < k)
								tmp = tmp->right;
							else
								tmp = tmp->left;
//							if (tmp == NULL)
//								return mapped_type();
						}
						return tmp->data.second;
					}
			};

}

#endif // MAP_HPP
