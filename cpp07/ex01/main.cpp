/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshay <rshay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 12:44:30 by rshay             #+#    #+#             */
/*   Updated: 2024/08/28 13:07:17 by rshay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main()
{
	int tab[4] = {1, 2, 3, 4};
	std::cout << tab[0] << std::endl;
	incr<int>(tab[0]);
	std::cout << tab[0] << std::endl;
	iter(tab, 4, incr<int>);

	for (int i = 0; i < 4; i++) {
		std::cout << tab[i] << std::endl;
	}
}
