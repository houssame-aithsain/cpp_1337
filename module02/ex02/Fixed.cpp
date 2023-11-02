/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 11:23:34 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/10/31 20:55:28 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) {

    std::cout << "Default constructor called" << std::endl;
    this->fixed = 0;
}

Fixed::Fixed( const Fixed& fixed) {

    std::cout << "Copy constructor called" << std::endl;
    *this = fixed;
}

Fixed::~Fixed() {

    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed( const int num) {

    int scale;

    std::cout << "Int constructor called" << std::endl;
    scale = std::pow(2, this->fractionalBits);
    this->fixed = num * scale;
}

Fixed::Fixed( const float num) {

    std::cout << "Float constructor called" << std::endl;
    this->fixed = std::round(num * std::pow(2, this->fractionalBits));
}

std::ostream& operator<<(std::ostream& output, const Fixed& fixed) {

    output << fixed.toFloat();
    return output;
}

Fixed& Fixed::operator=(const Fixed& other) {

    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->fixed = other.fixed;
    return *this;
}

float Fixed::toFloat( void ) const {

    return(this->fixed / std::pow(2, this->fractionalBits));
}

int Fixed::toInt( void ) const {

    return (this->fixed / std::pow(2, this->fractionalBits));
}
// The 6 comparison operators: >, <, >=, <=, == and !=

bool Fixed::operator>(const Fixed& other) {

    return (this->fixed > other.fixed);
}

bool Fixed::operator<(const Fixed& other) {

    return (this->fixed < other.fixed);
}

bool Fixed::operator>=(const Fixed& other) {

    return (this->fixed >= other.fixed);
}

bool Fixed::operator<=(const Fixed& other) {

    return (this->fixed <= other.fixed);
}

bool Fixed::operator==(const Fixed& other) {

    return (this->fixed == other.fixed);
}

bool Fixed::operator!=(const Fixed& other) {

    return (this->fixed != other.fixed);
}

// The 4 arithmetic operators: +, -, *, and /

const Fixed Fixed::operator+(const Fixed& other) {

    Fixed result;
    result.fixed = this->fixed  + other.fixed;
    return (result);
}

const Fixed Fixed::operator-(const Fixed& other) {

    Fixed result;
    result.fixed = this->fixed - other.fixed;
    return (result);
}

const Fixed Fixed::operator*(const Fixed& other) {
    
    Fixed result;
    result.fixed = (this->fixed * other.fixed) >> this->fractionalBits;
    return (result);
}

const Fixed Fixed::operator/(const Fixed& other) {

    Fixed result;
    result.fixed = (this->fixed / other.fixed) << this->fractionalBits;
    return (result);
}

// pre-increment and post-increment, pre-decrement and post-decrement

const Fixed Fixed::operator++() {

    this->fixed++;
    return (*this);
}

const Fixed Fixed::operator++(int) {

    Fixed copy(*this);
    ++this->fixed;
    return (copy);
}

const Fixed Fixed::operator--() {

    this->fixed--;
    return (*this);
}

const Fixed Fixed::operator--(int) {

    Fixed copy(*this);
    --this->fixed;
    return (copy);
}

// MIN - MAX

const Fixed& Fixed::max(const Fixed& obj1, const Fixed& obj2) {

    if (obj1.fixed > obj2.fixed)
        return (obj1);
    else
        return (obj2);
}

Fixed& Fixed::max(Fixed& obj1, Fixed& obj2) {

    if (obj1.fixed > obj2.fixed)
        return (obj1);
    else
        return (obj2);
}

const Fixed& Fixed::min(const Fixed& obj1, const Fixed& obj2) {

    if (obj1.fixed < obj2.fixed)
        return (obj1);
    else
        return (obj2);
}

Fixed& Fixed::min(Fixed& obj1, Fixed& obj2) {

    if (obj1.fixed < obj2.fixed)
        return (obj1);
    else
        return (obj2);
}

int Fixed::getRawBits( void ) const {

    std::cout << "getRawBits member function called" << std::endl;
    return this->fixed;
}

void Fixed::setRawBits( int const raw ) {
    
    std::cout << "setRawBits member function called" << std::endl;
    this->fixed = raw;
}
