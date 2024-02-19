/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebronen <lebronen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:29:19 by rshay             #+#    #+#             */
/*   Updated: 2024/02/19 22:22:08 by lebronen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() {
    std::cout << "Default constructor called" << std::endl;
    valeur = 0;
}

Fixed::Fixed(Fixed const &cpy) {
    std::cout << "Copy constructor called" << std::endl;
    *this = cpy;
}

Fixed::Fixed(int const entier) {
    std::cout << "Int constructor called" << std::endl;
    this->setRawBits(entier << this->bits);
}

Fixed::Fixed(float const flottant) {
     std::cout << "Float constructor called" << std::endl;
    int twoPower = 1 << this->bits;
    int rawVal = (int)roundf(flottant * twoPower);
    this->setRawBits(rawVal);
}

int Fixed::getRawBits(void) const{
    return this->valeur;
}

void Fixed::setRawBits(int const raw) {
    this->valeur = raw;
}

Fixed &Fixed::operator=(Fixed const &other) {
    std::cout << "Copy assignment operator called" << std::endl;
    this->valeur = other.getRawBits();
    return (*this);
}

int Fixed::toInt(void) const {
    return getRawBits() >> bits;
}

float Fixed::toFloat(void) const {
    return static_cast<float>(this->getRawBits()) / (1 << bits);
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
    
}

std::ostream &operator<<(std::ostream &o, Fixed const &f)
{
    return (o << f.toFloat());
}