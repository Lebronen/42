/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshay <rshay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 17:40:20 by rshay             #+#    #+#             */
/*   Updated: 2024/08/29 18:25:43 by rshay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <string>

template <typename T>
int easyfind(T &container, int x)
{
	int c = -1;
	for (int i : container) {
		c++;
		if (i == x)
			return (c);
	}
	return (-1);

}

#endif
