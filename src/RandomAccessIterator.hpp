/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RandomAccessIterator.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 11:46:21 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/07/26 23:22:26 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

#include <typeinfo>
#include <IteratorTraits.hpp>

namespace ft {
	template < typename T >
		class RandomAccessIterator { 
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
				RandomAccessIterator(): _ptr() { };
				RandomAccessIterator(pointer ptr): _ptr(ptr) { }
				//RandomAccessIterator(ReverseIterator<T> it): _ptr(it.base()) { }
				RandomAccessIterator(RandomAccessIterator<T> const& it) { *this = it; }
				virtual ~RandomAccessIterator() { }

				pointer	base() const { return this->_ptr; }

				// Operators
				operator RandomAccessIterator<T const>() const {
					return RandomAccessIterator<T const>(this->_ptr);
				}

				RandomAccessIterator&	operator=(RandomAccessIterator const& it){
					this->_ptr = it._ptr;
					return *this;
				}

				RandomAccessIterator&	operator++(){
					this->_ptr++;
					return *this;
				}

				RandomAccessIterator	operator++(int) {
					RandomAccessIterator<T>	tmp = *this;
					this->_ptr++;
					return tmp;
				}

				RandomAccessIterator&	operator--() {
					this->_ptr--;
					return *this;
				}

				RandomAccessIterator	operator--(int) {
					RandomAccessIterator<T>	tmp = *this;
					this->_ptr--;
					return tmp;
				}

				RandomAccessIterator	operator+(difference_type const& n) const {
					return this->_ptr + n;
				}

				RandomAccessIterator&	operator+=(difference_type const& n) {
					this->_ptr += n;
					return *this;
				}

				RandomAccessIterator	operator-(difference_type n) const {
					return this->_ptr - n;
				}

				RandomAccessIterator&	operator-=(difference_type const& n) {
					this->_ptr -= n;
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
		bool	operator==(RandomAccessIterator<T> const& it1,
				RandomAccessIterator<U> const& it2) {
			return it1.base() == it2.base();
		}

	template<typename T, typename U>
		bool	operator!=(RandomAccessIterator<T> const& it1,
				RandomAccessIterator<U> const& it2) {
			return it1.base() != it2.base();
		}

	template<typename T, typename U>
		bool	operator<(RandomAccessIterator<T> const& it1,
				RandomAccessIterator<U> const& it2) {
			return it1.base() < it2.base();
		}

	template<typename T, typename U>
		bool	operator<=(RandomAccessIterator<T> const& it1,
				RandomAccessIterator<U> const& it2) {
			return it1.base() <= it2.base();
		}

	template<typename T, typename U>
		bool	operator>(RandomAccessIterator<T> const& it1,
				RandomAccessIterator<U> const& it2) {
			return it1.base() > it2.base();
		}

	template<typename T, typename U>
		bool	operator>=(RandomAccessIterator<T> const& it1,
				RandomAccessIterator<U> const& it2) {
			return it1.base() >= it2.base();
		}

	template<typename T, typename U>
		typename RandomAccessIterator<T>::difference_type
		operator-(RandomAccessIterator<T> const& it1, RandomAccessIterator<U> const& it2) {
			return it1.base() - it2.base();
		}

	template<typename T>
		RandomAccessIterator<T>
		operator-(typename RandomAccessIterator<T>::difference_type n,
				RandomAccessIterator<T> const& it) {
			return (it - n);
		}

	template<typename T, typename U>
		typename RandomAccessIterator<T>::difference_type
		operator+(RandomAccessIterator<T> const& it1, RandomAccessIterator<U> const& it2) {
			return it1.base() + it2.base();
		}

	template<typename T>
		RandomAccessIterator<T>
		operator+(typename RandomAccessIterator<T>::difference_type const& n,
				RandomAccessIterator<T> const& it) {
			return (it + n);
		}
}

#endif // RANDOM_ACCESS_ITERATOR_HPP
