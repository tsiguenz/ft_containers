/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iterators.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 11:46:21 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/06/28 21:35:25 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATORS_HPP
# define ITERATORS_HPP

#include <typeinfo>
namespace ft {
	template < typename T >
		struct RandomAccessIterator { 
		// Types
			typedef typename std::iterator_traits<T*>::difference_type		difference_type;
			typedef typename std::iterator_traits<T*>::value_type			value_type;
			typedef typename std::iterator_traits<T*>::pointer				pointer;
			typedef typename std::iterator_traits<T*>::reference			reference;
			typedef typename std::iterator_traits<T*>::iterator_category	iterator_category;

		// Member
			pointer	ptr;
		
		// Object managment
			RandomAccessIterator(): ptr() { };
			RandomAccessIterator(T* pointer): ptr(pointer) { }
			RandomAccessIterator(RandomAccessIterator const& it) { *this = it; }
			~RandomAccessIterator() { }

		// Operators
			RandomAccessIterator<T>&	operator=(RandomAccessIterator<T> const& it){
				this->ptr = it.ptr;
				return *this;
			}
			RandomAccessIterator<T>&	operator++(){
				this->ptr++;
				return *this;
			}
			RandomAccessIterator<T>	operator++(int) {
				RandomAccessIterator<T>	tmp = *this;
				++(*this);
				return tmp;
			}
			RandomAccessIterator<T>&	operator--() {
				this->ptr--;
				return *this;
			}
			RandomAccessIterator<T>	operator--(int) {
				RandomAccessIterator<T>	tmp = *this;
				--(*this);
				return tmp;
			}
			RandomAccessIterator<T>	operator+(difference_type const& n) {
				return this->ptr + n;
			}
			RandomAccessIterator<T>&	operator+=(difference_type const& n) {
				this->ptr += n;
				return *this;
			}
			RandomAccessIterator<T>	operator-(difference_type const& n) {
				return this->ptr - n;
			}
			RandomAccessIterator<T>&	operator-=(difference_type const& n) {
				this->ptr -= n;
				return *this;
			}
			T&	operator*() {
				return *(this->ptr);
			}
			bool	operator==(RandomAccessIterator<T> const& it) const {
				return this->ptr == it.ptr;
			}
			bool	operator!=(RandomAccessIterator<T> const& it) const {
				return this->ptr != it.ptr;
			}
			bool	operator<(RandomAccessIterator<T> const& it) const {
				return this->ptr < it.ptr;
			}
			bool	operator<=(RandomAccessIterator<T> const& it) const {
				return this->ptr <= it.ptr;
			}
			bool	operator>(RandomAccessIterator<T> const& it) const {
				return this->ptr > it.ptr;
			}
			bool	operator>=(RandomAccessIterator<T> const& it) const {
				return this->ptr >= it.ptr;
			}
		};
}

#endif // ITERATORS_HPP
