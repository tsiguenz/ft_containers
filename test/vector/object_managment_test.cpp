/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_managment_test.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 15:00:26 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/09/21 15:29:43 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	vector_object_managment_test() {
# ifdef REAL
	namespace ft = std;
#endif
	std::cout << "----------  Object managment : ----------" << std::endl;
	{
		ft::vector<int>		ftV;
		std::vector<int>	stdV;

		assertEq("Default constructor size", ftV.size(), stdV.size());
	}
	{
		ft::vector<int>		ftV1(5);
		std::vector<int>	stdV1(5);
		ft::vector<int>		ftV2(5, 42);
		std::vector<int>	stdV2(5, 42);

		assertEqVector("fill constructor no initialisation", ftV1, stdV1);
		assertEqVector("Fill Constructor with initialisation", ftV2, stdV2);
		for (int i = 0; i < 5; i++) {
			ftV2[i] += (5 * i);
			stdV2[i] += (5 * i);
		}
		ft::vector<int>		ftV3(ftV2.begin(), ftV2.end());
		std::vector<int>	stdV3(stdV2.begin(), stdV2.end());
		assertEq("Range constructor is equal ?", ftV2 == ftV3, stdV2 == stdV3);
		assertEqVector("range constructor", ftV3, stdV3);
		ft::vector<int>		ftV4(ftV3);
		std::vector<int>	stdV4(stdV3);
		assertEq("Copy constructor is equal ?", ftV4 == ftV3, stdV4 == stdV3);
		assertEqVector("range constructor", ftV4, stdV4);
	}
}
