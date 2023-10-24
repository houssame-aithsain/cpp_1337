/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 20:17:05 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/10/23 20:17:07 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

const std::string& Weapon::getType( void ){

    return (this->type);
}

void Weapon::setType(const std::string &str){

    this->type = str;
}

Weapon::Weapon(const std::string str){
    
    this->type = str;
}

Weapon::Weapon( void ){};