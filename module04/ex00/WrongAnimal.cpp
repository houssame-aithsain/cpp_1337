/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 14:55:30 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/11/12 14:01:18 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

void WrongAnimal::makeSound( void ) const {
    
    std::cout << "wrong animal sound!" << std::endl;
}

std::string WrongAnimal::getType(void) const {

    return (this->type);
}

WrongAnimal::~WrongAnimal( void ) {

    std::cout << "WrongAnimal Destructer has been called!" << std::endl;
}

WrongAnimal::WrongAnimal( void ) {

    std::cout << "WrongAnimal Constructer has been called!" << std::endl;
    type = "wrong animal";
}

WrongAnimal::WrongAnimal(WrongAnimal& other ) {

    std::cout << "WrongAnimal Copy Constructer has been called!" << std::endl;
    *this = other;
}

WrongAnimal& WrongAnimal::operator=(WrongAnimal& other) {

    std::cout << "WrongAnimal Operator has been called!" << std::endl;
    if (this != &other)
        this->type = other.type;
    return (other);
}
