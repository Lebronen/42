/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebronen <lebronen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:22:10 by lebronen          #+#    #+#             */
/*   Updated: 2024/03/07 14:54:56 by lebronen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "ClapTrap.hpp"

static int	max(int a, int b)
{
	if (a >= b)
		return (a);
	return (b);
}

ClapTrap::ClapTrap(std::string name) {
    this->name = name;
    this->hit_points = 10;
    this->energy_points = 10;
    this->attack_damage = 0;
}

ClapTrap::ClapTrap(ClapTrap const &cpy) {
    *this = cpy;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &other) {
    if (this != &other)
	{
		this->name = other.name;
        this->hit_points = other.hit_points;
        this->energy_points = other.energy_points;
		this->attack_damage = other.attack_damage;
        
	}
	return (*this);
}

void ClapTrap::attack(const std::string& target) {
    if (energy_points > 0 && hit_points > 0) {
        std::cout << name << " attacks " << target << "(loses " << attack_damage << "hp)" << std::endl;
        energy_points -= 1;
    }
    else if (energy_points > 0)
        std::cout << name << " attac.. wait you can't attack, you're DEAD !" << std::endl;
    else
        std::cout << "you're too weak " << name <<  "sorry, go lift some weights" << std::endl;
    showStats();
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (hit_points > 0) {
        std::cout << "Houston we have a problem, " << name << "just lost " << amount <<"hp" << std::endl;
        hit_points = max(hit_points - amount, 0);
        if (hit_points == 0)
            std::cout << name << "is cold, we can't do anything for him anymore" << std::endl;
    }
    else
        std::cout << name << "is already dead, why would you still hurt him" << std::endl;
    showStats();
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (energy_points > 0 && hit_points > 0) {
        std::cout << name << " recovered " << amount << "hp" << std::endl;
        hit_points += amount;
        energy_points -= 1;
    }
    else if (energy_points > 0)
        std::cout << name << " has nothing to repair, he's dead" << std::endl;
    else
        std::cout << "you're too weak " << name <<  "sorry, go lift some weights" << std::endl;
    showStats();
}

void ClapTrap::showStats(void) const {
    std::cout << std::setw(5) << hit_points << " hp";
    std::cout << std::setw(5) << energy_points << " ep";
    std::cout << std::setw(5) << attack_damage << " ad" << std::endl;
}

