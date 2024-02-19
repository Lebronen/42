/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebronen <lebronen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 18:35:21 by lebronen          #+#    #+#             */
/*   Updated: 2024/02/18 13:06:19 by lebronen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanB {

    //attributs
    private :

    Weapon *arme;
    std::string name;

    //Constructeurs
    public :

    HumanB(std::string name);
    
    //Fonctions
    public :
    
    void attack(void);
    void setWeapon(Weapon &arme); 
    ~HumanB(void);
};

#endif