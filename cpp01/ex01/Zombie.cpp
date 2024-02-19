/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshay <rshay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:04:31 by rshay             #+#    #+#             */
/*   Updated: 2024/02/13 16:34:52 by rshay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name) {
    this->name = name;
    this->next = NULL;
}
Zombie::~Zombie() {
    std::cout << "destruction du zombie : " << name << std::endl;

}

Zombie *Zombie::getNext() {
    return (this->next);
}

void Zombie::setNext(std::string name) {
    delete this->next;
    this->next = new Zombie(name);
}

void Zombie::announce(void) {
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;   
}
