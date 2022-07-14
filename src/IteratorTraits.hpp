/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IteratorTraits.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 12:10:12 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/07/14 12:32:18 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAITS_HPP
# define ITERATOR_TRAITS_HPP

namespace ft {
	template<class Iterator>
	struct iterator_traits {
		typedef typename Iterator::difference_type			difference_type;
		typedef typename Iterator::value_type				value_type;
		typedef typename Iterator::pointer					pointer;
		typedef typename Iterator::reference				reference;
		typedef typename Iterator::iterator_category		iterator_category;
	};

	template<typename T>
	struct iterator_traits<T*> {
		typedef std::ptrdiff_t						difference_type;
		typedef T									value_type;
		typedef T*									pointer;
		typedef T&									reference;
		typedef std::random_access_iterator_tag	iterator_category;

	};

	template<typename T>
	struct iterator_traits<const T*> {
		typedef std::ptrdiff_t						difference_type;
		typedef T									value_type;
		typedef T const*							pointer;
		typedef T const&							reference;
		typedef std::random_access_iterator_tag	iterator_category;
	};
}

#endif // ITERATOR_TRAITS_HPP
