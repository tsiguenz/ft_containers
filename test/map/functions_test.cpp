/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_test.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 14:53:51 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/09/29 22:48:15 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	map_functions_test() {
# ifdef REAL
	namespace ft = std;
#endif
	std::cout << "----------  Map member functions test : ----------" << std::endl;
	// constructors
	{
		ft::map<char, int>	def;
		assertEq("default constructor size", def.size(), (size_t) 0);

		ft::map<char, int>	range;
		range.insert(ft::make_pair('a', 12));
		range.insert(ft::make_pair('c', 42));
		range.insert(ft::make_pair('z', -3));

		ft::map<char, int>	m1(range.begin(), range.end());
		assertEq("insert range m1[a]", m1['a'], 12);
		assertEq("insert range m1[c]", m1['c'], 42);
		assertEq("insert range m1[z]", m1['z'], -3);
		assertEq("size after insert range", m1.size(), (size_t) 3);

		ft::map<char, int>	eq(m1);
		assertEq("copy construct eq[a]", m1['a'], 12);
		assertEq("copy construct eq[c]", m1['c'], 42);
		assertEq("copy construct eq[z]", m1['z'], -3);
		assertEq("size after copy construct", m1.size(), (size_t) 3);
	}
	// at and operator[]
	{
		ft::map<char, int>	m1;

		m1.insert(ft::make_pair('a', 42));
		assertEq("at after insert", m1.at('a'), 42);
		m1.at('a') = 12;
		assertEq("at after modify value with at", m1.at('a'), 12);
		{
			int	ex = 0;
			try {
				m1.at('b');
			}
			catch (std::exception const& e) {
				ex++;
			}
			assertEq("at exception with bad key", ex, 1);
		}
		assertEq("operator[] to access value", m1['a'], 12);
		m1['a'] = 24;
		assertEq("operator[] update existing value", m1['a'], 24);
		m1['b'] = 42;
		assertEq("operator[] insert new value", m1['b'], 42);
		m1['c'];
		assertEq("operator[] create pair with key and default value", m1['c'], 0);
	}
	// empty, size
	{
		ft::map<char, int>	m1;
		std::map<char, int>	m2;

		assertEq("empty on empty map", m1.empty(), true);
		assertEq("size on empty map", m1.size(), (size_t) 0);
		m1.insert(ft::make_pair('c', 42));
		m2.insert(std::make_pair('c', 42));
		assertEq("empty on non empty map", m1.empty(), false);
		assertEq("size after insert", m1.size(), (size_t) 1);
		assertEqMap("assertEqMap test", m1, m2);
		// TODO test after delete an element
	}
	// clear
	{
		ft::map<char, int>	m1;

		m1.insert(ft::make_pair('a', 42));
		m1.insert(ft::make_pair('b', 14));
		m1.insert(ft::make_pair('z', 24));
		assertEq("size before clear", m1.size(), (size_t) 3);
		m1.clear();
		assertEq("size after clear", m1.size(), (size_t) 0);
	}
	// insert
	{
		// single element
		ft::map<char, int>	m1;

		ft::pair<ft::map<char, int>::iterator, bool>	res;
		res = m1.insert(ft::make_pair('c', 42));
		assertEq("insert new element return value first", res.first->second, 42);
		assertEq("insert new element return value second", res.second, true);
		res = m1.insert(ft::make_pair('c', 42));
		assertEq("insert second time return value second", res.second, false);
		assertEq("insert second time return value first", res.first->second, 42);

		// single element with hint
		ft::map<char, int>::iterator	it;
		it = m1.insert(m1.begin(), ft::make_pair('y', 14));
		assertEq("insert hint return value", it->second, 14);
		it = m1.insert(m1.begin(), ft::make_pair('y', 24));
		assertEq("insert hint second time return value", it->second, 14);
		
		// range
		ft::map<char, int>	range;
		range.insert(ft::make_pair('a', 12));
		range.insert(ft::make_pair('c', 1));
		range.insert(ft::make_pair('z', -3));
		m1.insert(range.begin(), range.end());
		assertEq("insert range m1[a]", m1['a'], 12);
		assertEq("insert range m1[c]", m1['c'], 42);
		assertEq("insert range m1[z]", m1['z'], -3);
		assertEq("size after insert range", m1.size(), (size_t) 4);
	}
	// erase
	{
		ft::map<char, int>	m1;

		// from iterator
		m1.insert(ft::make_pair('a', 42));
		m1.insert(ft::make_pair('b', 14));
		m1.insert(ft::make_pair('z', 24));
		assertEq("size before erase iterator", m1.size(), (size_t) 3);
		m1.erase(m1.begin());
		m1.erase(m1.begin());
		m1.erase(m1.begin());
		assertEq("size after erase iterator", m1.size(), (size_t) 0);

		// single element
		m1.insert(ft::make_pair('a', 42));
		assertEq("size before erase single element", m1.size(), (size_t) 1);
		assertEq("erase existing element", m1.erase('a'), (size_t) 1);
		assertEq("erase non existing element", m1.erase('a'), (size_t) 0);
		assertEq("size after erase single element", m1.size(), (size_t) 0);
		
		// range
		m1.insert(ft::make_pair('a', 42));
		m1.insert(ft::make_pair('b', 14));
		m1.insert(ft::make_pair('z', 24));
		assertEq("size before erase range", m1.size(), (size_t) 3);
		m1.erase(m1.begin(), m1.end());
		assertEq("size after erase range", m1.size(), (size_t) 0);
	}
	// swap
	{
		ft::map<char, int>	foo, bar;

		foo['x']=100;
		foo['y']=200;

		bar['a']=11;
		bar['b']=22;
		bar['c']=33;

		foo.swap(bar);
		assertEq("foo[a] contain", foo['a'], 11);
		assertEq("foo[b] contain", foo['b'], 22);
		assertEq("foo[c] contain", foo['c'], 33);

		assertEq("bar[x] contain", bar['x'], 100);
		assertEq("bar[y] contain", bar['y'], 200);
	}
	// count
	{
		ft::map<char, int>	foo;

		foo['x']=100;

		assertEq("count when key is existing", foo.count('x'), (size_t) 1);
		assertEq("count when key is not existing", foo.count('y'), (size_t) 0);
	}
	// find
	{
		ft::map<char, int>	bar;

		bar['a']=11;
		bar['b']=22;
		bar['c']=33;

		assertEq("return value of find", bar.find('b')->second, 22);
		assertEq("return value of find", (--bar.find('z'))->second, 33);
		ft::map<char, int>::const_iterator	it = bar.find('a');
		assertEq("return value of const find", it->second, 11);
	}
	// equal_range
	{
		typedef	ft::map<char, int>::const_iterator	ci;
		ft::map<char, int>	bar;

		bar['a']=11;
		bar['b']=22;
		bar['c']=33;
		assertEq("equal_range first->second", bar.equal_range('a').first->second, 11);
		assertEq("equal_range second->second", bar.equal_range('a').second->second, 22);
		assertEq("equal_range invalid first", bar.equal_range('z').first == bar.end(), true);
		assertEq("equal_range invalid second", bar.equal_range('z').second == bar.end(), true);
		ft::pair<ci, ci>	p = bar.equal_range('c');
		assertEq("const equal_range first", p.first->second, 33);
		assertEq("const equal_range second", p.second == bar.end(), true);
	}
	// lower_bound / upper_bound
	{
		ft::map<char, int>	m1;
		std::map<char, int>	m2;
		ft::map<char, int>::iterator	it1;
		std::map<char, int>::iterator	it2;
		ft::map<char, int>::const_iterator	cit1;
		std::map<char, int>::const_iterator	cit2;


		m1['a']=20;
		m1['c']=60;
		m1['d']=80;
		m2['a']=20;
		m2['c']=60;
		m2['d']=80;
		// lower_bound
		it1 = m1.lower_bound('b');
		it2 = m2.lower_bound('b');
		assertEq("lower_bound nonexistant key", it1->second, it2->second);
		it1 = m1.lower_bound('d');
		it2 = m2.lower_bound('d');
		assertEq("lower_bound existant key", it1->second, it2->second);
		it1 = m1.lower_bound('z');
		it2 = m2.lower_bound('z');
		assertEq("lower_bound return end()", it1 == m1.end(), true);
		cit1 = m1.lower_bound('b');
		cit2 = m2.lower_bound('b');
		assertEq("const lower_bound nonexistant key", cit1->second, cit2->second);
		// upper_bound
		it1 = m1.upper_bound('b');
		it2 = m2.upper_bound('b');
		assertEq("upper_bound nonexistant key", it1->second, it2->second);
		it1 = m1.upper_bound('c');
		it2 = m2.upper_bound('c');
		assertEq("upper_bound existant key", it1->second, it2->second);
		it1 = m1.upper_bound('z');
		it2 = m2.upper_bound('z');
		assertEq("upper_bound return end()", it1 == m1.end(), true);
		cit1 = m1.upper_bound('b');
		cit2 = m2.upper_bound('b');
		assertEq("const upper_bound nonexistant key", cit1->second, cit2->second);
	}
	// non member swap
	{
		ft::map<char, int>	foo, bar;

		foo['x']=100;
		foo['y']=200;

		bar['a']=11;
		bar['b']=22;
		bar['c']=33;

		ft::swap(foo, bar);
		assertEq("foo[a] contain", foo['a'], 11);
		assertEq("foo[b] contain", foo['b'], 22);
		assertEq("foo[c] contain", foo['c'], 33);

		assertEq("bar[x] contain", bar['x'], 100);
		assertEq("bar[y] contain", bar['y'], 200);
	}
}
