/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ReverseIterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 11:46:21 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/07/29 17:43:43 by tsiguenz         ###   ########.fr       */
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

			protected:
				Iterator	current;

			public:
				// Object managment
				ReverseIterator(): current() { };
				ReverseIterator(iterator it): current(it) { }
				ReverseIterator(ReverseIterator const& it): current(it.current) { }
				template<typename Iter>
					ReverseIterator(ReverseIterator<Iter> const& it): current(it.base()) { }
				virtual ~ReverseIterator() { }

				iterator	base() const { return this->current; }

				operator ReverseIterator<Iterator const>() const
				{ return ReverseIterator<Iterator const>(this->_ptr); }

				ReverseIterator&	operator=(ReverseIterator const& it){
					this->current = it.current;
					return *this;
				}

				ReverseIterator&	operator++(){
					this->current--;
					return *this;
				}

				ReverseIterator	operator++(int) {
					ReverseIterator<Iterator>	tmp = *this;
					this->current--;
					return tmp;
				}

				ReverseIterator&	operator--() {
					this->current++;
					return *this;
				}

				ReverseIterator	operator--(int) {
					ReverseIterator<Iterator>	tmp = *this;
					this->current++;
					return tmp;
				}

				ReverseIterator	operator+(difference_type const& n) const
				{ return ReverseIterator(this->current - n); }

				ReverseIterator&	operator+=(difference_type const& n) {
					this->current -= n;
					return *this;
				}

				ReverseIterator	operator-(difference_type const& n) const
				{ return ReverseIterator(this->current + n); }

				ReverseIterator&	operator-=(difference_type const& n) {
					this->current += n;
					return *this;
				}

				reference	operator[](difference_type const& n) const
				{ return *(*this + n); }

				reference	operator*() const {
					iterator	tmp = this->current;
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
