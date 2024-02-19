/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebronen <lebronen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 18:50:00 by lebronen          #+#    #+#             */
/*   Updated: 2024/02/18 13:06:27 by lebronen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string) {
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
