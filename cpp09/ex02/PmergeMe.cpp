/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebronen <lebronen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 14:29:53 by lebronen          #+#    #+#             */
/*   Updated: 2024/09/05 14:29:54 by lebronen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// Constructors
PmergeMe::PmergeMe()
{
    std::cout << "\e[0;33mDefault Constructor called of PmergeMe\e[0m" << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe &copy)
{
    (void)copy;
    std::cout << "\e[0;33mCopy Constructor called of PmergeMe\e[0m" << std::endl;
}

// Destructor
PmergeMe::~PmergeMe()
{
    std::cout << "\e[0;31mDestructor called of PmergeMe\e[0m" << std::endl;
}

// Operators
PmergeMe &PmergeMe::operator=(const PmergeMe &assign)
{
    (void)assign;
    return *this;
}
