/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 19:40:02 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/09/21 16:13:38 by tsiguenz         ###   ########.fr       */
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
# include "MapIterator.hpp"
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

			// Object managment

				// Default constructor O(1)
				explicit map(key_compare const& comp = key_compare(),
						allocator_type const& alloc = allocator_type())
					: _tree(value_compare(comp)), _comp(comp), _alloc(alloc) { }

				// Range constructor O(n * log(n))
				template <class InputIterator>
					map (InputIterator first, InputIterator last,
							const key_compare& comp = key_compare(),
							const allocator_type& alloc = allocator_type())
					: _tree(value_compare(comp)), _comp(comp), _alloc(alloc) {
						insert(first, last);
					}

				// Copy constructor O(n * log(n))
				map(map const& x): _tree(value_compare(x._comp)), _comp(x._comp) {
					insert(x.begin(), x.end());
				}

				// Destructor O(n)
				~map() { }

				// operator= O(n * log(n))
				map&	operator=(map const& other) {
					if (empty() == false)
						clear();
					if (other.empty() == false)
						insert(other.begin(), other.end());
					return *this;
				}

				// O(1)
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

				// O(1)
				iterator	begin()
				{ return iterator(_tree.begin()); }

				// O(1)
				const_iterator	begin() const
				{ return const_iterator(_tree.begin()); }

				// O(1)
				reverse_iterator	rbegin()
				{ return reverse_iterator(_tree.end()); }

				// O(1)
				const_reverse_iterator	rbegin() const
				{ return const_reverse_iterator(_tree.end()); }

				// O(1)
				iterator	end()
				{ return iterator(_tree.end()); }

				// O(1)
				const_iterator	end() const
				{ return const_iterator(_tree.end()); }

				// O(1)
				reverse_iterator	rend()
				{ return reverse_iterator(_tree.begin()); }

				// O(1)
				const_reverse_iterator	rend() const
				{ return const_reverse_iterator(_tree.begin()); }

			// Capacity

				// O(1)
				bool	empty() const
				{ return _tree.size() == 0; }

				// O(1)
				size_type	size() const
				{ return _tree.size(); }

				// O(1)
				size_type	max_size() const
				{ return _tree.max_size(); }

			// Modifiers

				void	clear() {
					erase(begin(), end());
				}

				// insert single value O(log(n))
				ft::pair<iterator, bool>	insert(const value_type& value) {
					ft::Node<value_type>*	tmp = _getNodeByKey(value.first);
					
					if (tmp != NULL)
						return ft::pair<iterator, bool>(tmp, false);
					_tree.insert(value);
					return ft::pair<iterator, bool>(_getNodeByKey(value.first), true);
				}

				// TODO change for respect the complexity ?
				// insert single value with hint O(log(n)) (hint useless)
				iterator	insert(iterator hint, const value_type& value) {
					(void) hint;
					return insert(value).first;
				}

				// insert range O(n * log(n) + n)
				template<class InputIt>
					void	insert(InputIt first, InputIt last) {
						for (;first != last; first++) {
							insert(*first);
						}
					}

				// TODO change for respect the complexity
				// erase pos O(1)
				void	erase(iterator pos) {
					_tree.remove(*pos);
				}

				// erase key O(log(n))
				size_type	erase(key_type const& k) {
					Node<value_type>*	nodeToRemove = _getNodeByKey(k);
					if (nodeToRemove == NULL)
						return 0;
					_tree.remove(nodeToRemove->data);
					return 1;
				}

				// TODO change for respect the complexity
				// erase range
				void	erase(iterator first, iterator last) {
					while (first != last) {
						erase(first++);
					}
				}

				void	swap(map& x) {
					map	tmp = *this;

					*this = x;
					x = tmp;
				}
			// Lookup

				size_type	count(key_type const& key) const {
					return _getNodeByKey(key) != NULL;
				}

				iterator	find(key_type const& key) {
					Node<value_type>*	ret = _getNodeByKey(key);
					return ret == NULL ? end() : ret;
				}

				const_iterator	find(key_type const& key) const {
					Node<value_type>*	ret = _getNodeByKey(key);
					return ret == NULL ? end() : ret;
				}

				ft::pair<iterator, iterator>	equal_range(Key const& key) {
					Node<value_type>*	ret = _getNodeByKey(key);

					if (ret == NULL)
						return ft::make_pair(end(), end());
					return ft::make_pair(ret, ++iterator(ret));
				}

				ft::pair<const_iterator, const_iterator>	equal_range(Key const& key) const {
					Node<value_type>*	ret = _getNodeByKey(key);

					if (ret == NULL)
						return ft::make_pair(end(), end());
					return ft::make_pair(ret, ++iterator(ret));
				}

				iterator	lower_bound(key_type const& key) {
					iterator	curr = begin();

					while (curr != end()) {
						if (!_comp(curr->first, key))
							return iterator(curr);
						else
							curr++;
					}
					return end();
				}

				const_iterator	lower_bound(key_type const& key) const {
					iterator	curr = begin();

					while (curr != end()) {
						if (!_comp(curr->first, key))
							return iterator(curr);
						else
							curr++;
					}
					return end();
				}

				iterator	upper_bound(key_type const& key) {
					iterator	curr = begin();

					while (curr != end()) {
						if (_comp(key, curr->first))
							return iterator(curr);
						else
							curr++;
					}
					return end();
				}

				const_iterator	upper_bound(key_type const& key) const {
					iterator	curr = begin();

					while (curr != end()) {
						if (_comp(key, curr->first))
							return iterator(curr);
						else
							curr++;
					}
					return end();
				}

			// Observers

				// O(n)
				key_compare	key_comp()
				{ return _comp; }

				// O(n)
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

	template<class Key, class T, class Compare, class Alloc>
		bool	operator==(ft::map<Key, T, Compare, Alloc> const& lhs,
				ft::map<Key, T, Compare, Alloc> const& rhs) {
			if (lhs.size() != rhs.size())
				return false;
			return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
		}

	template<class Key, class T, class Compare, class Alloc>
		bool	operator!=(ft::map<Key, T, Compare, Alloc> const& lhs,
				ft::map<Key, T, Compare, Alloc> const& rhs) {
			return !(lhs == rhs);
		}

	template<class Key, class T, class Compare, class Alloc>
		bool	operator<(ft::map<Key, T, Compare, Alloc> const& lhs,
				ft::map<Key, T, Compare, Alloc> const& rhs) {
			return ft::lexicographical_compare (lhs.begin(), lhs.end(),
					rhs.begin(), rhs.end());
		}

	template<class Key, class T, class Compare, class Alloc>
		bool	operator<=(ft::map<Key, T, Compare, Alloc> const& lhs,
				ft::map<Key, T, Compare, Alloc> const& rhs) {
			return !(rhs < lhs);
		}

	template<class Key, class T, class Compare, class Alloc>
		bool	operator>(ft::map<Key, T, Compare, Alloc> const& lhs,
				ft::map<Key, T, Compare, Alloc> const& rhs) {
			return rhs < lhs;
		}

	template<class Key, class T, class Compare, class Alloc>
		bool	operator>=(ft::map<Key, T, Compare, Alloc> const& lhs,
				ft::map<Key, T, Compare, Alloc> const& rhs) {
			return !(lhs < rhs);
		}

	template< class Key, class T, class Compare, class Alloc >
		void	swap(ft::map<Key, T, Compare, Alloc>& lhs,
				ft::map<Key, T, Compare, Alloc>& rhs ) {
			lhs.swap(rhs);
		}
}

#endif // MAP_HPP
