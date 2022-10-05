/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 10:48:08 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/10/05 11:01:11 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <iterator> // std::random_access_iterator_tag
#include <memory> // std::allocator
#include <cstddef> // std::ptrdiff_t
#include <stdexcept> // std::out_of_range and std::length_error
#include "RandomAccessIterator.hpp"
#include "reverse_iterator.hpp"
#include "Utils.hpp"
#include "TypeTraits.hpp"

namespace ft {
	template < class T, class Allocator = std::allocator<T> >
		class vector {
			public:
				// Types

				typedef T										value_type;
				typedef Allocator								allocator_type;
				typedef size_t									size_type;
				typedef std::ptrdiff_t							difference_type;
				typedef value_type&								reference;
				typedef value_type const&						const_reference;
				typedef typename Allocator::pointer 			pointer;
				typedef typename Allocator::const_pointer		const_pointer;
				typedef ft::RandomAccessIterator<T>				iterator;
				typedef ft::RandomAccessIterator<const T>		const_iterator;
				typedef ft::reverse_iterator<iterator>			reverse_iterator;
				typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;

				// Object managment

				// Default
				explicit vector(allocator_type const& alloc = allocator_type())
					: _p(0), _size(0), _capacity(0), _allocator(alloc) {
					}

				// Fill
				explicit vector(size_type count,
						const_reference value = value_type(),
						Allocator const& alloc = Allocator())
					: _p(0), _size(0), _capacity(0), _allocator(alloc) {
						assign(count, value);
					}

				// Range
				template<class InputIterator>
					vector (InputIterator first,
							InputIterator last,
							allocator_type const& alloc = allocator_type())
					: _p(0), _size(0), _capacity(0), _allocator(alloc) {
						assign(first, last);
					}

				// Copy
				vector(vector const& rhs)
					: _p(0), _size(0), _capacity(0), _allocator() {
						*this = rhs; }

				// Destructor
				~vector() {
					_freeAll();
				}

				vector&	operator=(vector const& rhs) {
					_freeAll();
					this->_allocator = rhs._allocator;
					this->_size = rhs._size;
					this->_capacity = rhs._size;
					this->_p = this->_allocator.allocate(this->_capacity);
					for (size_type i = 0; i < rhs._size; i++)
						this->_allocator.construct(this->_p + i, rhs._p[i]);
					return *this;
				}

				// Member functions
				void	assign(size_type count, const_reference value) {
					clear();
					for (size_type i = 0; i < count; i++)
						push_back(value);
				}

				template<class InputIt>
					typename ft::enable_if<!ft::is_integral<InputIt>::value>::type
					assign(InputIt first, InputIt last) {
						clear();
						insert(begin(), first, last);
					}

				allocator_type	get_allocator() const
				{ return this->_allocator; }

				// Element acces

				reference	at(size_type pos) {
					if (!(pos < size()))
						throw std::out_of_range("vector::at");
					return this->_p[pos];
				}

				const_reference	at(size_type pos) const {
					if (!(pos < size()))
						throw std::out_of_range("vector::at");
					return this->_p[pos];
				}

				reference	operator[](size_type pos) {
					return this->_p[pos];
				}

				const_reference	operator[](size_type pos) const {
					return this->_p[pos];
				}

				reference	front()
				{ return *(begin()); }

				const_reference	front() const
				{ return *(begin()); }

				reference	back()
				{ return *(end() - 1); }

				const_reference	back() const
				{ return *(end() - 1); }

				pointer	data()
				{ return this->_p; }

				const_pointer	data() const
				{ return this->_p; }

				// Iterators

				iterator	begin()
				{ return this->_p; }

				const_iterator	begin() const
				{ return this->_p; }

				iterator	end()
				{ return this->_p + this->_size; }

				const_iterator	end() const
				{ return this->_p + this->_size; }

				reverse_iterator	rbegin()
				{ return end(); }

				const_reverse_iterator	rbegin() const
				{ return end(); }

				reverse_iterator	rend()
				{ return begin(); }

				const_reverse_iterator	rend() const
				{ return begin(); }

				// Capacity

				bool	empty() const
				{ return begin() == end(); }

				size_type	size() const
				{ return this->_size; }

				size_type	max_size() const
				{ return this->_allocator.max_size(); }

				void	reserve(size_type new_cap) {
					if (new_cap > max_size())
						throw std::length_error("vector::reserve");
					if (new_cap <= this->_capacity)
						return ;
					ft::vector<T>	tmp = *this;
					_freeAll();
					this->_size = tmp._size;
					this->_capacity = new_cap;
					this->_allocator = tmp._allocator;
					this->_p = this->_allocator.allocate(this->_capacity);
					for (size_type i = 0; i < this->_size; i++)
						this->_allocator.construct(this->_p + i, tmp[i]);
				}

				size_type	capacity() const
				{ return this->_capacity; }

				// Modifiers
				void	clear() {
					if (this->_size == 0 || this->_p == NULL)
						return ;
					for (size_type i = 0; i < this->_size; i++)
						this->_allocator.destroy(this->_p + i);
					this->_size = 0;
				}

