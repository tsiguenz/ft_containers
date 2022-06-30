/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_managment_test.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 15:00:26 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/06/30 15:01:36 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_MANAGMENT_TEST_HPP
# define OBJECT_MANAGMENT_TEST_HPP

template<typename T>
void	objectManagmentTest() {
	std::cout << "----------  Object managment : ----------" << std::endl;
	ft::vector<T>	ftV(5);
	std::vector<T>	stdV(5);

	ftV[0] = 42;
	stdV[0] = 42;
	assertEq("[] operator", ftV[0], stdV[0]);
	assertEq("[] operator on uninitialise value", ftV[1], stdV[1]);
}
#endif // OBJECT_MANAGMENT_TEST_HPP
