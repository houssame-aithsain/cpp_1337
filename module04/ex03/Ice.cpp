/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 20:43:28 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/11/24 19:26:37 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::~Ice( void ) {}

Ice::Ice( void ) {

    this->type = "ice";
}

Ice::Ice( Ice& other ) {

    this->type = "ice";
    *this = other;
}

Ice& Ice::operator=(Ice& other) {

    if (this != &other)
        this->type = other.type;
    return (other);
}

Ice* Ice::clone(void) const {

    return (new Ice());
}

void Ice::use(ICharacter& target) {

    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
