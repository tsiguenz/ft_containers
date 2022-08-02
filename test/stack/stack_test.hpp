/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_test.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 23:00:02 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/08/02 23:49:43 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_TEST_HPP
# define STACK_TEST_HPP

# define TESTED_NAMESPACE ft
# define TESTED_TYPE	T
# include <stack>

# include <stack.hpp>
# include <utils_test.hpp>

void	stack_test() {
# ifdef REAL
	namespace ft = std;
# endif

	ft::stack<int>	s;

}

#endif // STACK_TEST_HPP
