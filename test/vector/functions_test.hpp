/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_test.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 16:49:25 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/07/15 18:04:45 by tsiguenz         ###   ########.fr       */
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
			b1[i] = i * 10;
		std::vector<T>	b4(b1);
		std::swap(b1, b2);
		assertEq("swap compare first element", (a2 == a4), (b2 == b4));
		assertEq("swap compare second element", (a1 == a3), (b1 == b3));
		assertEq("size after swap", a1.size(), b1.size());
		assertEq("size after swap", a2.size(), b2.size());
		assertEq("capacity after swap", a1.capacity(), b1.capacity());
		assertEq("capacity after swap", a2.capacity(), b2.capacity());
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
		assertEq("assign first overload compare capacity", a1.capacity(), b1.capacity());
		for (int i = 0; i < 4; i++)
			assertEq("assign first overload compare elements", a1[i], b1[i]);
		assertEq("assign second overload compare size", a2.size(), b2.size());
		assertEq("assign second overload compare capacity", a2.capacity(), b2.capacity());
		for (int i = 0; i < 2; i++)
			assertEq("assign second overload compare elements", a2[i], b2[i]);
		a1.assign(2, 12);
		b1.assign(2, 12);
		a2.assign(a1.begin() + 1, a1.end());
		b2.assign(b1.begin() + 1, b1.end());
		assertEq("assign a second time first overload compare size", a1.size(), b1.size());
		assertEq("assign a second time first overload compare capacity", a1.capacity(), b1.capacity());
		for (int i = 0; i < 2; i++)
			assertEq("assign a second time first overload compare elements", a1[i], b1[i]);
		assertEq("assign a second time second overload compare size", a2.size(), b2.size());
		assertEq("assign a second time second overload compare capacity", a2.capacity(), b2.capacity());
		for (int i = 0; i < 1; i++)
			assertEq("assign a second time second overload compare elements", a2[i], b2[i]);
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
		try { a.at(-1); } catch (std::exception const& e) { nbException++; }
		try { b.at(-1); } catch (std::exception const& e) { nbException++; }
		const ft::vector<T>		c(a);
		const std::vector<T>	d(b);
		for (int i = 0; i < 3; i++) {
			assertEq("at const test value", c.at(i), d.at(i));
		}
		try { c.at(5); } catch (std::exception const& e) { nbException++; }
		try { d.at(5); } catch (std::exception const& e) { nbException++; }
		try { c.at(-1); } catch (std::exception const& e) { nbException++; }
		try { d.at(-1); } catch (std::exception const& e) { nbException++; }
		assertEq("Exception handling in at and const at", nbException, 8);
	}
	// operator []
	{
		ft::vector<T>	a(3);
		std::vector<T>	b(3);

		for (int i = 0; i < 3; i++) {
			a[i] = i * 10;
			b[i] = i * 10;
			assertEq("operator [] test value", a[i], b[i]);
		}
		const ft::vector<T>		c(a);
		const std::vector<T>	d(b);
		for (int i = 0; i < 3; i++) {
			assertEq("operator [] const test value", c[i], d[i]);
		}
	}
	// front / back / data
	{
		ft::vector<T>	a(3);
		std::vector<T>	b(3);

		for (int i = 0; i < 3; i++) {
			a[i] = i * 10;
			b[i] = i * 10;
		}
		assertEq("front value", a.front(), b.front());
		assertEq("back value", a.back(), b.back());
		const ft::vector<T>		c(a);
		const std::vector<T>	d(b);
		assertEq("front const  value", c.front(), d.front());
		assertEq("back const value", c.back(), d.back());
		T*	p1 = a.data();
		T*	p2 = b.data();
		T const*	p3 = c.data();
		T const*	p4 = d.data();
		for (int i = 0; i < 3; i++) {
			assertEq("data compare", p1[i], p2[i]);
			assertEq("data const compare", p3[i], p4[i]);
		}
	}
	// empty / size / max_size / capacity
	{
		ft::vector<T>	a;
		std::vector<T>	b;
		ft::vector<T>	c(3);
		std::vector<T>	d(3);
		assertEq("empty of empty vector", a.empty(), b.empty());
		a.reserve(10);
		b.reserve(10);
		assertEq("empty of empty vector but reserve(10)", a.empty(), b.empty());
		assertEq("empty of non empty vector", c.empty(), d.empty());
		assertEq("size of empty vector", a.size(), b.size());
		assertEq("size of non empty vector", c.size(), d.size());
		assertEq("max_size", a.max_size(), b.max_size());
		assertEq("capacity of empty vector", a.capacity(), b.capacity());
		assertEq("capacity of non empty vector", c.capacity(), d.capacity());
	}
	// reserve / clear
	{
		ft::vector<T>	a(3, 42);
		std::vector<T>	b(3, 42);

		a.reserve(5);
		b.reserve(5);
		assertEq("reserve size", a.size(), b.size());
		assertEq("reserve capacity", a.capacity(), b.capacity());
		a.reserve(4);
		b.reserve(4);
		assertEq("check size reserve(4) on vector capacity = 5", a.size(), b.size());
		assertEq("check capacity reserve(4) on vector capacity = 5", a.capacity(), b.capacity());
		a.reserve(1);
		b.reserve(1);
		assertEq("check size reserve(1) on vector capacity = 5", a.size(), b.size());
		assertEq("check capacity reserve(1) on vector capacity = 5", a.capacity(), b.capacity());
		a.clear();
		b.clear();
		assertEq("check vector is empty after clear", a.empty(), b.empty());
		assertEq("check vector capacity after clear", a.capacity(), b.capacity());
		assertEq("check vector size after clear", a.size(), b.size());
		
	}
//	// insert
//	{
//		ft::vector<T>	a(3);
//		std::vector<T>	b(3);
//
//		for (int i = 0; i < 3; i++) {
//			a[i] = i * 10;
//			b[i] = i * 10;
//			std::cout << a[i] << std::endl;
//		}
//		a.insert(a.begin(), 42);
//		b.insert(b.begin(), 42);
//		assertEq("size after first implementation of insert", a.size(), b.size());
//		assertEq("capacity after first implementation of insert", a.capacity(), b.capacity());
//		for (int i = 0; i < 4; i++) {
//			std::cout << a[i] << std::endl;
//		}
//	}
	//TODO add tests with capacity in others functions
}

#endif // FUNCTIONS_TEST_HPP
