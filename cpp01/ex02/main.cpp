/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebronen <lebronen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 18:03:15 by lebronen          #+#    #+#             */
/*   Updated: 2024/02/17 18:15:07 by lebronen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void) {
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string &stringREF = str;
    std::cout << "adresse de la string en mémoire : " << &str << std::endl;
    std::cout << "adresse stockée dans stringPTR : " << stringPTR << std::endl;
    std::cout << "adresse stockée dans stringREF : " << &stringREF << std::endl;
    std::cout << "valeur de la string : " << str << std::endl;
    std::cout << "valeur pointée par stringPTR : " << *stringPTR << std::endl;
    std::cout << "valeur pointée par stringREF : " << stringREF << std::endl;
    
}