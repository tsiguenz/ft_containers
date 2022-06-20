/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 10:53:55 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/06/20 18:36:17 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <vector.hpp>
#include <test.hpp>


int	main() {

#ifdef REAL
	namespace ft = std;
#endif
	std::cout << "---------- Default constructor tests : ----------" << std::endl;
	{
		int	ftExceptions = 0;
		int	stdExceptions = 0;
		ft::vector<int>		ftV;
		std::vector<int>	stdV;

		assertEq("data()", ftV.data(), stdV.data());

		try { ftV.at(0); } catch (std::exception const& e) { ftExceptions++; }
		try { stdV.at(0); } catch (std::exception const& e) { stdExceptions++; }

		assertEq("at() exceptions", ftExceptions, stdExceptions);
	}
	return 0;
}

