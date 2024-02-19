/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshay <rshay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:22:38 by rshay             #+#    #+#             */
/*   Updated: 2024/02/13 16:53:34 by rshay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"


Zombie *Zombie::zombieHorde(int N, std::string name) {
    Zombie *first = newZombie(name);
    Zombie *tmp = first;
    for (int i = 1; i < N; i++) {
        tmp->next = newZombie(name);
        tmp = tmp->next;
    }
    return (first);
}

void Zombie::deleteHorde(Zombie *first) {
    Zombie *tmp = first;
    Zombie *tmp2;
    while (tmp)
    {
        tmp2 = tmp->getNext();
        delete tmp;
        tmp = tmp2;
    }
    
}

void Zombie::hordeAnnounce(Zombie *first) {
    Zombie *tmp = first;
    while (tmp) {
        tmp->announce();
        tmp = tmp->getNext();
    }
}