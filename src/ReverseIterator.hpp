/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ReverseIterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 11:46:21 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/07/26 23:22:33 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

#include <typeinfo>
#include <IteratorTraits.hpp>

namespace ft {
	template < typename T >
		class ReverseIterator { 
			public:
				// Types
				typedef T													iterator_type;
				typedef typename ft::iterator_traits<T*>::difference_type	difference_type;
				typedef typename ft::iterator_traits<T*>::value_type		value_type;
				typedef typename ft::iterator_traits<T*>::pointer			pointer;
				typedef typename ft::iterator_traits<T*>::reference			reference;
				typedef typename ft::iterator_traits<T*>::iterator_category	iterator_category;

			private:
				T*	_ptr;

			public:
				// Object managment
				ReverseIterator(): _ptr() { };
				ReverseIterator(pointer ptr): _ptr(ptr) { }
				ReverseIterator(RandomAccessIterator<T> it): _ptr(it.base()) { }
				ReverseIterator(ReverseIterator<T> const& it) { *this = it; }
				virtual ~ReverseIterator() { }

				pointer	base() const { return this->_ptr; }

				// Operators
				operator ReverseIterator<T const>() {
					return ReverseIterator<T const>(this->_ptr);
				}

				ReverseIterator&	operator=(ReverseIterator const& it){
					this->_ptr = it._ptr;
					return *this;
				}

				ReverseIterator&	operator++(){
					this->_ptr--;
					return *this;
				}

				ReverseIterator	operator++(int) {
					ReverseIterator<T>	tmp = *this;
					this->_ptr--;
					return tmp;
				}

				ReverseIterator&	operator--() {
					this->_ptr++;
					return *this;
				}

				ReverseIterator	operator--(int) {
					ReverseIterator<T>	tmp = *this;
					this->_ptr++;
					return tmp;
				}

				ReverseIterator	operator+(difference_type const& n) const {
					return this->_ptr - n;
				}

				ReverseIterator&	operator+=(difference_type const& n) {
					this->_ptr -= n;
					return *this;
				}

				ReverseIterator	operator-(difference_type const& n) const {
					return this->_ptr + n;
				}

				ReverseIterator&	operator-=(difference_type const& n) {
					this->_ptr += n;
					return *this;
				}

				reference	operator[](difference_type const& n) {
					return *(this->_ptr + n);
				}

				reference	operator*() {
					return *(this->_ptr);
				}

				pointer	operator->() {
					return this->_ptr;
				}
		};

	template<typename T, typename U>
		bool	operator==(ReverseIterator<T> const& it1,
				ReverseIterator<U> const& it2) {
			return it1.base() == it2.base();
		}

	template<typename T, typename U>
		bool	operator!=(ReverseIterator<T> const& it1,
				ReverseIterator<U> const& it2) {
			return it1.base() != it2.base();
		}

	template<typename T, typename U>
		bool	operator<(ReverseIterator<T> const& it1,
				ReverseIterator<U> const& it2) {
			return it1.base() > it2.base();
		}

	template<typename T, typename U>
		bool	operator<=(ReverseIterator<T> const& it1,
				ReverseIterator<U> const& it2) {
			return it1.base() >= it2.base();
		}

	template<typename T, typename U>
		bool	operator>(ReverseIterator<T> const& it1,
				ReverseIterator<U> const& it2) {
			return it1.base() < it2.base();
		}

	template<typename T, typename U>
		bool	operator>=(ReverseIterator<T> const& it1,
				ReverseIterator<U> const& it2) {
			return it1.base() <= it2.base();
		}

	template<typename T, typename U>
		typename ReverseIterator<T>::difference_type
		operator-(ReverseIterator<T> const& it1, ReverseIterator<U> const& it2) {
			return it1.base() + it2.base();
		}

	template<typename T>
		ReverseIterator<T>
		operator-(typename ReverseIterator<T>::difference_type n,
				RandomAccessIterator<T> const& it) {
			return (it - n);
		}

	template<typename T, typename U>
		typename ReverseIterator<T>::difference_type
		operator+(ReverseIterator<T> const& it1, ReverseIterator<U> const& it2) {
			return it1.base() - it2.base();
		}

	template<typename T>
		ReverseIterator<T>
		operator+(typename ReverseIterator<T>::difference_type const& n,
				ReverseIterator<T> const& it) {
			return (it + n);
		}
}

#endif // REVERSE_ITERATOR_HPP
