/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ReverseIterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 11:46:21 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/09/26 17:23:56 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

#include <typeinfo>
#include "IteratorTraits.hpp"

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
				Iterator	_current;

			public:
				// Object managment

				ReverseIterator(): _current() { };

				ReverseIterator(iterator it): _current(it) { }

				ReverseIterator(ReverseIterator const& it): _current(it._current) { }

				template<typename Iter>
					ReverseIterator(ReverseIterator<Iter> const& it): _current(it.base()) { }

				virtual ~ReverseIterator() { }

				iterator	base() const { return this->_current; }

				operator ReverseIterator<Iterator const>() const
				{ return ReverseIterator<Iterator const>(_current); }

				ReverseIterator&	operator=(ReverseIterator const& it){
					_current = it._current;
					return *this;
				}

				ReverseIterator&	operator++(){
					_current--;
					return *this;
				}

				ReverseIterator	operator++(int) {
					ReverseIterator	tmp(_current);
					_current--;
					return tmp;
				}

				ReverseIterator&	operator--() {
					_current++;
					return *this;
				}

				ReverseIterator	operator--(int) {
					Iterator	tmp = Iterator(_current);
					_current++;
					return tmp;
				}

				ReverseIterator	operator+(difference_type const& n) const
				{ return ReverseIterator(_current - n); }

				ReverseIterator&	operator+=(difference_type const& n) {
					_current -= n;
					return *this;
				}

				ReverseIterator	operator-(difference_type const& n) const
				{ return ReverseIterator(_current + n); }

				ReverseIterator&	operator-=(difference_type const& n) {
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
		bool	operator==(ReverseIterator<IteratorL> const& it1,
			ReverseIterator<IteratorR> const& it2)
		{ return it1.base() == it2.base(); }

	template<typename IteratorL, typename IteratorR>
		bool	operator!=(ReverseIterator<IteratorL> const& it1,
			ReverseIterator<IteratorR> const& it2)
		{ return !(it1 == it2); }

	template<typename IteratorL, typename IteratorR>
		bool	operator<(ReverseIterator<IteratorL> const& it1,
			ReverseIterator<IteratorR> const& it2)
		{ return it2.base() < it1.base(); }

	template<typename IteratorL, typename IteratorR>
		bool	operator<=(ReverseIterator<IteratorL> const& it1,
			ReverseIterator<IteratorR> const& it2)
		{ return !(it2 < it1); }

	template<typename IteratorL, typename IteratorR>
		bool	operator>(ReverseIterator<IteratorL> const& it1,
			ReverseIterator<IteratorR> const& it2)
		{ return it2 < it1; }

	template<typename IteratorL, typename IteratorR>
		bool	operator>=(ReverseIterator<IteratorL> const& it1,
			ReverseIterator<IteratorR> const& it2)
		{ return !(it1 < it2); }

	template<typename IteratorL, typename IteratorR>
		typename ReverseIterator<IteratorL>::difference_type
		operator-(ReverseIterator<IteratorL> const& it1,
			ReverseIterator<IteratorR> const& it2)
		{ return it2.base() - it1.base(); }

	template<typename Iterator>
		ReverseIterator<Iterator>
		operator+(typename ReverseIterator<Iterator>::difference_type n,
			ReverseIterator<Iterator> const& it)
		{ return it.base() - n; }
}

#endif // REVERSE_ITERATOR_HPP
