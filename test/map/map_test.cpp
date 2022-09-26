/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_test.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 16:27:59 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/09/26 19:02:06 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

#define FTMAP ft::map<int, int>
#define STDMAP std::map<int, int>

#include <list>

#define T1 int
#define T2 foo<int>

// --- Class foo
template <typename T>
class foo {
public:
	typedef T	value_type;

	foo(void) : value(), _verbose(false) { };
	foo(value_type src, const bool verbose = false) : value(src), _verbose(verbose) { };
	foo(foo const &src, const bool verbose = false) : value(src.value), _verbose(verbose) { };
	~foo(void) { if (this->_verbose) std::cout << "~foo::foo()" << std::endl; };
	void m(void) { std::cout << "foo::m called [" << this->value << "]" << std::endl; };
	void m(void) const { std::cout << "foo::m const called [" << this->value << "]" << std::endl; };
	foo &operator=(value_type src) { this->value = src; return *this; };
	foo &operator=(foo const &src) {
		if (this->_verbose || src._verbose)
			std::cout << "foo::operator=(foo) CALLED" << std::endl;
		this->value = src.value;
		return *this;
	};
	value_type	getValue(void) const { return this->value; };
	void		switchVerbose(void) { this->_verbose = !(this->_verbose); };

	operator value_type(void) const {
		return value_type(this->value);
	}
private:
	value_type	value;
	bool		_verbose;
};

template <typename T>
std::ostream	&operator<<(std::ostream &o, foo<T> const &bar) {
	o << bar.getValue();
	return o;
}
// --- End of class foo


void	map_test() {
# ifdef REAL
	namespace ft = std;
#endif
	pair_test();
	avl_test();
	map_iterators_test();
	map_operators_test();
	map_functions_test();
	{
	}
}
