/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebronen <lebronen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:29:19 by rshay             #+#    #+#             */
/*   Updated: 2024/03/07 16:00:59 by lebronen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() {
    valeur = 0;
}

Fixed::Fixed(Fixed const &cpy) {
    *this = cpy;
}

Fixed::Fixed(int const entier) {
    this->setRawBits(entier << this->bits);
}

Fixed::Fixed(float const flottant) {
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
    this->valeur = other.getRawBits();
    return (*this);
}

int Fixed::toInt(void) const {
    return getRawBits() >> bits;
}

float Fixed::toFloat(void) const {
    return static_cast<float>(this->getRawBits()) / (1 << bits);
}

bool Fixed::operator>(const Fixed &other) const {
    return valeur > other.valeur;
}

bool Fixed::operator<(const Fixed &other) const {
    return valeur < other.valeur;
}

bool Fixed::operator>=(const Fixed &other) const {
    return valeur >= other.valeur;
}

bool Fixed::operator<=(const Fixed &other) const {
    return valeur <= other.valeur;
}

bool Fixed::operator==(const Fixed &other) const {
    return valeur == other.valeur;
}

bool Fixed::operator!=(const Fixed &other) const {
    return valeur != other.valeur;
}

Fixed Fixed::operator+(const Fixed &other) const {
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) const {
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) const {
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const {
    return Fixed(this->toFloat() / other.toFloat());
}

Fixed &Fixed::min(Fixed &f1, Fixed &f2) {
    if (f1 <= f2)
        return (f1);
    return (f2);
}

 const Fixed &Fixed::min(const Fixed &f1,const Fixed &f2) {
    if (f1 <= f2)
        return (f1);
    return (f2);
}

Fixed &Fixed::max(Fixed &f1, Fixed &f2) {
    if (f1 >= f2)
        return (f1);
    return (f2);
}

const Fixed &Fixed::max(const Fixed &f1,const Fixed &f2) {
    if (f1 >= f2)
        return (f1);
    return (f2);
}

Fixed &Fixed::operator++(void) {
    ++valeur;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed tmp(this->toFloat());
    ++valeur;
    return tmp;
}

Fixed &Fixed::operator--(void) {
    --valeur;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed tmp(valeur);
    valeur--;
    return tmp;
}

Fixed::~Fixed() {
    
}

std::ostream &operator<<(std::ostream &o, Fixed const &f)
{
    return (o << f.toFloat());
}