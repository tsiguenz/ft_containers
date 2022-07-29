/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 10:48:08 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/07/29 16:45:30 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <RandomAccessIterator.hpp>
#include <ReverseIterator.hpp>
#include <Utils.hpp>
#include <TypeTraits.hpp>

namespace ft {
	template < class T, class Allocator = std::allocator<T> >
		class vector {
			public:
				// Types

				typedef T									value_type;
				typedef Allocator							allocator_type;
				typedef value_type* 						pointer;
				typedef value_type const*					const_pointer;
				typedef value_type&							reference;
				typedef value_type const&					const_reference;
				typedef size_t								size_type;
				typedef std::ptrdiff_t						difference_type;
				typedef ft::RandomAccessIterator<T>			iterator;
				typedef ft::RandomAccessIterator<const T>	const_iterator;
				typedef ft::ReverseIterator<iterator>		reverse_iterator;
				typedef ft::ReverseIterator<const_iterator>	const_reverse_iterator;

				// Object managment

				// Default
				explicit vector(allocator_type const& alloc = allocator_type())
					: _c(0), _size(0), _capacity(0), _allocator(alloc) {
					}

				// Fill
				explicit vector(size_type count,
						const_reference value = T(),
						Allocator const& alloc = Allocator())
					: _c(0), _size(0), _capacity(0), _allocator(alloc) {
						assign(count, value);
					}

				// Range
				template<class InputIterator>
					vector (InputIterator first,
							InputIterator last,
							allocator_type const& alloc = allocator_type())
					: _c(0), _size(0), _capacity(0), _allocator(alloc) {
						assign(first, last);
					}

				// Copy
				vector(vector const& rhs)
					: _c(0), _size(0), _capacity(0), _allocator() {
						*this = rhs; }

				// Destructor
				~vector() {
					_freeAll();
				}

				// Operators
				vector&	operator=(vector const& rhs) {
					_freeAll();
					this->_allocator = rhs._allocator;
					this->_size = rhs._size;
					this->_capacity = rhs._size;
					this->_c = this->_allocator.allocate(this->_capacity);
					for (size_type i = 0; i < rhs._size; i++)
						this->_allocator.construct(this->_c + i, rhs._c[i]);
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
						_freeAll();
						this->_size = ft::distance(first, last);
						if (this->_capacity == 0)
							this->_capacity = this->_size;
						while (this->_capacity < this->_size)
							reserve(this->_capacity * 2);
						this->_c = this->_allocator.allocate(this->_capacity);
						for (size_type i = 0; first != last; first++) {
							this->_allocator.construct(this->_c + i, *first);
							i++;
						}
					}

				allocator_type	get_allocator() { return this->_allocator; }

				// Element acces

				// TODO need the same exception message ?
				reference	at(size_type pos) {
					if (pos < 0 || pos >= this->_size)
						throw std::out_of_range("Vector::Out of range");
					return this->_c[pos];
				}

				const_reference	at(size_type pos) const {
					if (pos < 0 || pos >= this->_size)
						throw std::out_of_range("Vector::Out of range");
					return this->_c[pos];
				}

				reference	operator[](size_type const& pos) {
					return this->_c[pos];
				}

				const_reference	operator[](size_type const& pos) const {
					return this->_c[pos];
				}

				reference	front() { return *(begin()); }

				const_reference	front() const { return *(begin()); }

				reference	back() { return *(end() - 1); }

				const_reference	back() const { return *(end() - 1); }

				pointer	data() { return this->_c; }

				const_pointer	data() const { return this->_c; }

				// Iterators

				iterator	begin() { return this->_c; }

				iterator	end() { return this->_c + this->_size; }

				const_iterator	begin() const { return this->_c; }

				const_iterator	end() const { return this->_c + this->_size; }

				reverse_iterator	rbegin() { return end(); }

				const_reverse_iterator	rbegin() const { return end(); }

				reverse_iterator	rend() { return begin(); }

				const_reverse_iterator	rend() const { return begin(); }

				// Capacity

				bool	empty() const { return begin() == end(); }

				size_type	size() const { return this->_size; }

				size_type	max_size() const { return this->_allocator.max_size(); }

				void	reserve(size_type new_cap) {
					if (new_cap <= this->_capacity)
						return ;
					ft::vector<T>	tmp = *this;
					_freeAll();
					this->_size = tmp._size;
					this->_capacity = new_cap;
					this->_allocator = tmp._allocator;
					this->_c = this->_allocator.allocate(this->_capacity);
					// TODO use insert
					for (size_type i = 0; i < this->_size; i++) {
						this->_allocator.construct(this->_c + i, tmp[i]);
					}
				}

				size_type	capacity() const { return this->_capacity; }

				// Modifiers
				void	clear() {
					if (this->_size == 0 || this->_c == NULL)
						return ;
					for (size_type i = 0; i < this->_size; i++)
						this->_allocator.destroy(this->_c + i);
					this->_size = 0;
				}

