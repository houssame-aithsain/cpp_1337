/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:40:57 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/11/01 17:25:14 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {

    HitPoints = 10;
    EnergyPoints = 10;
    AttackDamages = 0;
}

ClapTrap::~ClapTrap() {

    std::cout << "Distrcuter called!" << std::endl;
}

ClapTrap::ClapTrap (ClapTrap& other) {

    this->name = other.name;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {

    if (this != &other)
        this->name = other.name;
    return (*this);
}

void ClapTrap::attack(const std::string& target) { 

    if (this->HitPoints && this->EnergyPoints) {
        std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->AttackDamages << "  points of damage!" << std::endl;
        this->EnergyPoints--;
    }
}

void ClapTrap::takeDamage(unsigned int amount) {

    
}

void ClapTrap::beRepaired(unsigned int amount) {

    if (this->EnergyPoints) {
        std::cout << "Repairing" << std::endl;
        this->EnergyPoints--;
    }
}