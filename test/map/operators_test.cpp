/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators_test.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 16:34:33 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/09/21 16:09:58 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	map_operators_test() {
# ifdef REAL
	namespace ft = std;
#endif
	std::cout << "----------  Map operators test : ----------" << std::endl;
	// operator=
	{
		ft::map<char, int>	m1;
		m1.insert(ft::make_pair('a', 12));
		m1.insert(ft::make_pair('c', 42));
		m1.insert(ft::make_pair('z', -3));

		ft::map<char, int>	m2;
		m2 = m1;
		assertEq("size after operator= empty = non empty", m2.size(), (size_t) 3);

		ft::map<char, int>	empty;
		m1 = empty;
		assertEq("size after operator= non empty = empty", m1.size(), (size_t) 0);

		m1.insert(ft::make_pair('x', 888));
		m1.insert(ft::make_pair('y', 88));
		m1.insert(ft::make_pair('v', 8));
		m1.insert(ft::make_pair('u', 9));
		m2 = m1;
		assertEq("size after operator= non empty = non empty", m2.size(), (size_t) 4);
	}
	ft::map<int, int>	a0, a1, a2, a3, a4, a5;

	a0[0] = 42;
	a0[1] = 24;

	a1[0] = 42;
	a1[1] = 24;

	a2[0] = 42;
	a2[1] = 0;

	a3[0] = 42;
	a3[1] = -42;

	a4[0] = 42;

	a5[0] = 42;
	a5[1] = 24;
	a5[2] = 0;

	ft::map<int, int>	b0, b1, b2, b3, b4, b5;

	b0[0] = 42;
	b0[1] = 24;

	b1[0] = 42;
	b1[1] = 24;

	b2[0] = 42;
	b2[1] = 0;

	b3[0] = 42;
	b3[1] = -42;

	b4[0] = 42;

	b5[0] = 42;
	b5[1] = 24;
	b5[2] = 0;

	assertEq("Equal operator (true)", (a1 == a0), (b1 == b0));
	assertEq("Equal operator (false)", (a1 == a2), (b1 == b2));
	assertEq("Equal operator (false)", (a1 == a5), (b1 == b5));

	assertEq("Not equal operator (false)", (a1 != a0), (b1 != b0));
	assertEq("Not equal operator (true)", (a1 != a2), (b1 != b2));
	assertEq("Not equal operator (true)", (a1 != a5), (b1 != b5));

	assertEq("Less than operator (true)", (a2 < a1), (b2 < b1));
	assertEq("Less than operator (false)", (a1 < a2), (b1 < b2));
	assertEq("Less than operator (false)", (a1 < a4), (b1 < b4));
	assertEq("Less than operator (false)", (a1 < a0), (b1 < b0));
	
	assertEq("Less or equal than operator (true)", (a2 <= a1), (b2 <= b1));
	assertEq("Less or equal than operator (false)", (a1 <= a2), (b1 <= b2));
	assertEq("Less or equal than operator (false)", (a1 <= a4), (b1 <= b4));
	assertEq("Less or equal than operator (true)", (a1 <= a0), (b1 <= b0));

	assertEq("Upper than operator (true)", (a5 > a1), (b5 > b1));
	assertEq("Upper than operator (true)", (a1 > a3), (b1 > b3));
	assertEq("Upper than operator (false)", (a4 > a3), (b4 > b3));
	assertEq("Upper than operator (false)", (a1 > a0), (b1 > b0));

	assertEq("Upper or equal than operator (true)", (a5 >= a1), (b5 >= b1));
	assertEq("Upper or equal than operator (true)", (a1 >= a3), (b1 >= b3));
	assertEq("Upper or equal than operator (false)", (a4 >= a3), (b4 >= b3));
	assertEq("Upper or equal than operator (true)", (a1 >= a0), (b1 >= b0));
}
