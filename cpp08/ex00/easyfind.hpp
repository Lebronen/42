/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebronen <lebronen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 17:40:20 by rshay             #+#    #+#             */
/*   Updated: 2024/08/30 18:35:49 by lebronen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <string>

template <typename T>
int easyfind(T &container, int x)
{
	typename T::iterator it;
	int c = -1;
	for (it = container.begin(); it != container.end(); it++) {
		c++;
		if (*it == x)
			return (c);
	}
	return (-1);

}

#endif
