/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Materia.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:55:53 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/11/10 18:00:17 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Materia.hpp"

Materia::Materia (void){

}

Materia::Materia (Materia& other) {

    *this = other;
}

Materia::Materia(std::string const & type) {

    this->type = type;
}

Materia& Materia::operator=(Materia& other) {

    if (this != &other)
        this->type = other.type;
    return (*this);
}

std::string const & Materia::getType() const {

    return (this->type);
}

void Materia::use(ICharacter& target){

    (void)target;
}

Materia* Materia::clone() const {

    return (new Materia());
}
