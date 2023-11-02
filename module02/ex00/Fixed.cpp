/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 11:23:34 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/10/31 20:53:54 by hait-hsa         ###   ########.fr       */
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

int Fixed::getRawBits( void ) const {

    std::cout << "getRawBits member function called" << std::endl;
    return this->fixed;
}

void Fixed::setRawBits( int const raw ) {
    
    std::cout << "setRawBits member function called" << std::endl;
    this->fixed = raw;
}

Fixed& Fixed::operator=(const Fixed& other) {

    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->fixed = other.getRawBits();
    return *this;
}