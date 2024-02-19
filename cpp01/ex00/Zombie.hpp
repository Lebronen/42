/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshay <rshay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:04:33 by rshay             #+#    #+#             */
/*   Updated: 2024/02/13 14:04:34 by rshay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie {

    // Attributs
    private : std::string  name;

    // Constructeur
    public : Zombie(std::string name);

    // Fonctions
    public : void announce(void);
    public : Zombie *newZombie(std::string name);
    void randomChump(std::string name);

    // Destructeur
   public :  ~Zombie();

};


#endif