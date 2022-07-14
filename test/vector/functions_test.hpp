/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_test.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 16:49:25 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/07/14 18:49:02 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_TEST_HPP
# define FUNCTIONS_TEST_HPP

// TODO functions tests (don't forget swap)
template<typename T>
void	functionsTest() {
	std::cout << "----------  Functions test : ----------" << std::endl;
	// swap
	{
		ft::vector<T>	a1(5);
		ft::vector<T>	a2;
		ft::vector<T>	a3;

		for (int i = 0; i < 5; i++)
			a1[i] = i * 10;
		ft::vector<T>	a4(a1);
		ft::swap(a1, a2);

		std::vector<T>	b1(5);
		std::vector<T>	b2;
		std::vector<T>	b3;

		for (int i = 0; i < 5; i++)
			a1[i] = i * 10;
		std::vector<T>	b4(b1);
		std::swap(b1, b2);
		assertEq("swap compare first element", (a2 == a4), (b2 == b4));
		assertEq("swap compare second element", (a1 == a3), (b1 == b3));
	}
	// assign
	{
		ft::vector<T>	a1;
		ft::vector<T>	a2;
		std::vector<T>	b1;
		std::vector<T>	b2;

		a1.assign(4, 42);
		a2.assign(a1.begin() + 1, a1.end() - 1);
		b1.assign(4, 42);
		b2.assign(b1.begin() + 1, b1.end() - 1);
		assertEq("assign first overload compare size", a1.size(), b1.size());
		for (int i = 0; i < 4; i++)
			assertEq("assign first overload compare elements", a1[i], b1[i]);
		assertEq("assign second overload compare size", a2.size(), b2.size());
		for (int i = 0; i < 2; i++)
			assertEq("assign second overload compare elements", a2[i], b2[i]);
	}
	// get_allocator
	{
		ft::vector<T>	a;
		std::vector<T>	b;

		assertEq("get_allocator compare allocator", 
				(a.get_allocator() == b.get_allocator()), true);
	}
	// at
	{
		int	nbException = 0;
		ft::vector<T>	a(3);
		std::vector<T>	b(3);
		
		for (int i = 0; i < 3; i++) {
			a.at(i) = i * 10;
			b.at(i) = i * 10;
			assertEq("at test value", a.at(i), b.at(i));
		}
		try { a.at(5); } catch (std::exception const& e) { nbException++; }
		try { b.at(5); } catch (std::exception const& e) { nbException++; }
		assertEq("try to catch an exception with at out of range", nbException, 2);
	}
}

#endif // FUNCTIONS_TEST_HPP
