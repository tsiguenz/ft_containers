/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default_constructor_test.hpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 14:51:14 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/06/30 15:05:55 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFAULT_CONSTRUCTOR_TEST_HPP
# define DEFAULT_CONSTRUCTOR_TEST_HPP

template<typename T>
void	defaultConstructorTest() {
	std::cout << "---------- Default constructor tests : ----------" << std::endl;
	int	ftExceptions = 0;
	int	stdExceptions = 0;
	ft::vector<T>	ftV;
	std::vector<T>	stdV;

	assertEq("data()", ftV.data(), stdV.data());

	try { ftV.at(0); } catch (std::exception const& e) { ftExceptions++; }
	try { stdV.at(0); } catch (std::exception const& e) { stdExceptions++; }

	assertEq("at() exceptions", ftExceptions, stdExceptions);
}

#endif // DEFAULT_CONSTRUCTOR_TEST_HPP
