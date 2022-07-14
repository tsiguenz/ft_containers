/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EnableIf.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 13:37:24 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/07/14 12:01:13 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENABLE_IF_HPP
# define ENABLE_IF_HPP

namespace ft {
	template<bool, typename T = void>
		struct	enable_if { };

	template<typename T>
		struct	enable_if<true, T> {
			typedef T	type;
		};
}

#endif // ENABLE_IF_HPP
