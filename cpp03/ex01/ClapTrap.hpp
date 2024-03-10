/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebronen <lebronen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:12:30 by lebronen          #+#    #+#             */
/*   Updated: 2024/03/07 15:13:37 by lebronen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAP_TRAP_HPP
# define CLAP_TRAP_HPP

#include <iostream>

class ClapTrap {

    //attributs
    private :

    std::string name;
    int hit_points;
    int energy_points;
    int attack_damage;

    //Constructeurs
    public :
    
    ClapTrap(std::string name);
    ClapTrap(ClapTrap const &cpy);
    ClapTrap(std::string name, int hp, int ep, int ad);

    //Fonctions
    public :

    ClapTrap &operator=(ClapTrap const &other);
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
    void showStats(void) const;

    //Destructeur
    public :

    ~ClapTrap(void);
    
};

#endif