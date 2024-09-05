/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebronen <lebronen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 14:29:55 by lebronen          #+#    #+#             */
/*   Updated: 2024/09/05 14:51:29 by lebronen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <deque>
#include <stdlib.h>

class PmergeMe
{
public:
    // Constructors
    PmergeMe();
    PmergeMe(const PmergeMe &copy);

    // Destructor
    ~PmergeMe();

    // Functions
    template <typename T>
    static void sort(T &container) {
        if (container.size() < 2)
            return ;
        sort_pairs(container);

        T biggests;
        for (size_t i = 1; i < container.size(); i+= 2) {
            biggests.push_back(container[i]);
        }
        sort(biggests);

        for (size_t i = 0; i < container.size(); i += 2) {
            binary_insert(biggests, container[i]);
        }
        container = biggests;
    }
    

    // Operators
    PmergeMe &operator=(const PmergeMe &assign);

private:

    // Secondary private Functions

    template <typename T>
    static void sort_pairs(T &container) {
        for (size_t i = 0; i < container.size() - 1; i+= 2) {
            if (container[i] > container[i+1])
                std::swap(container[i], container[i+1]);
        }
    }

    template <typename T>
    static void binary_insert(T &container, size_t element) {
        int left = 0;
        int right = container.size() - 1;
        int mid;

        while (left <= right) {
            mid = left + (right - left) / 2;
            if (element < container[mid])
                right = mid - 1;
            else
                left = mid + 1;
        }

        container.insert(container.begin() + left, element);
    }
};

#endif