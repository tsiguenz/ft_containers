/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TypeTraits.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 15:03:55 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/07/05 16:51:56 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_TRAITS_HPP
# define TYPE_TRAITS_HPP

namespace ft {
	template<class T, T v>
	struct	integral_constant {
		static T const	value = v;
		typedef T	value_type;
		typedef integral_constant<T, v>	type;
		operator const	T() { return v; }
	};

	typedef	integral_constant<bool, true>	true_type;
	typedef	integral_constant<bool, false>	false_type;

	template<typename> struct is_integral_base: false_type { };
	template<> struct is_integral_base<bool>: true_type { };
	template<> struct is_integral_base<char>: true_type { };
	template<> struct is_integral_base<wchar_t>: true_type { };
	template<> struct is_integral_base<signed char>: true_type { };
	template<> struct is_integral_base<short int>: true_type { };
	template<> struct is_integral_base<int>: true_type { };
	template<> struct is_integral_base<long int>: true_type { };
	template<> struct is_integral_base<long long int>: true_type { };
	template<> struct is_integral_base<unsigned char>: true_type { };
	template<> struct is_integral_base<unsigned short int>: true_type { };
	template<> struct is_integral_base<unsigned int>: true_type { };
	template<> struct is_integral_base<unsigned long int>: true_type { };
	template<> struct is_integral_base<unsigned long long int>: true_type { };

	template<class T> struct is_integral: is_integral_base<T> { };
}
#endif // TYPE_TRAITS_HPP
