/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ReverseIterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 11:46:21 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/07/28 11:28:04 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

#include <typeinfo>
#include <IteratorTraits.hpp>

namespace ft {
	template < typename Iterator >
		class ReverseIterator { 
			public:
				// Types
				typedef Iterator								iterator;
				typedef typename Iterator::difference_type		difference_type;
				typedef typename Iterator::value_type			value_type;
				typedef typename Iterator::pointer				pointer;
				typedef typename Iterator::reference			reference;
				typedef typename Iterator::iterator_category	iterator_category;

			private:
				Iterator	_base;

			public:
				// Object managment
				ReverseIterator(): _base() { };
				ReverseIterator(iterator it): _base(it) { }
				ReverseIterator(ReverseIterator<Iterator> const& it) { *this = it; }
				virtual ~ReverseIterator() { }

				iterator	base() const { return this->_base; }

				// Operators
				operator ReverseIterator<Iterator const>() {
					return ReverseIterator<Iterator const>(this->_base);
				}

				ReverseIterator&	operator=(ReverseIterator const& it){
					this->_base = it._base;
					return *this;
				}

				ReverseIterator&	operator++(){
					this->_base--;
					return *this;
				}

				ReverseIterator	operator++(int) {
					ReverseIterator<Iterator>	tmp = *this;
					this->_base--;
					return tmp;
				}

				ReverseIterator&	operator--() {
					this->_base++;
					return *this;
				}

				ReverseIterator	operator--(int) {
					ReverseIterator<Iterator>	tmp = *this;
					this->_base++;
					return tmp;
				}

				ReverseIterator	operator+(difference_type const& n) const {
					return this->_base - n;
				}

				ReverseIterator&	operator+=(difference_type const& n) {
					this->_base -= n;
					return *this;
				}

				ReverseIterator	operator-(difference_type const& n) const {
					return this->_base + n;
				}

				ReverseIterator&	operator-=(difference_type const& n) {
					this->_base += n;
					return *this;
				}

				reference	operator[](difference_type const& n) {
					return *(this->_base + n);
				}

				reference	operator*() {
					return *(this->_base);
				}

				pointer	operator->() {
					return this->_base;
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
