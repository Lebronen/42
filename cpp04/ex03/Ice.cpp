/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebronen <lebronen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 11:49:57 by lebronen          #+#    #+#             */
/*   Updated: 2024/03/15 12:12:26 by lebronen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void) {
    this->type = "ice";
}

Ice::~Ice() {

}

AMateria *Ice::clone() {
    AMateria *iceclone = new Ice();
    return (iceclone);
}

void Ice::use(ICharacter &target) {
    std::cout << "*shots an ice bolt at " << target.name << "*" std::endl;
}