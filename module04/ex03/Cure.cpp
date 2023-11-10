/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 20:43:16 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/11/09 22:33:01 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::~Cure( void ) {

    
}

Cure::Cure( void ) {

    this->type = "cure";
}

Cure::Cure( Cure& other ) {

    *this = other;
}

Cure& Cure::operator=(Cure& other) {

    if (this != &other)
        this->type = other.type;
    return (other);
}

Cure* Cure::clone(void) const {

    return (new Cure());
}

void Cure::use(ICharacter& target) {

    std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}