/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 10:48:08 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/07/15 12:47:09 by tsiguenz         ###   ########.fr       */
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
				// Types :

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
				typedef ft::ReverseIterator<T>				reverse_iterator;
				typedef ft::ReverseIterator<const T>		const_reverse_iterator;

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
						this->_allocator = alloc;
						this->assign(count, value);
					}

				// Range
				template<class InputIterator>
					vector (InputIterator first,
							InputIterator last,
							allocator_type const& alloc = allocator_type())
					: _c(0), _size(0), _capacity(0), _allocator(alloc) {
						this->_allocator = alloc;
						assign(first, last);
					}

				// Copy
				vector(vector const& rhs)
					: _c(0), _size(0), _capacity(0), _allocator() {
						*this = rhs; }

				// Destructor
				~vector() {
					_free_all();
				}

				// Operators

				vector&	operator=(vector const& rhs) {
					_free_all();
					this->_allocator = rhs._allocator;
					this->_size = rhs._size;
					this->_capacity = rhs._capacity;
					this->_c = this->_allocator.allocate(this->_capacity);
					for (size_type i = 0; i < rhs._size; i++)
						this->_allocator.construct(this->_c + i, rhs._c[i]);
					return *this;
				}

				// Member functions

				void	assign(size_type count, const_reference value) {
					_free_all();
					this->_size = count;
					this->_capacity = this->_size;
					this->_c = this->_allocator.allocate(count);
					for (size_type i = 0; i < count; i++)
						this->_allocator.construct(this->_c + i, value);
				}

				template<class InputIt>
					typename ft::enable_if<!ft::is_integral<InputIt>::value>::type
					assign(InputIt first, InputIt last) {
						_free_all();
						this->_size = distance(first, last);
						this->_capacity = this->_size;
						this->_c = this->_allocator.allocate(this->_capacity);
						for (size_type i = 0; first < last; first++) {
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

				reference	front() { return *(this->begin()); }

				const_reference	front() const { return *(this->begin()); }

				reference	back() { return *(this->end() - 1); }

				const_reference	back() const { return *(this->end() - 1); }

				pointer	data() { return this->_c; }

				const_pointer	data() const { return this->_c; }

				// Iterators

				iterator	begin() { return this->_c; }

				iterator	end() { return this->_c + this->_size; }

				const_iterator	begin() const { return this->_c; }

				const_iterator	end() const {
					return this->_c + this->_size;
				}

				reverse_iterator	rbegin() {
					return this->_c + (this->_size - 1);
				}

				reverse_iterator	rend() { return this->_c - 1; }

				const_reverse_iterator	rbegin() const {
					return this->_c + (this->_size - 1);
				}

				const_reverse_iterator	rend() const { return this->_c; }

				// Capacity

				bool	empty() const { return this->begin() == this->end(); }

				size_type	size() const { return this->_size; }

				size_type	max_size() const { return this->_allocator.max_size(); }

				void	reserve(size_type new_cap) {
					if (new_cap <= this->_capacity)
						return ;
					ft::vector<T>	tmp = *this;
					_free_all();
					this->_size = tmp._size;
					this->_capacity = new_cap;
					this->_allocator = tmp._allocator;
					this->_c = this->_allocator.allocate(this->_capacity);
					// use insert
					typename ft::vector<T>::iterator	first = tmp.begin();
					typename ft::vector<T>::iterator	last = tmp.end();
					for (size_type i = 0; first < last; first++) {
						this->_allocator.construct(this->_c + i, *first);
						i++;
					}
				}

				size_type	capacity() const { return this->_capacity; }

				// Modifiers

				void	clear() {
					//TODO do we need this ?
					//	if (this->_size == 0 || this->_c == NULL)
					//		return ;
					for (size_type i = 0; i < this->_size; i++)
						this->_allocator.destroy(this->_c + i);
					this->_size = 0;
					this->_allocator = std::allocator<T>();
				}

				iterator	insert(iterator pos, const_reference value) {

				}

				void	insert(iterator pos, size_type count, const_reference value) {

				}

				template<class InputIt>
				void	insert(iterator pos, InputIt first, InputIt last) {
					
				}

			protected:
				pointer		_c;
				size_type	_size;
				size_type	_capacity;
				Allocator	_allocator;

			private:

				void	_free_all() {
					this->clear();
					this->_allocator.deallocate(this->_c, this->_capacity);
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
			return !ft::lexicographical_compare(rhs.begin(), rhs.end(),
					lhs.begin(), lhs.end());
		}

	template<class T, class Alloc>
		bool	operator>(vector<T, Alloc> const& lhs, vector<T, Alloc>const& rhs) {
			return ft::lexicographical_compare (rhs.begin(), rhs.end(),
					lhs.begin(), lhs.end());
		}

	template<class T, class Alloc>
		bool	operator>=(vector<T, Alloc> const& lhs, vector<T, Alloc> const& rhs) {
			return !ft::lexicographical_compare(lhs.begin(), lhs.end(),
					rhs.begin(), rhs.end());
		}

	template<class T, class Alloc>
		void	swap(vector<T, Alloc>& x, vector<T, Alloc>& y) {
			vector<T>	tmp = x;

			x = y;
			y = tmp;
		}
}

#endif
