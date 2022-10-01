/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RandomAccessIterator.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 11:46:21 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/10/02 01:11:02 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

# include <typeinfo>
# include "IteratorTraits.hpp"

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
				RandomAccessIterator(RandomAccessIterator const& it): _ptr(it.base()) { }
				virtual ~RandomAccessIterator() { }

				pointer	base() const { return this->_ptr; }

				// Operators
				operator RandomAccessIterator<T const>() const
				{ return RandomAccessIterator<T const>(this->_ptr); }

				RandomAccessIterator&	operator=(RandomAccessIterator const& it){
					this->_ptr = it._ptr;
					return *this;
				}

				RandomAccessIterator&	operator++(){
					++this->_ptr;
					return *this;
				}

				RandomAccessIterator	operator++(int)
				{ return RandomAccessIterator(this->_ptr++); }

				RandomAccessIterator&	operator--() {
					--this->_ptr;
					return *this;
				}

				RandomAccessIterator	operator--(int)
				{ return RandomAccessIterator(this->_ptr--); }

				RandomAccessIterator	operator+(difference_type const& n) const
				{ return RandomAccessIterator(this->_ptr + n); }

				RandomAccessIterator&	operator+=(difference_type const& n) {
					this->_ptr += n;
					return *this;
				}

				RandomAccessIterator	operator-(difference_type n) const
				{ return this->_ptr - n; }

				RandomAccessIterator&	operator-=(difference_type const& n) {
					this->_ptr -= n;
					return *this;
				}

				reference	operator[](difference_type const& n)
				{ return this->_ptr[n]; }

				reference	operator*() const
				{ return *(this->_ptr); }

				pointer	operator->() const
				{ return this->_ptr; }
		};

	template<typename IteratorL, typename IteratorR>
		bool	operator==(RandomAccessIterator<IteratorL> const& it1,
			RandomAccessIterator<IteratorR> const& it2)
		{ return it1.base() == it2.base(); }

	template<typename IteratorL, typename IteratorR>
		bool	operator!=(RandomAccessIterator<IteratorL> const& it1,
			RandomAccessIterator<IteratorR> const& it2)
		{ return !(it1.base() == it2.base()); }

	template<typename IteratorL, typename IteratorR>
		bool	operator<(RandomAccessIterator<IteratorL> const& it1,
			RandomAccessIterator<IteratorR> const& it2)
		{ return it1.base() < it2.base(); }

	template<typename IteratorL, typename IteratorR>
		bool	operator<=(RandomAccessIterator<IteratorL> const& it1,
			RandomAccessIterator<IteratorR> const& it2)
		{ return !(it2 < it1); }

	template<typename IteratorL, typename IteratorR>
		bool	operator>(RandomAccessIterator<IteratorL> const& it1,
			RandomAccessIterator<IteratorR> const& it2)
		{ return it2 < it1; }

	template<typename IteratorL, typename IteratorR>
		bool	operator>=(RandomAccessIterator<IteratorL> const& it1,
			RandomAccessIterator<IteratorR> const& it2)
		{ return !(it1 < it2); }

	template<typename IteratorL, typename IteratorR>
		typename RandomAccessIterator<IteratorL>::difference_type
		operator-(RandomAccessIterator<IteratorL> const& it1,
			RandomAccessIterator<IteratorR> const& it2)
		{ return it1.base() - it2.base(); }

	template<typename Iterator>
		RandomAccessIterator<Iterator>
		operator+(typename RandomAccessIterator<Iterator>::difference_type n,
			RandomAccessIterator<Iterator> const& it)
		{ return RandomAccessIterator<Iterator>(it.base() + n); }
}

#endif // RANDOM_ACCESS_ITERATOR_HPP
