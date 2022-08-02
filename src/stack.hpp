/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 19:19:56 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/08/03 00:01:35 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

namespace ft {
	template< class T, class Container = ft::vector<T> >
		class stack {
			public:
				// Types

				typedef Container							container_type;
				typedef typename Container::value_type		value_type;
				typedef typename Container::size_type		size_type;
				typedef typename Container::reference		reference;
				typedef typename Container::const_reference	const_reference;

				// Object managment

				// Default
				explicit stack(Container const& cont = Container())
				: c(cont) { }

				virtual ~stack() { };

			protected:

				container_type	c;

			private:

	};
}
#endif // STACK_HPP
