/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshay <rshay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:04:26 by rshay             #+#    #+#             */
/*   Updated: 2024/02/13 16:19:51 by rshay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

int main() {
    Zombie z("Tsunami");
    z.announce();
    Zombie *cod = z.newZombie("COD");
    cod->announce();
    z.randomChump("Plant");
    delete cod;
    return 0;
}