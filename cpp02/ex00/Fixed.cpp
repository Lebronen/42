/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebronen <lebronen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:29:19 by rshay             #+#    #+#             */
/*   Updated: 2024/03/07 14:20:53 by lebronen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() {
    std::cout << "Default constructor called" << std::endl;
    valeur = 0;
}

Fixed::Fixed(Fixed& cpy) {
    std::cout << "Copy constructor called" << std::endl;
    *this = cpy;
}

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->valeur;
}

void Fixed::setRawBits(int const raw) {
    std::cout << "setRawBits member function called" << std::endl;
    this->valeur = raw;
}

Fixed &Fixed::operator=(Fixed &other) {
    std::cout << "Copy assignment operator called" << std::endl;
    this->valeur = other.getRawBits();
    return (*this);
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
    
}