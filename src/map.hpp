/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 19:40:02 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/09/09 17:54:14 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <iterator> // std::random_access_iterator_tag
# include <memory> // std::allocator
# include <cstddef> // std::ptrdiff_t
# include <stdexcept> // std::out_of_range and std::length_error
# include "Utils.hpp"
# include "TypeTraits.hpp"
# include "AVLTree.hpp"
# include "AVLIterator.hpp"
# include "ReverseIterator.hpp"
# include "pair.hpp"

namespace ft {
	template < class Key, class T,
		class Compare = std::less<Key>,
		class Alloc = std::allocator<ft::pair<const Key,T> > >
			class map {
				private:

					template<class CompareKey>
						struct	pair_key_less {
							CompareKey	comp;

							pair_key_less(): comp() { }
							~pair_key_less() { }

							bool	operator()(ft::pair<const Key, T> a, ft::pair<const Key, T> b) const {
								return comp(a.first, b.first);
							}
						};

				public:
					// Types
					typedef Key													key_type;
					typedef T													mapped_type;
					typedef ft::pair<const Key, T>								value_type;
					typedef std::size_t											size_type;
					typedef ptrdiff_t											difference_type;
					typedef Compare												key_compare;
//					typedef ????												value_compare;
					typedef Alloc												allocator_type;
					typedef value_type&											reference;
					typedef value_type const&									const_reference;
					typedef typename Alloc::pointer								pointer;
					typedef typename Alloc::const_pointer						const_pointer;
					typedef AVLIterator<value_type, ft::Node<value_type>, pair_key_less<Compare> >	iterator;
//					typedef AVLIterator<value_type const, ft::Node<value_type> const, pair_key_less<Compare> >	const_iterator;
					typedef ft::ReverseIterator<iterator>						reverse_iterator;
//					typedef ft::ReverseIterator<const iterator>					const_reverse_iterator;
				private:

					AVLTree<value_type, Alloc, pair_key_less<Compare> >	_tree;

				public:

					// Object managment

					map()
					: _tree() { }

					// TODO do it
					void	insert(value_type const& pair) {
						_tree.insert(pair);
					}

					// Iterators

					iterator	begin()
					{ return iterator(_tree.begin()); }

//					const_iterator	begin() const
//					{ return const_iterator(_tree.begin()); }

					reverse_iterator	rbegin()
					{ return reverse_iterator(_tree.end()); }

//					const_reverse_iterator	rbegin() const
//					{ return const_reverse_iterator(_tree.end()); }

					iterator	end()
					{ return iterator(_tree.end()); }

//					const_iterator	end() const
//					{ return const_iterator(_tree.end()); }

					reverse_iterator	rend()
					{ return reverse_iterator(_tree.begin()); }

//					const_reverse_iterator	rend() const
//					{ return const_reverse_iterator(_tree.begin()); }

					// Member functions

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

					// TODO delete this helper function
					AVLTree<value_type, Alloc, pair_key_less<Compare> >&	getData() {
						return _tree;
					}
			};

}

#endif // MAP_HPP
