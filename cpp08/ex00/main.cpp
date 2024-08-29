/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshay <rshay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 18:20:00 by rshay             #+#    #+#             */
/*   Updated: 2024/08/29 18:40:35 by rshay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <set>
#include <list>

int main()
{

	int tab[5] = {1, 2, 3, 4, 5};
	std::cout << ::easyfind(tab, 5) << std::endl;
	std::vector<int> pi = {3, 14, 15, 92, 65, 35};
	std::cout << ::easyfind(pi, 92) << std::endl;
	std::list<int> fibo = {1, 1, 2, 3, 5, 8, 13, 21, 34};
	std::cout << ::easyfind(fibo, 21) << std::endl;
	std::set<int> prems = {2, 3, 5, 7, 11, 13, 17, 19, 23};
	std::cout << ::easyfind(prems, 5);
}
