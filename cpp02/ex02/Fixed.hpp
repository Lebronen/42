/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshay <rshay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:28:52 by rshay             #+#    #+#             */
/*   Updated: 2024/02/20 16:12:13 by rshay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXFLOAT_HPP
# define FIXFLOAT_HPP

#include <iostream>
#include <fstream>

class Fixed {

    //Attributs
    private :

    int valeur;
    static const int bits = 8;

    //Constructeurs
    public :

    Fixed(void);
    Fixed(Fixed const &cpy);
    Fixed(int const entier);
    Fixed(float const flottant);

    //Fonctions
    public :

    Fixed &operator=(Fixed const &other);
    int getRawBits(void) const;
    void setRawBits(int const raw);
    
    float toFloat(void) const;
    int toInt(void) const;
    
    bool operator>(const Fixed &other) const;
    bool operator<(const Fixed &other) const;
    bool operator>=(const Fixed &other) const;
    bool operator<=(const Fixed &other) const;
    bool operator==(const Fixed &other) const;
    bool operator!=(const Fixed &other) const;
    
    Fixed operator+(const Fixed &other) const;
    Fixed operator-(const Fixed &other) const;
    Fixed operator*(const Fixed &other) const;
    Fixed operator/(const Fixed &other) const;
    
    Fixed &operator++(void);
    Fixed operator++(int);
    Fixed &operator--(void);
    Fixed operator--(int);
    static Fixed &min(Fixed &f1, Fixed &f2);
    static const Fixed &min(const Fixed &f1,const Fixed &f2);
    static Fixed &max(Fixed &f1, Fixed &f2);
    static const Fixed &max(const Fixed &f1, const Fixed &f2);
    
    //Destructeur
    public :

    ~Fixed(void);
    
};

std::ostream &operator<<(std::ostream &o, Fixed const &f);

#endif