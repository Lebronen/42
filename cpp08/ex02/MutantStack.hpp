/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshay <rshay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 15:20:31 by rshay             #+#    #+#             */
/*   Updated: 2024/09/02 16:26:13 by rshay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <string>
#include <stack>
#include <deque>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
    // Declaration of the iterator type
    typedef typename std::deque<T>::iterator iterator;

	// Functions
	iterator begin() {
		return this->c.begin();
	}
	iterator end() {
		return this->c.end();
	}

};

#endif
