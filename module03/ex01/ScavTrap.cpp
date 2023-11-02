/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:55:23 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/11/02 18:54:56 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {

    std::cout << "Default constructor called" << std::endl;
}

ScavTrap::~ScavTrap() {

    std::cout << "Distrcuter called!" << std::endl;
}

ScavTrap::ScavTrap (std::string name) {

    std::cout << "Copy constructor called" << std::endl;
    this->name = name;
    this->HitPoints = 10;
    this->EnergyPoints = 10;
    this->AttackDamage = 0;
}

void ScavTrap::attack(const std::string& target) { 

    if (this->HitPoints > 0 && this->EnergyPoints) {
        std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->AttackDamage << " points of damage!" << std::endl;
        this->EnergyPoints--;
    }
}

void guardGate( void ) {

    std::cout << "ScavTrap is now in Gate keeper mode" << std::endl;
}

unsigned int ScavTrap::GetAttackDamage(void) {

    return (this->AttackDamage);
}

void ScavTrap::SetAttackDamage(unsigned int amount) {

    this->AttackDamage = amount;
}