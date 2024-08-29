/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshay <rshay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 12:11:17 by rshay             #+#    #+#             */
/*   Updated: 2024/08/28 12:57:25 by rshay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>
#include <string>

template <typename T>
void incr(T &x)
{
	x++;
}

template <typename T, typename F>
void iter(T *ptr, int len, F f)
{
	for (int i = 0; i < len; i++) {
		f(ptr[i]);
	}
}

#endif
