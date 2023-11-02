/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:40:57 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/11/02 13:33:54 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {

    std::cout << "Default constructor called" << std::endl;
}

ClapTrap::~ClapTrap() {

    std::cout << "Distrcuter called!" << std::endl;
}

ClapTrap::ClapTrap (std::string name) {

    std::cout << "Copy constructor called" << std::endl;
    this->name = name;
    this->HitPoints = 10;
    this->EnergyPoints = 10;
    this->AttackDamage = 0;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {

    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->name = other.name;
    return (*this);
}

void ClapTrap::attack(const std::string& target) { 

    if (this->HitPoints > 0 && this->EnergyPoints) {
        std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->AttackDamage << " points of damage!" << std::endl;
        this->EnergyPoints--;
    }
}

void ClapTrap::takeDamage(unsigned int amount) {

    this->HitPoints -= amount;
    if (this->HitPoints < 0)
        this->HitPoints = 0;
}

void ClapTrap::beRepaired(unsigned int amount) {

    if (this->HitPoints > 0 && this->EnergyPoints) {
        std::cout << this->name << " is Repairing..." << std::endl;
        this->HitPoints += amount;
        this->EnergyPoints--;
    }
}

unsigned int ClapTrap::GetAttackDamage(void) {

    return (this->AttackDamage);
}

void ClapTrap::SetAttackDamage(unsigned int amount) {

    this->AttackDamage = amount;
}

std::string ClapTrap::GetTargetName( void ) {

    return (this->name);
}