/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_test.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 23:00:02 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/08/03 16:23:41 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_TEST_HPP
# define STACK_TEST_HPP

# include <stack>

# include "stack.hpp"
# include <utils_test.hpp>

void	stack_test() {
# ifdef REAL
	namespace ft = std;
# endif

	ft::stack<int, ft::vector<int> >	s1;
	ft::stack<int, ft::vector<int> >	s2;

	assertEq("empty while container is empty", s1.empty(), true);
	assertEq("size while container is empty", (int) s1.size(), 0);

	s1.push(42);
	s1.push(24);
	s1.push(53);

	assertEq("empty while container is not empty", s1.empty(), false);
	assertEq("size while container is not empty", (int) s1.size(), 3);
	assertEq("top", s1.top(), 53);
	s1.top() = 2;
	assertEq("top after modify value of top()", s1.top(), 2);

	s1.pop();
	assertEq("top after pop", s1.top(), 24);

	// lexicographical compare

	assertEq("equal when not equal", s1 == s2, false);
	assertEq("non equal when not equal", s1 != s2, true);
	s2.push(42);

	assertEq("<", s1 < s2, false);
	assertEq("<=", s1 <= s2, false);
	assertEq(">", s1 > s2, true);
	assertEq(">=", s1 >= s2, true);
	
	s2.push(0);

	assertEq("<", s1 < s2, false);
	assertEq("<=", s1 <= s2, false);
	assertEq(">", s1 > s2, true);
	assertEq(">=", s1 >= s2, true);
	s2.top() = s1.top();
	assertEq("equal when equal", s1 == s2, true);
	assertEq("non equal when equal", s1 != s2, false);
}

#endif // STACK_TEST_HPP
