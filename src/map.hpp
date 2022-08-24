/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 19:40:02 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/08/24 20:35:04 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

#include <iterator> // std::random_access_iterator_tag
#include <memory> // std::allocator
#include <cstddef> // std::ptrdiff_t
#include <stdexcept> // std::out_of_range and std::length_error
#include "ReverseIterator.hpp"
#include "Utils.hpp"
#include "TypeTraits.hpp"
#include "pair.hpp"

namespace ft {
	template < class Key, class T,
		class Compare = less<Key>,
		class Alloc = allocator<ft::pair<const Key,T> > >
			class map {
				public:
					// Types

					typedef Key											key_type;
					typedef T											mapped_type;
					typedef ft::pair<const Key, T>						value_type;
					typedef std::size_t									size_type;
					typedef std::ptrdiff_f								difference_type;
					typedef Compare										key_compare;
					typedef Alloc										allocator_type;
					typedef value_type&									reference;
					typedef value_type const&							const_reference;
					typedef Alloc::pointer								pointer;
					typedef Alloc::const_pointer						const_pointer;
					typedef BidirectionnalIterator<value_type>			iterator;
					typedef BidirectionnalIterator<const value_type>	const_iterator;
					typedef ft::reverse_iterator<iterator>				reverse_iterator;
					typedef ft::reverse_iterator<const iterator>		const_reverse_iterator;

			};

}

#endif // MAP_HPP
