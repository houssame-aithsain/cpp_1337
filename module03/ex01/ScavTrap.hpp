/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:56:04 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/11/02 18:48:36 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {

    private:
        std::string name;
        unsigned int HitPoints;
        unsigned int EnergyPoints;
        unsigned int AttackDamage;
    public:
        ScavTrap();
        ~ScavTrap();
        void attack(const std::string& target);
        ScavTrap (std::string name);
        void guardGate( void );
        void SetAttackDamage(unsigned int amount);
        unsigned int GetAttackDamage(void);
};
