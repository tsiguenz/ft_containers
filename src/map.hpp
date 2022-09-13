/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 19:40:02 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/09/13 18:45:42 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <iterator> // std::random_access_iterator_tag
# include <memory> // std::allocator
# include <cstddef> // std::ptrdiff_t
# include <stdexcept> // std::out_of_range and std::length_error
# include <functional> // std::binary_function
# include "Utils.hpp"
# include "TypeTraits.hpp"
# include "AVLTree.hpp"
# include "AVLIterator.hpp"
# include "ReverseIterator.hpp"
# include "pair.hpp"

namespace ft {
	template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key,T> > >
		class map {
			public:
				// Types
				typedef Key											key_type;
				typedef T											mapped_type;
				typedef ft::pair<const Key, T>						value_type;
				typedef std::size_t									size_type;
				typedef ptrdiff_t									difference_type;
				typedef Compare										key_compare;
				typedef Alloc										allocator_type;
				typedef value_type&									reference;
				typedef value_type const&							const_reference;
				typedef typename Alloc::pointer						pointer;
				typedef typename Alloc::const_pointer				const_pointer;

				class value_compare: public std::binary_function<value_type, value_type, bool> {
					friend class map;

					protected:
						Compare	comp;
						value_compare (Compare c) : comp(c) { }

					public:
						typedef bool	result_type;
						typedef value_type	first_argument_type;
						typedef value_type	second_argument_type;

						bool	operator() (const value_type& x, const value_type& y) const {
							return comp(x.first, y.first);
						}
				};

				typedef AVLIterator<value_type, ft::Node<value_type> >				iterator;
				typedef AVLIterator<value_type const, ft::Node<value_type> const>	const_iterator;
				typedef ft::ReverseIterator<iterator>								reverse_iterator;
				typedef ft::ReverseIterator<const_iterator>							const_reverse_iterator;

			private:

				AVLTree<value_type, Alloc, value_compare>	_tree;
				key_compare									_comp;
				allocator_type								_alloc;

			public:

			// TODO delete this helper function
				AVLTree<value_type, Alloc, value_compare >&	getData() {
					return _tree;
				}

			// Object managment

				explicit map(key_compare const& comp = key_compare(),
						allocator_type const& alloc = allocator_type())
					: _tree(value_compare(comp)), _comp(comp), _alloc(alloc) { }

				// TODO do it
				void	insert(value_type const& pair) {
					_tree.insert(pair);
				}

			// Iterators

				iterator	begin()
				{ return iterator(_tree.begin()); }

				const_iterator	begin() const
				{ return const_iterator(_tree.begin()); }

				reverse_iterator	rbegin()
				{ return reverse_iterator(_tree.end()); }

				const_reverse_iterator	rbegin() const
				{ return const_reverse_iterator(_tree.end()); }

				iterator	end()
				{ return iterator(_tree.end()); }

				const_iterator	end() const
				{ return const_iterator(_tree.end()); }

				reverse_iterator	rend()
				{ return reverse_iterator(_tree.begin()); }

				const_reverse_iterator	rend() const
				{ return const_reverse_iterator(_tree.begin()); }

			// Member functions

				// Element access

				T&	at(Key const& key) {
					ft::Node<value_type>*	tmp = _tree.getRoot();

					// TODO extract this in another function ?
					while (tmp->data.first != key) {
						if (tmp->data.first < key)
							tmp = tmp->right;
						else
							tmp = tmp->left;
						if (tmp == NULL)
							throw std::out_of_range("map::at : Key is out of range");
					}
					return tmp->data.second;
				}


				T const &	at(Key const& key) const {
					ft::Node<value_type>*	tmp = _tree.getRoot();

					while (tmp->data.first != key) {
						if (tmp->data.first < key)
							tmp = tmp->right;
						else
							tmp = tmp->left;
						if (tmp == NULL)
							throw std::out_of_range("map::at : Key is out of range");
					}
					return tmp->data.second;
				}

				// TODO do it
				mapped_type&	operator[](key_type const& k) {
					ft::Node<value_type>*	tmp = _tree.getRoot();

					while (tmp->data.first != k) {
						if (tmp->data.first < k)
							tmp = tmp->right;
						else
							tmp = tmp->left;
						if (tmp == NULL) {
							insert(ft::make_pair(k, mapped_type()));
							break ;
						}
					}
					return tmp->data.second;
				}

				// Observers

				key_compare	key_comp()
				{ return _comp; }

				value_compare	value_comp()
				{ return value_compare(_comp); }
		};

}

#endif // MAP_HPP
