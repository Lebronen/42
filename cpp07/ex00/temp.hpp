/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshay <rshay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 11:54:20 by rshay             #+#    #+#             */
/*   Updated: 2024/08/28 12:47:43 by rshay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEMP_HPP
# define TEMP_HPP

#include <iostream>
#include <string>

template <typename T>
void swap(T &x, T &y)
{
	T temp = x;
	x = y;
	y = temp;
}

template <typename T>
T min(T &x, T &y)
{
	if (x < y)
		return (x);
	return (y);
}

template <typename T>
T max(T &x, T &y)
{
	if (x > y)
		return (x);
	return (y);
}


#endif
