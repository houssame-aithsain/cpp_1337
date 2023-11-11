/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 19:20:34 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/11/11 15:14:46 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria (void){

}

AMateria::AMateria (AMateria& other) {

    *this = other;
}

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

    (void)target;
}

// AMateria* AMateria::clone() const {

//     return (new AMateria(this->type));
// }
