/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebronen <lebronen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 11:58:08 by lebronen          #+#    #+#             */
/*   Updated: 2024/03/15 12:13:55 by lebronen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.cpp"

Cure::Cure(void) {
    this->type = "cure";
}

Cure::~Cure() {
    
}

AMateria *Cure::clone() {
    AMateria *cureclone = new Cure();
    return (cureclone);
}

void Cure::use(AMateria &target) {
    std::cout << "*heals " << target.name << "'s wounds*" << std::endl;
}