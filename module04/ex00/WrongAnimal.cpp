/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 14:55:30 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/11/05 15:03:35 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

void WrongAnimal::makeSound( void ) const {
    
    if (!this->type.compare("WrongCat"))
        std::cout << "wrong cat" << std::endl;
    else if (!this->type.compare("Dog"))
        std::cout << "wrong dog" << std::endl;
}

std::string WrongAnimal::getType(void) const {

    return (this->type);
}

WrongAnimal::~WrongAnimal( void ) {}

WrongAnimal::WrongAnimal( void ) {}

WrongAnimal::WrongAnimal(WrongAnimal& other ) {

    *this = other;
}

WrongAnimal& WrongAnimal::operator=(WrongAnimal& other) {

    if (this != &other)
        this->type = other.type;
    return (other);
}
