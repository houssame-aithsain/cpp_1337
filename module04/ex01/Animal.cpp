/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 11:46:42 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/11/06 17:06:05 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

void Animal::makeSound( void ) const {
    
    if (!this->type.compare("Cat"))
        std::cout << "QEWWWWWWWED QEWWWWWWED" << std::endl;
    else if (!this->type.compare("Dog"))
        std::cout << "HOEF HOEF" << std::endl;
}

std::string Animal::getType(void) const {

    return (this->type);
}

Animal::~Animal( void ) {

    std::cout << "Animal Destructer called" << std::endl;
}

Animal::Animal( void ) {

    std::cout << "Animal constructer called" << std::endl;
}

Animal::Animal(Animal& other ) {

    *this = other;
}

Animal& Animal::operator=(Animal& other) {

    std::cout << "=========> operator called!" << std::endl;
    if (this != &other)
        this->type = other.type;
    return (other);
}
