/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_test.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 14:53:51 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/09/19 18:09:32 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	map_functions_test() {
# ifdef REAL
	namespace ft = std;
#endif
	std::cout << "----------  Map member functions test : ----------" << std::endl;
	// constructors
	{
		ft::map<char, int>	range;
		range.insert(ft::make_pair('a', 12));
		range.insert(ft::make_pair('c', 42));
		range.insert(ft::make_pair('z', -3));

		ft::map<char, int>	m1(range.begin(), range.end());
		assertEq("insert range m1[a]", m1['a'], 12);
		assertEq("insert range m1[c]", m1['c'], 42);
		assertEq("insert range m1[z]", m1['z'], -3);
		assertEq("size after insert range", m1.size(), (size_t) 3);
		// TODO need more tests
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
		// from iterator
		// single element
		ft::map<char, int>	m1;

		m1.insert(ft::make_pair('a', 42));
		assertEq("erase existing element", m1.erase('a'), (size_t) 1);
		assertEq("erase non existing element", m1.erase('a'), (size_t) 0);
		assertEq("size after erase", m1.size(), (size_t) 0);
		
		// range
	}
}
