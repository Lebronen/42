/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshay <rshay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:04:33 by rshay             #+#    #+#             */
/*   Updated: 2024/02/13 16:52:30 by rshay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie {

    // Attributs
    private : std::string  name;
    private : Zombie *next;

    // Constructeur
    public : Zombie(std::string name);

    // Fonctions
    public : void announce(void);
    public : Zombie *newZombie(std::string name);
    void randomChump(std::string name);
    public : Zombie *getNext();
    public : void setNext(std::string name);
    public : Zombie *zombieHorde(int N, std::string name);
    public : void deleteHorde(Zombie *first);
    public : void hordeAnnounce(Zombie *first);

    // Destructeur
   public :  ~Zombie();

};


#endif