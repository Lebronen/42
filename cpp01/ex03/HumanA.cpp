/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebronen <lebronen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 18:41:53 by lebronen          #+#    #+#             */
/*   Updated: 2024/02/18 13:05:40 by lebronen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& arme) : arme(arme) {
    this->name = name;

}

void HumanA::attack(void) {
    std::cout << name << " attacks with their " << arme.getType() <<std::endl;
}

HumanA::~HumanA(void) {
    
}