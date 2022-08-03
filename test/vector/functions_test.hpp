/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_test.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 16:49:25 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/08/03 14:20:37 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_TEST_HPP
# define FUNCTIONS_TEST_HPP

template<class T>
void	functionsTest() {
	std::cout << "----------  Functions test : ----------" << std::endl;
	// swap
	{
		ft::vector<T>	a1(5);
		ft::vector<T>	a2;

		for (int i = 0; i < 5; i++)
			a1[i] = i * 10;
		ft::swap(a1, a2);

		std::vector<T>	b1(5);
		std::vector<T>	b2;

		for (int i = 0; i < 5; i++)
			b1[i] = i * 10;
		std::swap(b1, b2);
		assertEqVector("swap compare a1 to b1", a1, b1);
		assertEqVector("swap compare a2 to b2", a2, b2);
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
		assertEqVector("asssign fill overload", a1, b1);
		assertEqVector("asssign range overload", a2, b2);
		a1.assign(2, 12);
		b1.assign(2, 12);
		a2.assign(a1.begin() + 1, a1.end());
		b2.assign(b1.begin() + 1, b1.end());
		assertEqVector("asssign fill overload second time", a1, b1);
		assertEqVector("asssign range overload second time", a2, b2);
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
		assertEqVector("compare after reserve", a, b);
	}
	// reserve / clear
	{
		ft::vector<T>	a(3, 42);
		std::vector<T>	b(3, 42);

		a.reserve(5);
		b.reserve(5);
		assertEqVector("reserve classic", a, b);
		a.reserve(4);
		b.reserve(4);
		assertEqVector("reserve 4 on capacity 5", a, b);
		a.reserve(1);
		b.reserve(1);
		assertEqVector("reserve 1 on capacity 5", a, b);
		a.clear();
		b.clear();
		assertEqVector("clear check vectors", a, b);

		int	nbException = 0;

		try { a.reserve(a.max_size() + 1); } catch (std::exception const& e) { nbException++; }
		try { b.reserve(b.max_size() + 1); } catch (std::exception const& e) { nbException++; }
		assertEq("reserve exception test", nbException, 2);
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
		assertEqVector("insert single element non empty container", a, b);

		ft::vector<T>	a1;
		std::vector<T>	b1;

		assertEq("insert empty vector return value", *a1.insert(a1.begin(), 42), *b1.insert(b1.begin(), 42));
		assertEqVector("insert single element range empty container", a1, b1);
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
		assertEqVector("insert fill non empty container", a, b);

		ft::vector<T>	a1;
		std::vector<T>	b1;

		a1.insert(a1.begin(), 2, 42);
		b1.insert(b1.begin(), 2, 42);
		assertEqVector("insert fill empty container", a1, b1);
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
		assertEqVector("insert range not empty container", a, b);

		ft::vector<T>	a1;
		std::vector<T>	b1;

		a1.insert(a1.begin(), range.begin(), range.end());
		b1.insert(b1.begin(), range.begin(), range.end());
		assertEqVector("insert range empty container", a1, b1);
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
		assertEq("erase pos return value", *a.erase(a.begin()), *b.erase(b.begin()));
		assertEqVector("erase pos size 1", a, b);
		assertEq("erase pos return value", *a.erase(a.begin() + 2), *b.erase(b.begin() + 2));
		assertEqVector("erase pos size 1", a, b);
		assertEq("erase pos return value", *a.erase(a.end() - 1), *b.erase(b.end() - 1));
		assertEqVector("erase pos size 1", a, b);
		assertEq("erase pos return value", *a.erase(a.begin()), *b.erase(b.begin()));
		assertEqVector("erase pos size 1", a, b);
		a.push_back(5);
		a.push_back(2);
		a.push_back(8);
		a.push_back(6);

		b.push_back(5);
		b.push_back(2);
		b.push_back(8);
		b.push_back(6);
		assertEq("erase range basic return value", *a.erase(a.begin() + 1, a.begin() + 3), *b.erase(b.begin() + 1, b.begin() + 3));
		assertEqVector("erase range basic", a, b);
		assertEq("erase range begin, end return value", *a.erase(a.begin(), a.end()), *b.erase(b.begin(), b.end()));
		assertEqVector("erase range begin, end", a, b);
		assertEq("erase empty range return value", *a.erase(a.begin() + 1, a.begin() + 1), *b.erase(b.begin() + 1, b.begin() + 1));
		assertEqVector("erase empty range", a, b);
		ft::vector<std::string>		vct1(10);
		std::vector<std::string>	vct2(10);
		for (unsigned long int i = 0; i < vct1.size(); ++i) {
			vct1[i] = std::string((vct1.size() - i), i + 65);
			vct2[i] = std::string((vct2.size() - i), i + 65);
		}
		vct1.erase(vct1.begin(), vct1.begin() + 3);
		vct2.erase(vct2.begin(), vct2.begin() + 3);
		assertEqVector("test", vct1, vct2);
		
	}
	// push_back
	{
		ft::vector<T>	a;
		std::vector<T>	b;

		a.push_back(42);
		a.push_back(32);
		a.push_back(32);
		b.push_back(42);
		b.push_back(32);
		b.push_back(32);
		assertEqVector("push_back on empty container", a, b);

		ft::vector<T>	a1(5);
		std::vector<T>	b1(5);

		a1.push_back(42);
		b1.push_back(42);
		assertEqVector("push_back on non empty container", a, b);
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
		assertEqVector("pop_back size 2", a, b);
		a.pop_back();
		b.pop_back();
		assertEqVector("pop_back size 1", a, b);
	}
	// resize
	{
		ft::vector<T>	a;
		std::vector<T>	b;
		a.push_back(42);
		a.push_back(32);
		b.push_back(42);
		b.push_back(32);
		a.resize(2);
		b.resize(2);
		assertEqVector("resize value equal than size", a, b);
		a.resize(1);
		b.resize(1);
		assertEqVector("resize value less than size", a, b);
		a.resize(5);
		b.resize(5);
		assertEqVector("resize value greater than size", a, b);
	}
	// swap
	{
		ft::vector<T>	a1(5);
		ft::vector<T>	a2;

		for (int i = 0; i < 5; i++)
			a1[i] = i * 10;
		a1.swap(a2);

		std::vector<T>	b1(5);
		std::vector<T>	b2;

		for (int i = 0; i < 5; i++)
			b1[i] = i * 10;
		b1.swap(b2);
		assertEqVector("swap compare a1 to b1", a1, b1);
		assertEqVector("swap compare a2 to b2", a2, b2);
	}
}

#endif // FUNCTIONS_TEST_HPP
