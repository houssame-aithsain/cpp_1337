/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 11:46:42 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/11/12 12:20:19 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

void Animal::makeSound( void ) const {
    
    std::cout << type << " sound!" << std::endl;
}

std::string Animal::getType(void) const {

    return (this->type);
}

Animal::~Animal( void ) {

    std::cout << "Animal Destructer has been called!" << std::endl;
}

Animal::Animal( void ) {

    std::cout << "Animal Constructer has been called!" << std::endl;
}

Animal::Animal(Animal& other ) {

    std::cout << "Animal Copy Constructer has been called!" << std::endl;
    *this = other;
}

Animal& Animal::operator=(Animal& other) {

    std::cout << "Animal Operator has been called!" << std::endl;
    if (this != &other)
        this->type = other.type;
    return (*this);
}
