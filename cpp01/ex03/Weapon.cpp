/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebronen <lebronen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 18:22:45 by lebronen          #+#    #+#             */
/*   Updated: 2024/02/17 18:26:46 by lebronen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) {
    this->type = type;
}

Weapon::Weapon(void) {
    
}

const std::string& Weapon::getType(void) {
    return this->type;
}

void Weapon::setType(std::string type) {
    this->type = type;
}

Weapon::~Weapon(void) {
    
}