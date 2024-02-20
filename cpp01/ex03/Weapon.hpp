/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshay <rshay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 18:15:58 by lebronen          #+#    #+#             */
/*   Updated: 2024/02/20 12:46:33 by rshay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>

class Weapon {
    
    //attributs
    private :
    
    std::string type;

    //Constructeurs
    public :
    
    Weapon(std::string type);
    Weapon(void);
    ~Weapon(void);

    //Fonctions
    public :

    const std::string& getType(void);
    void setType(std::string type);
    ~Weapon(void);
};

#endif