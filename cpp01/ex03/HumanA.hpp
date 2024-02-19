/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebronen <lebronen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 18:27:30 by lebronen          #+#    #+#             */
/*   Updated: 2024/02/18 13:03:19 by lebronen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanA {

    //attributs
    private :

    Weapon& arme;
    std::string name;

    //Constructeurs
    public:
    
    HumanA(std::string name, Weapon& arme);
    
    //Fonctions
    public :
    
    void attack(void);    
    ~HumanA(void);
};

#endif