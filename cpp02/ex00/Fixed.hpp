/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshay <rshay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:28:52 by rshay             #+#    #+#             */
/*   Updated: 2024/02/19 15:33:47 by rshay            ###   ########.fr       */
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

    //Fonctions
    public :

    Fixed &operator=(Fixed &other);
    int getRawBits(void);
    void setRawBits(int const raw);

    //Destructeur
    public :

    ~Fixed(void);
    
};

#endif