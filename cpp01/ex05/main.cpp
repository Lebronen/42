/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshay <rshay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:39:06 by rshay             #+#    #+#             */
/*   Updated: 2024/02/19 13:20:46 by rshay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int main(void) {
    Harl harl;
    std::cout << "debug : " << std::endl;
    harl.complain("debug");
    std::cout << "info : " << std::endl;
    harl.complain("info");
    std::cout << "warning : " << std::endl;
    harl.complain("warning");
    std::cout << "error : " << std::endl;
    harl.complain("error");
}