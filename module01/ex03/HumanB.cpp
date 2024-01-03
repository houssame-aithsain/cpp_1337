/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 20:16:49 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/10/25 13:37:22 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

void HumanB::attack(){

    if (Sclub)
        std::cout << this->name << " attacks with their " << Sclub->getType() << std::endl;
}

HumanB::HumanB(const std::string& str){

    this->Sclub = NULL;
    this->name = str;
}

void HumanB::setWeapon(Weapon& club){

    Sclub = &club;
}

HumanB::HumanB( void ){

    this->Sclub = NULL;
    this->name = "";
}
