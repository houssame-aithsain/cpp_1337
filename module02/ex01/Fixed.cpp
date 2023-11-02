/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 11:23:34 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/10/31 20:54:47 by hait-hsa         ###   ########.fr       */
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

int Fixed::getRawBits( void ) const {

    std::cout << "getRawBits member function called" << std::endl;
    return this->fixed;
}

void Fixed::setRawBits( int const raw ) {
    
    std::cout << "setRawBits member function called" << std::endl;
    this->fixed = raw;
}
