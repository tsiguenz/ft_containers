/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 10:48:08 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/07/14 12:23:02 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <RandomAccessIterator.hpp>
#include <ReverseIterator.hpp>
#include <EnableIf.hpp>
#include <TypeTraits.hpp>

namespace ft {
	template < class T, class Allocator = std::allocator<T> >
	class vector {
		public:
		// Types :

			typedef T											value_type;
			typedef Allocator									allocator_type;
			typedef value_type* 								pointer;
			typedef value_type const							const_pointer;
			typedef value_type&									reference;
			typedef const value_type&							const_reference;
			typedef size_t										size_type;
			typedef std::ptrdiff_t								difference_type;
			typedef ft::RandomAccessIterator<T>					iterator;
			typedef ft::RandomAccessIterator<const T>			const_iterator;
			typedef ft::ReverseIterator<T>						reverse_iterator;
			typedef ft::ReverseIterator<const T>				const_reverse_iterator;

		// Object managment

			// Default
			explicit vector(allocator_type const& alloc = allocator_type())
				: _c(0), _size(0), _allocator(alloc) {
			}

			// Fill
			explicit vector(size_type count,
				T const& value = T(),
				Allocator const& alloc = Allocator()) {
					this->_allocator = alloc;
					this->assign(count, value);
			}

			// Range
			template<class InputIterator>
			vector (InputIterator first, InputIterator last,
				allocator_type const& alloc = allocator_type()) {
					this->_allocator = alloc;
					this->_size = _distance(first, last);
					_range_insert<InputIterator>(first, last);
			}

			// Copy
			vector(vector const& rhs) { *this = rhs; }

			// Destructor
			~vector() { this->clear(); }

		// Operators

			vector&	operator=(vector const& rhs) {
				this->clear();
				this->_allocator = rhs._allocator;
				this->_size = rhs._size;
				this->c = this->_allocator.allocate(this->_size);
				for (size_type i = 0; i < rhs._size; i++)
					this->_allocator.construct(this->_c + i, rhs._c[i]);
				return rhs;
			}
			T&	operator[](size_type const& pos) { return this->_c[pos]; }

		// Member functions

			// Iterators

			iterator				begin() { return this->_c; }
			iterator				end() { return this->_c + this->_size; }
			const_iterator			begin() const { return this->_c; }
			const_iterator			end() const { return this->_c + this->_size; }
			reverse_iterator		rbegin() { return this->_c + (this->_size - 1); }
			reverse_iterator		rend() { return this->_c - 1; }
			const_reverse_iterator	rbegin() const { return this->_c + (this->_size - 1); }
			const_reverse_iterator	rend() const { return this->_c; }

			// Element acces

			// TODO need the same exception message ?
			T&	at(size_type pos) {
				if (pos < 0 || pos >= this->_size)
					throw std::out_of_range("Vector::Out of range");
				return (*this)[pos];
			}
			T&	front() { return *(this->begin()); }
			T&	back() { return *(this->end() - 1); }
			T*	data() { return this->_c; }

			// Others

			size_type	size() { return this->_size; }
			void	clear() {
				this->_allocator.deallocate(this->_c, this->_size);
				for (size_type i = 0; i < this->_size; i++)
					this->_allocator.destroy(this->_c + i);
				this->_size = 0;
			}

			bool	empty() { return !this->_size; }

			void	assign(size_type count, T const& value) {
				this->_size = count;
				this->_c = this->_allocator.allocate(count);
				for (size_type i = 0; i < count; i++)
					this->_allocator.construct(this->_c + i, value);
			}

		protected:
			pointer		_c;
			size_type	_size;
			Allocator	_allocator;

		private:
			template<typename InputIterator>
			size_type	_distance(InputIterator it, InputIterator ite) {
				size_type	res = 0;

				for (;it != ite; it++) {
					res++;
				}
				return res;
			}

			// Specialization for integral of _range_insert
			template<typename _Integral>
			typename ft::enable_if<ft::is_integral<_Integral>::value>::type
			_range_insert(_Integral count, _Integral value) {
					this->assign(count, value);
			}

			// Default function template _range_insert
			template<typename InputIterator>
			typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type
			_range_insert(InputIterator first, InputIterator last) {
				this->_c = this->_allocator.allocate(this->_size);
				for (size_type i = 0; first < last; first++) {
					this->_allocator.construct(this->_c + i, *first);
					i++;
				}
			}
	};
}

#endif
