/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebronen <lebronen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 19:50:53 by lebronen          #+#    #+#             */
/*   Updated: 2024/08/28 20:37:12 by lebronen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>

int main()
{
    Array<int> empty;
    std::cout << empty << std::endl << "size : " << empty.size() << std::endl;
    try
    {
        std::cout << empty[0];
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    Array<int> benten(10);
    std::cout << benten << " size : " << benten.size() << std::endl;
     try
    {
        std::cout << "benten[5] = " << benten[5] << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    Array<char> ctab(5);
    std::cout << ctab << std::endl << "size : " << ctab.size() << std::endl;
     try
    {
        std::cout << "ctab[0] = " << ctab[0] << std::endl;
        std::cout << "ctab[5] = " << ctab[5] << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    Array<int> cpy(benten);
    std::cout << cpy << " size : " << cpy.size() << std::endl;
}