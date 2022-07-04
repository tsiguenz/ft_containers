/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_managment_test.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 15:00:26 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/07/04 17:44:42 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_MANAGMENT_TEST_HPP
# define OBJECT_MANAGMENT_TEST_HPP

template<typename T>
void	objectManagmentTest() {
	std::cout << "----------  Object managment : ----------" << std::endl;
	{
		ft::vector<T>	ftV;
		std::vector<T>	stdV;

		assertEq("Default constructor size", ftV.size(), stdV.size());
	}
	{
		ft::vector<T>	ftV1(5);
		std::vector<T>	stdV1(5);
		ft::vector<T>	ftV2(5, 42);
		std::vector<T>	stdV2(5, 42);

		assertEq("Fill Constructor no initialisation", ftV1.size(), stdV1.size());
		assertEq("Uninitialize value", ftV1[0], stdV1[0]);
		assertEq("Fill Constructor with initialisation", ftV2.size(), stdV2.size());
		assertEq("Test value", ftV2[0], stdV2[0]);
	}
}
#endif // OBJECT_MANAGMENT_TEST_HPP
