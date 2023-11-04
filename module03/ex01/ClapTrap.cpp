/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:40:57 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/11/03 18:23:19 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {

    this->HitPoints = 10;
    this->EnergyPoints = 10;
    this->AttackDamage = 0;
    std::cout << "ClapTrap Default constructor called" << std::endl;
}

ClapTrap::~ClapTrap() {

    std::cout << "ClapTrap Distrcuter called!" << std::endl;
}

ClapTrap::ClapTrap (const ClapTrap& other) {

    std::cout << "ClapTrap Copy constructor called" << std::endl;
    *this = other;
}

ClapTrap::ClapTrap (std::string name) {

    std::cout << "ClapTrap Parameterized Constructor called" << std::endl;
    this->name = name;
    this->HitPoints = 10;
    this->EnergyPoints = 10;
    this->AttackDamage = 0;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {

    std::cout << "ClapTrap Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->name = other.name;
        this->HitPoints = other.HitPoints;
        this->EnergyPoints = other.EnergyPoints;
        this->AttackDamage = other.AttackDamage;
    }
    return (*this);
}

void ClapTrap::attack(const std::string& target) { 

    if (this->HitPoints > 0 && this->EnergyPoints) {
        std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->AttackDamage << " points of damage!" << std::endl;
        this->EnergyPoints--;
    }
    std::cout << this->name << "'s Energy Points = " << this->EnergyPoints << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {

    if (this->HitPoints <= 0)
        this->HitPoints = 0;
    else 
        this->HitPoints -= amount;
    std::cout << this->name << " has lost " << amount << " points of damage" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {

    if (this->HitPoints > 0 && this->EnergyPoints) {
        this->HitPoints += amount;
        std::cout << this->name << " is Repairing... DONE Hit Points = " << this->HitPoints << std::endl;
        this->EnergyPoints--;
        std::cout << this->name << "'s Energy Points = " << this->EnergyPoints << std::endl;
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