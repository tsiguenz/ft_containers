/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RandomAccessIterator.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 11:46:21 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/07/05 14:32:37 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

#include <typeinfo>
namespace ft {
	template < typename T >
		class RandomAccessIterator { 
			public:
				// Types
				typedef typename std::iterator_traits<T*>::difference_type		difference_type;
				typedef typename std::iterator_traits<T*>::value_type			value_type;
				typedef typename std::iterator_traits<T*>::pointer				pointer;
				typedef typename std::iterator_traits<T*>::reference			reference;
				typedef typename std::iterator_traits<T*>::iterator_category	iterator_category;

			private:
				T*	_ptr;

			public:
				// Object managment
				RandomAccessIterator(): _ptr() { };
				RandomAccessIterator(pointer ptr): _ptr(ptr) { }
				template<typename U>
					RandomAccessIterator(U ptr): _ptr(&*ptr) { }
				RandomAccessIterator(RandomAccessIterator<T> const& it) { *this = it; }
				~RandomAccessIterator() { }

				// Operators
				operator RandomAccessIterator<T const>() const {
					return RandomAccessIterator<T const>(this->_ptr);
				}
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
					this->_ptr++;
					return tmp;
				}
				RandomAccessIterator<T>&	operator--() {
					this->_ptr--;
					return *this;
				}
				RandomAccessIterator<T>	operator--(int) {
					RandomAccessIterator<T>	tmp = *this;
					this->_ptr--;
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

#endif // RANDOM_ACCESS_ITERATOR_HPP
