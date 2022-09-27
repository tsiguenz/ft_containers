/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_test.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 16:27:59 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/09/27 17:42:33 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include "src/containers_test/srcs/map/common.hpp"

#define FTMAP ft::map<int, int>
#define STDMAP std::map<int, int>

#include <list>

#define NS ft
#define T1 int
#define T2 std::string

static int iter = 0;

typedef NS::pair<const T1, T2> T3;

	template <typename MAP, typename U>
void	ft_erase(MAP &mp, U param)
{
	std::cout << "\t-- [" << iter++ << "] --" << std::endl;
	mp.erase(param);
	printSize(mp);
}

	template <typename MAP, typename U, typename V>
void	ft_erase(MAP &mp, U param, V param2)
{
	std::cout << "\t-- [" << iter++ << "] --" << std::endl;
	mp.erase(param, param2);
	printSize(mp);
}

void	map_test() {
# ifdef REAL
	namespace ft = std;
#endif
//	pair_test();
//	avl_test();
//	map_iterators_test();
//	map_operators_test();
//	map_functions_test();
	{
		std::list<T3> lst;
		unsigned int lst_size = 10;
		for (unsigned int i = 0; i < lst_size; ++i)
			lst.push_back(T3(i, std::string((lst_size - i), i + 65)));
		NS::map<T1, T2> mp(lst.begin(), lst.end());
//
//		ft_erase(mp, ++mp.begin());
//
//		ft_erase(mp, mp.begin());
//		ft_erase(mp, --mp.end());

//		ft_erase(mp, mp.begin(), ++(++(++mp.begin())));
		ft_erase(mp, --(--(--mp.end())), --mp.end());
//
//		mp[10] = "Hello";
//		mp[11] = "Hi there";
//		printSize(mp);
//		ft_erase(mp, --(--(--mp.end())), mp.end());
//
//		mp[12] = "ONE";
//		mp[13] = "TWO";
//		mp[14] = "THREE";
//		mp[15] = "FOUR";
//		printSize(mp);
//		ft_erase(mp, mp.begin(), mp.end());

	}
}