				// single element
				iterator	insert(iterator pos, const_reference value) {
					if (this->_size == 0) {
						push_back(value);
						return this->begin();
					}
					size_type	newSize = this->_size + 1;
					// need to store this because reserve change the iterators
					size_type	index_of_pos = _get_index_of_it(pos);
					if (this->_capacity < newSize)
						reserve(this->_capacity * 2);
					pos = this->begin() + index_of_pos;
					_move_range_left(pos, 1);
					*pos = value;
					this->_size++;
					return pos;
				}

				// fill
				void	insert(iterator pos, size_type count, const_reference value) {
					if (this->_size == 0) {
						assign(count, value);
						return ;
					}
					size_type	newSize = this->_size + count;
					// need to store this because reserve change the iterators
					size_type	index_of_pos = _get_index_of_it(pos);
					while (this->_capacity < newSize)
						reserve(this->_capacity * 2);
					pos = this->begin() + index_of_pos;
					_move_range_left(pos, count);
					for (size_type i = 0; i < count; i++)
						*(pos + i) = value;
					this->_size = newSize;
				}

				// range
				template<class InputIt>
					typename ft::enable_if<!ft::is_integral<InputIt>::value>::type
					insert(iterator pos, InputIt first, InputIt last) {
						if (this->_size == 0) {
							assign(first, last);
							return ;
						}
						size_type	newSize = this->_size + ft::distance(first, last);
						// need to store the index because reserve change the iterators
						size_type	index_of_pos = _get_index_of_it(pos);
						while (this->_capacity < newSize)
							reserve(this->_capacity * 2);
						pos = this->begin() + index_of_pos;
						_move_range_left(pos, ft::distance(first, last));
						for (; first != last; first++) {
							*pos = *first;
							pos++;
						}
						this->_size = newSize;
					}

				iterator	erase(iterator position) {
					if (position != (end() - 1))
						_move_range_right(position, 1);
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
					this->_allocator.construct(this->_c + this->_size, value);
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
					pointer		tmp_c = x._c;
					size_type	tmp_size = x._size;
					size_type	tmp_capacity = x._capacity;
					Allocator	tmp_allocator = x._allocator;
					x._c = this->_c;
					x._size = this->_size;
					x._capacity = this->_capacity;
					x._allocator = this->_allocator;
					this->_c = tmp_c;
					this->_size = tmp_size;
					this->_capacity = tmp_capacity;
					this->_allocator = tmp_allocator;
				}

			protected:
				pointer		_c;
				size_type	_size;
				size_type	_capacity;
				Allocator	_allocator;

			private:

				void	_freeAll() {
					clear();
					this->_allocator.deallocate(this->_c, this->_capacity);
				}

				void	_move_range_left(iterator const& from, size_type const& offset) {
					iterator	curr = this->end() + offset - 1;

					if (from == this->end())
						return ;
					for (size_type i = 0; i < this->_size && from != curr; i++) {
						*curr = *(curr - offset);
						curr--;
					}
				}

				void	_move_range_right(iterator from, size_type const& offset) {
					for (; from != (this->end() - offset); from++)
						*from = *(from + offset);
				}

				size_type	_get_index_of_it(iterator it) {
					size_type	ret = 0;

					for (iterator curr = this->begin(); curr != it; curr++) {
						ret++;
						if (curr == this->end())
							return 0;
					}
					return ret;
				}
		};

	template<class T, class Alloc>
		bool	operator==(vector<T, Alloc> const& lhs, vector<T, Alloc> const& rhs) {
			if (lhs.size() != rhs.size())
				return false;
			return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
		}

	template<class T, class Alloc>
		bool	operator!=(vector<T, Alloc> const& lhs, vector<T, Alloc> const& rhs) {
			return !(lhs == rhs);
		}

	template<class T, class Alloc>
		bool	operator<(vector<T, Alloc> const& lhs, vector<T, Alloc> const& rhs) {
			return ft::lexicographical_compare (lhs.begin(), lhs.end(),
					rhs.begin(), rhs.end());
		}

	template<class T, class Alloc>
		bool	operator<=(vector<T, Alloc> const& lhs, vector<T, Alloc> const& rhs) {
			return !(rhs < lhs);
		}

	template<class T, class Alloc>
		bool	operator>(vector<T, Alloc> const& lhs, vector<T, Alloc>const& rhs) {
			return rhs < lhs;
		}

	template<class T, class Alloc>
		bool	operator>=(vector<T, Alloc> const& lhs, vector<T, Alloc> const& rhs) {
			return !(lhs < rhs);
		}

	template<class T, class Alloc>
		void	swap(vector<T, Alloc>& x, vector<T, Alloc>& y) {
			x.swap(y);
		}
}

#endif
