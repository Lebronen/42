/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshay <rshay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 18:50:00 by lebronen          #+#    #+#             */
/*   Updated: 2024/02/20 12:43:43 by rshay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) {
    this->name = name;
    this->arme = NULL;
}

void HumanB::setWeapon(Weapon& arme) {
    this->arme = &arme;
}

void HumanB::attack(void) {
    std::cout << name << " attacks with their " << arme->getType() << std::endl;
}

HumanB::~HumanB(void) {
    
}
