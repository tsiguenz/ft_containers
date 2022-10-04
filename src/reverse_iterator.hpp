/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 11:46:21 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/10/04 16:43:04 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

#include <typeinfo>
#include "IteratorTraits.hpp"

namespace ft {
	template < typename Iterator >
		class reverse_iterator { 
			public:
				// Types
				typedef Iterator								iterator;
				typedef typename Iterator::difference_type		difference_type;
				typedef typename Iterator::value_type			value_type;
				typedef typename Iterator::pointer				pointer;
				typedef typename Iterator::reference			reference;
				typedef typename Iterator::iterator_category	iterator_category;

			private:
				Iterator	_current;

			public:
				// Object managment

				reverse_iterator(): _current() { };

				reverse_iterator(iterator it): _current(it) { }

				reverse_iterator(reverse_iterator const& it): _current(it._current) { }

				template<typename Iter>
					reverse_iterator(reverse_iterator<Iter> const& it): _current(it.base()) { }

				virtual ~reverse_iterator() { }

				iterator	base() const { return this->_current; }

				operator reverse_iterator<Iterator const>() const
				{ return reverse_iterator<Iterator const>(_current); }

				reverse_iterator&	operator=(reverse_iterator const& it){
					_current = it._current;
					return *this;
				}

				reverse_iterator&	operator++(){
					_current--;
					return *this;
				}

				reverse_iterator	operator++(int) {
					reverse_iterator	tmp(_current);
					_current--;
					return tmp;
				}

				reverse_iterator&	operator--() {
					_current++;
					return *this;
				}

				reverse_iterator	operator--(int) {
					Iterator	tmp = Iterator(_current);
					_current++;
					return tmp;
				}

				reverse_iterator	operator+(difference_type const& n) const
				{ return reverse_iterator(_current - n); }

				reverse_iterator&	operator+=(difference_type const& n) {
					_current -= n;
					return *this;
				}

				reverse_iterator	operator-(difference_type const& n) const
				{ return reverse_iterator(_current + n); }

				reverse_iterator&	operator-=(difference_type const& n) {
					_current += n;
					return *this;
				}

				reference	operator[](difference_type const& n) const
				{ return *(*this + n); }

				reference	operator*() const {
					iterator	tmp = Iterator(_current);
					return *--tmp;
				}

				pointer	operator->() const
				{ return &(operator*()); }
		};

	template<typename IteratorL, typename IteratorR>
		bool	operator==(reverse_iterator<IteratorL> const& it1,
			reverse_iterator<IteratorR> const& it2)
		{ return it1.base() == it2.base(); }

	template<typename IteratorL, typename IteratorR>
		bool	operator!=(reverse_iterator<IteratorL> const& it1,
			reverse_iterator<IteratorR> const& it2)
		{ return !(it1 == it2); }

	template<typename IteratorL, typename IteratorR>
		bool	operator<(reverse_iterator<IteratorL> const& it1,
			reverse_iterator<IteratorR> const& it2)
		{ return it2.base() < it1.base(); }

	template<typename IteratorL, typename IteratorR>
		bool	operator<=(reverse_iterator<IteratorL> const& it1,
			reverse_iterator<IteratorR> const& it2)
		{ return !(it2 < it1); }

	template<typename IteratorL, typename IteratorR>
		bool	operator>(reverse_iterator<IteratorL> const& it1,
			reverse_iterator<IteratorR> const& it2)
		{ return it2 < it1; }

	template<typename IteratorL, typename IteratorR>
		bool	operator>=(reverse_iterator<IteratorL> const& it1,
			reverse_iterator<IteratorR> const& it2)
		{ return !(it1 < it2); }

	template<typename IteratorL, typename IteratorR>
		typename reverse_iterator<IteratorL>::difference_type
		operator-(reverse_iterator<IteratorL> const& it1,
			reverse_iterator<IteratorR> const& it2)
		{ return it2.base() - it1.base(); }

	template<typename Iterator>
		reverse_iterator<Iterator>
		operator+(typename reverse_iterator<Iterator>::difference_type n,
			reverse_iterator<Iterator> const& it)
		{ return it.base() - n; }
}

#endif // REVERSE_ITERATOR_HPP
