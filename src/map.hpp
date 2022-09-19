/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 19:40:02 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/09/19 18:20:45 by tsiguenz         ###   ########.fr       */
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

				// Default constructor
				explicit map(key_compare const& comp = key_compare(),
						allocator_type const& alloc = allocator_type())
					: _tree(value_compare(comp)), _comp(comp), _alloc(alloc) { }

				// Range constructor
				template <class InputIterator>
					map (InputIterator first, InputIterator last,
							const key_compare& comp = key_compare(),
							const allocator_type& alloc = allocator_type())
					: _tree(value_compare(comp)), _comp(comp), _alloc(alloc) {
						insert(first, last);
					}

				// Copy constructor
				map(map const& x)
				{ *this = x; }

				// Destructor
				~map() { }

				map&	operator=(map const& other) {
					insert(other.begin(), other.end());
					this->_comp = other._comp;
					this->_alloc = other._alloc;
					return *this;
				}

				// O(n)
				allocator_type	get_allocator() const {
					return _alloc;
				}

			// Element access

				// O(log(n))
				mapped_type&	at(Key const& key) {
					ft::Node<value_type>*	tmp = _getNodeByKey(key);

					if (tmp == NULL)
						throw std::out_of_range("map::at : Key is out of range");
					return tmp->data.second;
				}

				// O(log(n))
				mapped_type const&	at(Key const& key) const {
					ft::Node<value_type>*	tmp = _getNodeByKey(key);

					if (tmp == NULL)
						throw std::out_of_range("map::at : Key is out of range");
					return tmp->data.second;
				}

				// O(log(n))
				mapped_type&	operator[](key_type const& key) {
					ft::Node<value_type>*	tmp = _getNodeByKey(key);

					if (tmp != NULL)
						return tmp->data.second;
					return insert(ft::make_pair(key, T())).first->second;
				}

			// Iterators

				// O(n)
				iterator	begin()
				{ return iterator(_tree.begin()); }

				// O(n)
				const_iterator	begin() const
				{ return const_iterator(_tree.begin()); }

				// O(n)
				reverse_iterator	rbegin()
				{ return reverse_iterator(_tree.end()); }

				// O(n)
				const_reverse_iterator	rbegin() const
				{ return const_reverse_iterator(_tree.end()); }

				// O(n)
				iterator	end()
				{ return iterator(_tree.end()); }

				// O(n)
				const_iterator	end() const
				{ return const_iterator(_tree.end()); }

				// O(n)
				reverse_iterator	rend()
				{ return reverse_iterator(_tree.begin()); }

				// O(n)
				const_reverse_iterator	rend() const
				{ return const_reverse_iterator(_tree.begin()); }

			// Capacity

				// O(n)
				bool	empty() const
				{ return _tree.size() == 0; }

				// O(n)
				size_type	size() const
				{ return _tree.size(); }

				// O(n)
				size_type	max_size() const
				{ return _tree.max_size(); }

			// Modifiers

				void	clear() {
					// use erase
				}

				// insert single value O(log(n))
				ft::pair<iterator, bool>	insert(const value_type& value) {
					ft::Node<value_type>*	tmp = _getNodeByKey(value.first);
					
					if (tmp != NULL)
						return ft::pair<iterator, bool>(tmp, false);
					_tree.insert(value);
					return ft::pair<iterator, bool>(_getNodeByKey(value.first), true);
				}

				// insert single value with hint O(log(n)) (hint useless)
				iterator	insert(iterator hint, const value_type& value) {
					(void) hint;
					return insert(value).first;
				}

				// insert range
				template<class InputIt>
					void	insert(InputIt first, InputIt last) {
						for (;first != last; first++) {
							insert(*first);
						}
					}

//				// erase pos O(1)
//				void	erase(iterator pos) {
//				}

				// erase key O(log(n))
				size_type	erase(key_type const& k) {
					Node<value_type>*	nodeToRemove = _getNodeByKey(k);
					if (nodeToRemove == NULL)
						return 0;
					_tree.remove(nodeToRemove->data);
					return 1;
				}
				// erase range
				void	erase(iterator first, iterator last) {
					for (;first != last; first++)
						erase(first);
				}

				// Observers

				key_compare	key_comp()
				{ return _comp; }

				value_compare	value_comp()
				{ return value_compare(_comp); }

				private:

				ft::Node<value_type>*	_getNodeByKey(key_type const& key) const {
					ft::Node<value_type>*	tmp = _tree.getRoot();

					while (tmp != NULL && tmp->data.first != key) {
						if (tmp->data.first < key)
							tmp = tmp->right;
						else
							tmp = tmp->left;
					}
					// if tmp == NULL return NULL
					return tmp;
				}
		};

}

#endif // MAP_HPP
