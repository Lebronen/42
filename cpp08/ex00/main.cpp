/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebronen <lebronen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 18:20:00 by rshay             #+#    #+#             */
/*   Updated: 2024/08/30 18:39:36 by lebronen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <set>
#include <list>

int main()
{

	int pitab[6] = {3, 14, 15, 92, 65, 35};
	std::vector<int> pi(pitab, pitab + 6);
	std::cout << ::easyfind(pi, 92) << std::endl;
	int fibotab[9] = {1, 1, 2, 3, 5, 8, 13, 21, 34};
	std::list<int> fibo(fibotab, fibotab + 9);
	std::cout << ::easyfind(fibo, 21) << std::endl;
	int tabprems[9] = {2, 3, 5, 7, 11, 13, 17, 19, 23};
	std::set<int> prems(tabprems, tabprems + 9);
	std::cout << ::easyfind(prems, 5) << std::endl;
}
