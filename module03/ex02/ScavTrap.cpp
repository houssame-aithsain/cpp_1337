/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:55:23 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/11/03 18:14:23 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap (const ScavTrap &other){

    std::cout << "ScavTrap copy constructor called" << std::endl;
    *this = other;
}

ScavTrap::ScavTrap() {

    this->HitPoints = 100;
    this->EnergyPoints = 50;
    this->AttackDamage = 20;
    std::cout << "ScavTrap Default constructor called" << std::endl;
}

ScavTrap::~ScavTrap() {

    std::cout << "ScavTrap Distrcuter called!" << std::endl;
}

ScavTrap::ScavTrap (std::string name) {

    std::cout << "ScavTrap Parameterized Constructor called" << std::endl;
    this->name = name;
    this->HitPoints = 100;
    this->EnergyPoints = 50;
    this->AttackDamage = 20;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other){

    std::cout << "ScavTrap Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->name = other.name;
        this->HitPoints = other.HitPoints;
        this->EnergyPoints = other.EnergyPoints;
        this->AttackDamage = other.AttackDamage;
    }
    return (*this); 
}

void ScavTrap::beRepaired(unsigned int amount) {

    if (this->HitPoints > 0 && this->EnergyPoints) {
        this->HitPoints += amount;
        std::cout << this->name << " is Repairing... DONE HitPoints = " << this->HitPoints << std::endl;
        this->EnergyPoints--;
    }
}

void ScavTrap::takeDamage(unsigned int amount) {

    if (this->HitPoints <= 0)
        this->HitPoints = 0;
    else 
        this->HitPoints -= amount;
    std::cout << this->name << " has lost " << amount << " points of damage" << std::endl;
}

void ScavTrap::attack(const std::string& target) { 

    if (this->HitPoints > 0 && this->EnergyPoints) {
        std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->AttackDamage << " points of damage!" << std::endl;
        this->EnergyPoints--;
    }
}

void ScavTrap::guardGate( void ) {

    std::cout << "ScavTrap is now in Gate keeper mode" << std::endl;
}

unsigned int ScavTrap::GetAttackDamage(void) {

    return (this->AttackDamage);
}

void ScavTrap::SetAttackDamage(unsigned int amount) {

    this->AttackDamage = amount;
}

std::string ScavTrap::GetTargetName( void ) {

    return (this->name);
}
