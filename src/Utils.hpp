/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 14:09:47 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/07/28 15:24:42 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

namespace ft {
	template<bool, typename T = void>
		struct	enable_if { };

	template<typename T>
		struct	enable_if<true, T> {
			typedef T	type;
		};

	template<typename InputIterator>
		typename ft::iterator_traits<InputIterator>::difference_type
		distance(InputIterator it, InputIterator ite) {
			typename ft::iterator_traits<InputIterator>::difference_type	res = 0;

			for (;it != ite; it++)
				res++;
			return res;
		}

	template<class InputIterator1, class InputIterator2>
		bool	equal  (InputIterator1 first1, InputIterator1 last1,
				InputIterator2 first2) {
			while (first1 != last1) {
				if (*first1 != *first2)
					return false;
				first1++;
				first2++;
			}
			return true;
		}

	template<class InputIterator1, class InputIterator2, class BinaryPredicate>
		bool	equal  (InputIterator1 first1, InputIterator1 last1,
				InputIterator2 first2, BinaryPredicate pred) {
			while (first1 != last1) {
				if (pred(*first1, *first2) == false)
					return false;
				first1++;
				first2++;
			}
			return true;
		}

	template<class InputIterator1, class InputIterator2>
		bool	lexicographical_compare(InputIterator1 first1, InputIterator1 last1,
				InputIterator2 first2, InputIterator2 last2) {
			while (first1 != last1) {
				if (first2 == last2 || *first2 < *first1)
					return false;
				else if (*first1 < *first2)
					return true;
				first1++;
				first2++;
			}			
			return (first2 != last2);
		}

	template<class InputIterator1, class InputIterator2, class Compare>
		bool	lexicographical_compare(InputIterator1 first1, InputIterator1 last1,
				InputIterator2 first2, InputIterator2 last2,
				Compare comp) {
			while (first1 != last1) {
				if (first2 == last2 || comp(*first2, *first1))
					return false;
				else if (comp(*first1, *first2))
					return true;
				first1++;
				first2++;
			}			
			return (first2 != last2);
		}
}

#endif // UTILS_HPP