				// single element
				iterator	insert(iterator pos, const_reference value) {
					if (_size == 0 || pos == end()) {
						push_back(value);
						return end() - 1;
					}
					size_type i = 0;
					size_type	index_of_pos = _get_index_of_it(pos);
					if (_capacity < _size + 1) {
						// need to store this because reserve change the iterators
						reserve(_capacity * 2);
						pos = begin() + index_of_pos;
					}
					i = _size;
					if (i != index_of_pos) {
						_allocator.construct(_p + i, _p[i - 1]);
						--i;
						for (; i > index_of_pos; i--)
							_p[i] = _p[i - 1];
						_p[i] = value;
					}
					else
						_allocator.construct(_p + i, value);
					_size++;
					return pos;
				}

				// fill
				void	insert(iterator pos, size_type count, const_reference value) {
					if (_size + count > _capacity)
					{
						size_type	to_add = pos- begin();
						if (_size + count > _capacity * 2)
							reserve(_size + count);
						else
							reserve(_size * 2);
						pos= begin() + to_add;
					}
					for (size_type i = 0; i < count; ++i)
						pos= insert(pos, value) + 1;
				}

				// range
				template<class InputIt>
					typename ft::enable_if<!ft::is_integral<InputIt>::value>::type
					insert(iterator pos, InputIt first, InputIt last) {
						for (; first != last; first++)
							pos = insert(pos, *first) + 1;
					}

				iterator	erase(iterator position) {
					if (position != (end() - 1))
						_move_range_left(position, 1);
					pop_back();
					return position;
				}

				iterator	erase(iterator first, iterator last) {
					size_type	dist = ft::distance(first, last);

					if (dist == 0)
						return last;
					for (size_type i = 0; (last + i) != this->end(); i++) {
						*(first + i) = *(last + i);
					}
					for (size_type i = 0; i < dist; i++)
						pop_back();
					return first;
				}

				void	push_back(const_reference value) {
					if (begin() == end())
						reserve(1);
					if (this->_size == this->_capacity)
						reserve(this->_capacity * 2);
					this->_allocator.construct(this->_p + this->_size, value);
					this->_size++;
				}

				void	pop_back() {
					this->_allocator.destroy(&(this->back()));
					this->_size--;
				}

				void	resize(size_type count, value_type value = value_type()) {
					if (count <= this->_size) {
						while (count != this->_size)
							pop_back();
						return ;
					}
					while (count != this->_size)
						push_back(value);
				}

				void	swap(vector& x) {
					pointer		tmp_p = x._p;
					size_type	tmp_size = x._size;
					size_type	tmp_capacity = x._capacity;
					Allocator	tmp_allocator = x._allocator;
					x._p = this->_p;
					x._size = this->_size;
					x._capacity = this->_capacity;
					x._allocator = this->_allocator;
					this->_p = tmp_p;
					this->_size = tmp_size;
					this->_capacity = tmp_capacity;
					this->_allocator = tmp_allocator;
				}

			private:

				pointer		_p;
				size_type	_size;
				size_type	_capacity;
				Allocator	_allocator;

			// Utils

				void	_freeAll() {
					clear();
					this->_allocator.deallocate(this->_p, this->_capacity);
					this->_capacity = 0;
				}

				void	_move_range_left(iterator from, size_type const& offset) {
					for (; from != (this->end() - offset); from++) {
						_allocator.destroy(&(*from));
						_allocator.construct(&(*from), *(from + offset));
					}
				}

				size_type	_get_index_of_it(iterator const& it) const
				{ return it - begin(); }
		};

	// Non member functions

	template<class T, class Alloc>
		bool	operator==(vector<T, Alloc> const& lhs, vector<T, Alloc> const& rhs) {
			if (lhs.size() != rhs.size())
				return false;
			return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
		}

	template<class T, class Alloc>
		bool	operator!=(vector<T, Alloc> const& lhs, vector<T, Alloc> const& rhs)
		{ return !(lhs == rhs); }

	template<class T, class Alloc>
		bool	operator<(vector<T, Alloc> const& lhs, vector<T, Alloc> const& rhs) {
			return ft::lexicographical_compare (lhs.begin(), lhs.end(),
					rhs.begin(), rhs.end());
		}

	template<class T, class Alloc>
		bool	operator<=(vector<T, Alloc> const& lhs, vector<T, Alloc> const& rhs)
		{ return !(rhs < lhs); }

	template<class T, class Alloc>
		bool	operator>(vector<T, Alloc> const& lhs, vector<T, Alloc>const& rhs)
		{ return rhs < lhs; }

	template<class T, class Alloc>
		bool	operator>=(vector<T, Alloc> const& lhs, vector<T, Alloc> const& rhs)
		{ return !(lhs < rhs); }

	template<class T, class Alloc>
		void	swap(vector<T, Alloc>& x, vector<T, Alloc>& y)
		{ x.swap(y); }
}

#endif
