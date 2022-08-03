/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_managment_test.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 15:00:26 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/08/03 16:22:54 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_MANAGMENT_TEST_HPP
# define OBJECT_MANAGMENT_TEST_HPP

template<typename T>
void	objectManagmentTest() {
# ifdef REAL
	namespace ft = std;
#endif
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

		assertEqVector("fill constructor no initialisation", ftV1, stdV1);
		assertEqVector("Fill Constructor with initialisation", ftV2, stdV2);
		for (int i = 0; i < 5; i++) {
			ftV2[i] += (5 * i);
			stdV2[i] += (5 * i);
		}
		ft::vector<T>	ftV3(ftV2.begin(), ftV2.end());
		std::vector<T>	stdV3(stdV2.begin(), stdV2.end());
		assertEq("Range constructor is equal ?", ftV2 == ftV3, stdV2 == stdV3);
		assertEqVector("range constructor", ftV3, stdV3);
		ft::vector<T>	ftV4(ftV3);
		std::vector<T>	stdV4(stdV3);
		assertEq("Copy constructor is equal ?", ftV4 == ftV3, stdV4 == stdV3);
		assertEqVector("range constructor", ftV4, stdV4);
	}
}
#endif // OBJECT_MANAGMENT_TEST_HPP
