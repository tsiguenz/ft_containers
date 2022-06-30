/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ReverseIterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 11:46:21 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/06/30 17:50:17 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

#include <typeinfo>
namespace ft {
	template < typename T >
		class ReverseIterator { 
			public:
				// Types
				typedef typename std::iterator_traits<T*>::difference_type		difference_type;
				typedef typename std::iterator_traits<T*>::value_type			value_type;
				typedef typename std::iterator_traits<T*>::pointer				pointer;
				typedef typename std::iterator_traits<T*>::reference			reference;
				typedef typename std::iterator_traits<T*>::iterator_category	iterator_category;

			private:
				pointer	_ptr;

			public:
				// Object managment
				RandomAccessIterator(): _ptr() { };
				RandomAccessIterator(T* pointer): _ptr(pointer) { }

				template<typename U>
					RandomAccessIterator(U pointer): _ptr(&(*pointer)) { }

				RandomAccessIterator(RandomAccessIterator const& it) { *this = it; }
				~RandomAccessIterator() { }

				// Operators
				RandomAccessIterator<T>&	operator=(RandomAccessIterator<T> const& it){
					this->_ptr = it._ptr;
					return *this;
				}
				RandomAccessIterator<T>&	operator++(){
					this->_ptr++;
					return *this;
				}
				RandomAccessIterator<T>	operator++(int) {
					RandomAccessIterator<T>	tmp = *this;
					++(*this);
					return tmp;
				}
				RandomAccessIterator<T>&	operator--() {
					this->_ptr--;
					return *this;
				}
				RandomAccessIterator<T>	operator--(int) {
					RandomAccessIterator<T>	tmp = *this;
					--(*this);
					return tmp;
				}
				RandomAccessIterator<T>	operator+(difference_type const& n) {
					return this->_ptr + n;
				}
				RandomAccessIterator<T>&	operator+=(difference_type const& n) {
					this->_ptr += n;
					return *this;
				}
				RandomAccessIterator<T>	operator-(difference_type const& n) {
					return this->_ptr - n;
				}
				RandomAccessIterator<T>&	operator-=(difference_type const& n) {
					this->_ptr -= n;
					return *this;
				}
				T&	operator*() {
					return *(this->_ptr);
				}
				bool	operator==(RandomAccessIterator<T> const& it) const {
					return this->_ptr == it._ptr;
				}
				bool	operator!=(RandomAccessIterator<T> const& it) const {
					return this->_ptr != it._ptr;
				}
				bool	operator<(RandomAccessIterator<T> const& it) const {
					return this->_ptr < it._ptr;
				}
				bool	operator<=(RandomAccessIterator<T> const& it) const {
					return this->_ptr <= it._ptr;
				}
				bool	operator>(RandomAccessIterator<T> const& it) const {
					return this->_ptr > it._ptr;
				}
				bool	operator>=(RandomAccessIterator<T> const& it) const {
					return this->_ptr >= it._ptr;
				}
		};
}

#endif // REVERSE_ITERATOR_HPP
