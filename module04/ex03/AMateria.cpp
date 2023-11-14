/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 19:20:34 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/11/12 14:17:01 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria (void) {}

AMateria::AMateria (AMateria& other) {

    *this = other;
}

AMateria::~AMateria (void) {}


AMateria::AMateria(std::string const & type) {

    this->type = type;
}

AMateria& AMateria::operator=(AMateria& other) {

    if (this != &other)
        this->type = other.type;
    return (*this);
}

std::string const & AMateria::getType() const {

    return (this->type);
}

void AMateria::use(ICharacter& target){

    target.use(0, target);
}
