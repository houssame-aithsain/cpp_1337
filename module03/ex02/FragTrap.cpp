/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 07:42:26 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/11/03 18:42:28 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() {

    std::cout << "FragTrap Default constructor called" << std::endl;
    this->HitPoints = 100;
    this->EnergyPoints = 100;
    this->AttackDamage = 30;
}

FragTrap::~FragTrap() {

    std::cout << "FragTrap Distrcuter called!" << std::endl;
}

FragTrap::FragTrap (const FragTrap &other) {

    std::cout << "FragTrap Copy constructor called" << std::endl;
    *this = other;
}

FragTrap::FragTrap (std::string name) {

    std::cout << "FragTrap Parameterized Constructor called" << std::endl;
    this->name = name;
    this->HitPoints = 100;
    this->EnergyPoints = 100;
    this->AttackDamage = 30;
}

void FragTrap::attack(const std::string& target) { 

    if (this->HitPoints > 0 && this->EnergyPoints) {
        std::cout << "FragTrap " << this->name << " attacks " << target << ", causing " << this->AttackDamage << " points of damage!" << std::endl;
        this->EnergyPoints--;
    }
    std::cout << this->name << "'s energy points = " << this->EnergyPoints << std::endl;
}

void FragTrap::takeDamage(unsigned int amount) {

   if (this->HitPoints <= 0)
        this->HitPoints = 0;
    else 
        this->HitPoints -= amount;
    std::cout << this->name << " has lost " << amount << " points of damage" << std::endl;
}

void FragTrap::beRepaired(unsigned int amount) {

    if (this->HitPoints > 0 && this->EnergyPoints) {
        this->HitPoints += amount;
        std::cout << this->name << " is Repairing... DONE Hit Points = " << this->HitPoints << std::endl;
        this->EnergyPoints--;
        std::cout << this->name << "'s Energy Points = " << this->EnergyPoints << std::endl;
    }
}


FragTrap& FragTrap::operator=(const FragTrap& other) {

    std::cout << "FragTrap Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->name = other.name;
        this->HitPoints = other.HitPoints;
        this->EnergyPoints = other.EnergyPoints;
        this->AttackDamage = other.AttackDamage;
    }
    return (*this);
}

void FragTrap::highFivesGuys(void) {

    std::cout << "FragTrap high Fives Guy!" << std::endl;
}

std::string FragTrap::GetTargetName( void ) {

    return (this->name);
}

unsigned int FragTrap::GetAttackDamage(void) {

    return (this->AttackDamage);
}

void FragTrap::SetAttackDamage(unsigned int amount) {

    this->AttackDamage = amount;
}