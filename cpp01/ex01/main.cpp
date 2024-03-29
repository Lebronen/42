/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebronen <lebronen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:04:26 by rshay             #+#    #+#             */
/*   Updated: 2024/02/19 22:37:15 by lebronen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

int main() {
    Zombie z("zombie");
    Zombie *tsunami = z.zombieHorde(3, "tsunami");
    tsunami->hordeAnnounce(tsunami);
    tsunami->deleteHorde(tsunami);
    return 0;
}