/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators_test.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 16:07:55 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/08/03 16:23:02 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATORS_TEST_HPP
# define OPERATORS_TEST_HPP

template<typename T>
void	operatorsTest() {
# ifdef REAL
	namespace ft = std;
#endif
	std::cout << "----------  Operators : ----------" << std::endl;
	ft::vector<T>	a0, a1, a2, a3, a4, a5;

	a0.push_back(42);
	a0.push_back(24);

	a1.push_back(42);
	a1.push_back(24);

	a2.push_back(42);
	a2.push_back(0);

	a3.push_back(42);
	a3.push_back(-42);

	a4.push_back(42);

	a5.push_back(42);
	a5.push_back(24);
	a5.push_back(0);

	std::vector<T>	b0, b1, b2, b3, b4, b5;

	b0.push_back(42);
	b0.push_back(24);

	b1.push_back(42);
	b1.push_back(24);

	b2.push_back(42);
	b2.push_back(0);

	b3.push_back(42);
	b3.push_back(-42);

	b4.push_back(42);

	b5.push_back(42);
	b5.push_back(24);
	b5.push_back(0);

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

#endif // OPERATORS_TEST_HPP
