/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_test.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 16:49:25 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/07/25 20:10:14 by tsiguenz         ###   ########.fr       */
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

		for (int i = 0; i < 5; i++)
			a1[i] = i * 10;
		ft::vector<T>	a4(a1);
		ft::swap(a1, a2);

		std::vector<T>	b1(5);
		std::vector<T>	b2;

		for (int i = 0; i < 5; i++)
			b1[i] = i * 10;
		std::vector<T>	b4(b1);
		std::swap(b1, b2);
		assertEqContainer("swap compare a1 to b1", a1, b1);
		assertEqContainer("swap compare a2 to b2", a2, b2);
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
		assertEqContainer("asssign fill overload", a1, b1);
		assertEqContainer("asssign range overload", a2, b2);
		a1.assign(2, 12);
		b1.assign(2, 12);
		a2.assign(a1.begin() + 1, a1.end());
		b2.assign(b1.begin() + 1, b1.end());
		assertEqContainer("asssign fill overload second time", a1, b1);
		assertEqContainer("asssign range overload second time", a2, b2);
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
		assertEqContainer("reserve classic", a, b);
		a.reserve(4);
		b.reserve(4);
		assertEqContainer("reserve 4 on capacity 5", a, b);
		a.reserve(1);
		b.reserve(1);
		assertEqContainer("reserve 1 on capacity 5", a, b);
		a.clear();
		b.clear();
		assertEqContainer("clear check vectors", a, b);
	}
	// insert single element
	{
		ft::vector<T>	a;
		std::vector<T>	b;

		a.push_back(42);
		a.push_back(24);
		b.push_back(42);
		b.push_back(24);
		assertEq("insert return value", *a.insert(a.begin(), 1), *b.insert(b.begin(), 1));
		assertEq("insert return value", *a.insert(a.begin() + 2, 8), *b.insert(b.begin() + 2, 8));
		assertEq("insert return value", *a.insert(a.end(), 2), *b.insert(b.end(), 2));
		assertEqContainer("insert single element non empty container", a, b);

		ft::vector<T>	a1;
		std::vector<T>	b1;

		assertEq("insert empty vector return value", *a1.insert(a1.begin(), 42), *b1.insert(b1.begin(), 42));
		assertEqContainer("insert single element range empty container", a1, b1);
	}
	// insert fill
	{
		ft::vector<T>	a;
		std::vector<T>	b;

		a.push_back(42);
		a.push_back(24);
		b.push_back(42);
		b.push_back(24);

		a.insert(a.begin(), 2, 42);
		b.insert(b.begin(), 2, 42);
		assertEqContainer("insert fill non empty container", a, b);

		ft::vector<T>	a1;
		std::vector<T>	b1;

		a1.insert(a1.begin(), 2, 42);
		b1.insert(b1.begin(), 2, 42);
		assertEqContainer("insert fill empty container", a1, b1);
	}
	// insert range
	{
		std::vector<T>	range;
		range.push_back(42);
		range.push_back(38);
		ft::vector<T>	a(1, 5);
		std::vector<T>	b(1, 5);

		a.insert(a.begin(), range.begin(), range.end());
		b.insert(b.begin(), range.begin(), range.end());

		a.insert(a.begin(), range.begin(), range.end());
		b.insert(b.begin(), range.begin(), range.end());
		assertEqContainer("insert range not empty container", a, b);

		ft::vector<T>	a1;
		std::vector<T>	b1;

		a1.insert(a1.begin(), range.begin(), range.end());
		b1.insert(b1.begin(), range.begin(), range.end());
		assertEqContainer("insert range empty container", a1, b1);
	}
	// push_back
	{
		ft::vector<T>	a;
		std::vector<T>	b;

		a.push_back(42);
		a.push_back(32);
		b.push_back(42);
		b.push_back(32);
		assertEqContainer("push_back on empty container", a, b);

		ft::vector<T>	a1(5);
		std::vector<T>	b1(5);

		a1.push_back(42);
		b1.push_back(42);
		assertEqContainer("push_back on non empty container", a, b);
	}
	// pop_back
	{
		ft::vector<T>	a;
		std::vector<T>	b;

		a.push_back(42);
		a.push_back(32);
		b.push_back(42);
		b.push_back(32);
		a.pop_back();
		b.pop_back();
		assertEqContainer("pop_back size 2", a, b);
		a.pop_back();
		b.pop_back();
		assertEqContainer("pop_back size 1", a, b);
	}
	// erase
	{
		ft::vector<T>	a;
		std::vector<T>	b;

		a.push_back(42);
		a.push_back(32);
		a.push_back(22);
		a.push_back(12);
		b.push_back(42);
		b.push_back(32);
		b.push_back(22);
		b.push_back(12);
		assertEq("erase return value", *a.erase(a.begin()), *b.erase(b.begin()));
		assertEqContainer("erase size 1", a, b);
		assertEq("erase return value", *a.erase(a.begin() + 2), *b.erase(b.begin() + 2));
		assertEqContainer("erase size 1", a, b);
		assertEq("erase return value", *a.erase(a.end() - 1), *b.erase(b.end() - 1));
		assertEqContainer("erase size 1", a, b);
		assertEq("erase return value", *a.erase(a.begin()), *b.erase(b.begin()));
		assertEqContainer("erase size 1", a, b);
	}
}

#endif // FUNCTIONS_TEST_HPP
