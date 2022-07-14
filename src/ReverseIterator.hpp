/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ReverseIterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 11:46:21 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/07/14 12:32:41 by tsiguenz         ###   ########.fr       */
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
				typedef typename ft::iterator_traits<T*>::difference_type		difference_type;
				typedef typename ft::iterator_traits<T*>::value_type			value_type;
				typedef typename ft::iterator_traits<T*>::pointer				pointer;
				typedef typename ft::iterator_traits<T*>::reference			reference;
				typedef typename ft::iterator_traits<T*>::iterator_category	iterator_category;

			private:
				T*	_ptr;

			public:
				// Object managment
				ReverseIterator(): _ptr() { };
				ReverseIterator(pointer ptr): _ptr(ptr) { }
				ReverseIterator(ReverseIterator<T> const& it) { *this = it; }
				~ReverseIterator() { }

				// Operators
				operator ReverseIterator<T const>() {
					return ReverseIterator<T const>(this->_ptr);
				}
				ReverseIterator<T>&	operator=(ReverseIterator<T> const& it){
					this->_ptr = it._ptr;
					return *this;
				}
				ReverseIterator<T>&	operator++(){
					this->_ptr--;
					return *this;
				}
				ReverseIterator<T>	operator++(int) {
					ReverseIterator<T>	tmp = *this;
					this->_ptr--;
					return tmp;
				}
				ReverseIterator<T>&	operator--() {
					this->_ptr++;
					return *this;
				}
				ReverseIterator<T>	operator--(int) {
					ReverseIterator<T>	tmp = *this;
					this->_ptr++;
					return tmp;
				}
				ReverseIterator<T>	operator+(difference_type const& n) {
					return this->_ptr - n;
				}
				ReverseIterator<T>&	operator+=(difference_type const& n) {
					this->_ptr -= n;
					return *this;
				}
				ReverseIterator<T>	operator-(difference_type const& n) {
					return this->_ptr + n;
				}
				ReverseIterator<T>&	operator-=(difference_type const& n) {
					this->_ptr += n;
					return *this;
				}
				T&	operator*() {
					return *(this->_ptr);
				}
				bool	operator==(ReverseIterator<T> const& it) const {
					return this->_ptr == it._ptr;
				}
				bool	operator!=(ReverseIterator<T> const& it) const {
					return this->_ptr != it._ptr;
				}
				bool	operator<(ReverseIterator<T> const& it) const {
					return this->_ptr > it._ptr;
				}
				bool	operator<=(ReverseIterator<T> const& it) const {
					return this->_ptr >= it._ptr;
				}
				bool	operator>(ReverseIterator<T> const& it) const {
					return this->_ptr < it._ptr;
				}
				bool	operator>=(ReverseIterator<T> const& it) const {
					return this->_ptr <= it._ptr;
				}
		};
}

#endif // REVERSE_ITERATOR_HPP
