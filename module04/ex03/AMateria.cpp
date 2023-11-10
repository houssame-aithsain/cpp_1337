/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 19:20:34 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/11/10 11:54:00 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria (void){

}

AMateria::AMateria(std::string const & type) {

    this->type = type;
}

std::string const & AMateria::getType() const {

    return (this->type);
}

void AMateria::use(ICharacter& target){

    (void)target;
}