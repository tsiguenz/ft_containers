/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 19:19:56 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/08/03 16:13:30 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

#include <iostream>
# include "vector.hpp"

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

				explicit stack(Container const& cont = Container())
					: c(cont) { }

				~stack() { };

				// Operators

				stack&	operator=(stack const& rhs) {
					this->c = rhs.c;
					return *this;
				}

				template<class U, class Cont>
					friend bool
					operator==(stack<U, Cont> const& lhs, stack<U, Cont> const& rhs);

				template<class U, class Cont>
					friend bool
					operator<(stack<U, Cont> const& lhs, stack<U, Cont> const& rhs);

				// Member functions

				reference	top()
				{ return this->c.back(); }

				const_reference	top() const
				{ return this->c.back(); }

				bool	empty() const
				{ return this->c.empty(); }

				size_type	size() const
				{ return this->c.size(); }

				void	push(value_type const& value)
				{ this->c.push_back(value); }

				void	pop()
				{ this->c.pop_back(); }

			protected:

				container_type	c;
		};

	// Non member functions

	template<class U, class Cont>
		bool	operator==(stack<U, Cont> const& lhs, stack<U, Cont> const& rhs)
		{ return lhs.c == rhs.c; }

	template<class U, class Cont>
		bool	operator!=(stack<U, Cont> const& lhs, stack<U, Cont> const& rhs)
		{ return !(lhs == rhs); }

	template<class U, class Cont>
		bool	operator<(stack<U, Cont> const& lhs, stack<U, Cont> const& rhs)
		{ return lhs.c < rhs.c; }

	template<class U, class Cont>
		bool	operator<=(stack<U, Cont> const& lhs, stack<U, Cont> const& rhs)
		{ return !(rhs < lhs); }

	template<class U, class Cont>
		bool	operator>(stack<U, Cont> const& lhs, stack<U, Cont>const& rhs)
		{ return rhs < lhs; }

	template<class U, class Cont>
		bool	operator>=(stack<U, Cont> const& lhs, stack<U, Cont> const& rhs)
		{ return !(lhs < rhs); }
}
#endif // STACK_HPP
