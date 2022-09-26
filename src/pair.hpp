/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 13:35:44 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/09/26 18:58:34 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
# define PAIR_HPP

namespace ft {
	template<class T1, class T2>
		class pair {
			public:

				typedef T1	first_type;
				typedef T2	second_type;

				first_type	first;
				second_type	second;

				// Object management

				pair(): first(first_type()), second(second_type()) { }

				pair(first_type const& x, second_type const&y)
					: first(x), second(y) { }

				template<class U1, class U2>
					pair(pair<U1, U2> const& p)
					: first(p.first), second(p.second) { }

				~pair() { }

				// Operator
				pair&	operator=(pair const& other) {
					this->first = other.first;
					this->second = other.second;
					return *this;
				}
		};

	// Non member operators

	template<class T1, class T2>
		bool	operator==(pair<T1, T2> const& lhs, pair<T1, T2> const& rhs)
		{ return (lhs.first == rhs.first && lhs.second == rhs.second); }

	template<class T1, class T2>
		bool	operator!=(pair<T1, T2> const& lhs, pair<T1, T2> const& rhs)
		{ return !(lhs == rhs); }

	template<class T1, class T2>
		bool	operator<(pair<T1, T2> const& lhs, pair<T1, T2> const& rhs)
		{ return lhs.first < rhs.first || (!(rhs.first < lhs.first)
			&& lhs.second < rhs.second); }

	template<class T1, class T2>
		bool	operator<=(pair<T1, T2> const& lhs, pair<T1, T2> const& rhs)
		{ return !(rhs < lhs); }

	template<class T1, class T2>
		bool	operator>(pair<T1, T2> const& lhs, pair<T1, T2> const& rhs)
		{ return rhs < lhs; }

	template<class T1, class T2>
		bool	operator>=(pair<T1, T2> const& lhs, pair<T1, T2> const& rhs)
		{ return !(lhs < rhs); }

	// Make pair

	template<class T1, class T2>
		pair<T1, T2>	make_pair(T1 x, T2 y)
		{ return pair<T1, T2>(x, y); }
}

#endif // PAIR_HPP
