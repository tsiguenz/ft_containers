/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair_test.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 14:01:38 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/08/24 15:45:44 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "pair.hpp"

void	pair_test() {
#ifdef REAL
	namespace ft = std;
#endif

	// object managment
	ft::pair<int, std::string>		p1;
	ft::pair<int, std::string>		p2(42, "hello");
	ft::pair<short, std::string>	p3(p2);
	ft::pair<int, std::string>		p4(42, "hella");

	assertEq("pair default constructor first", p1.first, int());
	assertEq("pair default constructor second", p1.second, std::string());
	assertEq("pair assignation constructor first", p2.first, 42);
	assertEq("pair assignation constructor second", p2.second, std::string("hello"));
	assertEq("pair copy constructor first", p3.first, (short) 42);
	assertEq("pair copy constructor second", p3.second, std::string("hello"));

	// operators
	assertEq("pair operator== when not equal", p1 == p2, false);
	assertEq("pair operator== when equal", p2 == p2, true);

	assertEq("pair operator!= when not equal", p1 != p2, true);
	assertEq("pair operator!= when equal", p2 != p2, false);

	assertEq("pair operator< when p4 < p2", p4 < p2, true);
	assertEq("pair operator< when p2 < p4", p2 < p4, false);
	assertEq("pair operator< when p1 < p2", p1 < p2, true);

	assertEq("pair operator<= when p4 <= p2", p4 <= p2, true);
	assertEq("pair operator<= when p2 <= p4", p2 <= p4, false);
	assertEq("pair operator<= when p1 <= p2", p1 <= p2, true);
	assertEq("pair operator<= when p2 <= p2", p2 <= p2, true);

	assertEq("pair operator> when p4 > p2", p4 > p2, false);
	assertEq("pair operator> when p2 > p4", p2 > p4, true);
	assertEq("pair operator> when p1 > p2", p1 > p2, false);

	assertEq("pair operator>= when p4 >= p2", p4 >= p2, false);
	assertEq("pair operator>= when p2 >= p4", p2 >= p4, true);
	assertEq("pair operator>= when p1 >= p2", p1 >= p2, false);
	assertEq("pair operator>= when p2 >= p2", p2 >= p2, true);

	// make_pair

	ft::pair<int, int>	foo;
	ft::pair<int, int>	bar;

	foo = ft::make_pair(10, 20);
	bar = ft::make_pair(10.5, 'A');

	assertEq("make_pair no conversion first", foo.first, 10);
	assertEq("make_pair no conversion second", foo.second, 20);
	assertEq("make_pair with conversion first", bar.first, 10);
	assertEq("make_pair with conversion second", bar.second, 65);
}
