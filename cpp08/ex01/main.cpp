/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshay <rshay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 14:47:07 by lebronen          #+#    #+#             */
/*   Updated: 2024/09/02 13:20:55 by rshay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <vector>

int main() {
    Span sp(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    try
    {
        sp.addNumber(4);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    Span vide;
    try
    {
        std::cout << vide.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    Span enorme(10000);
    std::vector<int> vec;
    for (int i = 0; i < 10000; i++) {
        vec.push_back(i);
    }
    enorme.addRange(vec.begin(), vec.end());
    std::cout << enorme.shortestSpan() << std::endl;
    std::cout << enorme.longestSpan() << std::endl;
}
