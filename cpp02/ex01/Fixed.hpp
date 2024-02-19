/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshay <rshay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:28:52 by rshay             #+#    #+#             */
/*   Updated: 2024/02/19 16:20:43 by rshay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXFLOAT_HPP
# define FIXFLOAT_HPP

#include <iostream>

class Fixed {

    //Attributs
    private :

    int valeur;
    const static int bits = 8;

    //Constructeurs
    public :

    Fixed(void);
    Fixed(Fixed& cpy);
    Fixed(int const entier);
    Fixed(float const flottant);

    //Fonctions
    public :

    Fixed &operator=(Fixed &other);
    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat(void) const;
    int toInt(void) const;

    //Destructeur
    public :

    ~Fixed(void);
    
};

std::ostream &operator<<(std::ostream &o, Fixed const &f);

#endif