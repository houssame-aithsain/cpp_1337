/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:56:04 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/11/03 18:39:00 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {

    public:
        ScavTrap();
        ~ScavTrap();
        ScavTrap (std::string name);
        ScavTrap (const ScavTrap &other);
        ScavTrap& operator=(const ScavTrap& other);
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void guardGate( void );
        void SetAttackDamage(unsigned int amount);
        unsigned int GetAttackDamage(void);
        void beRepaired(unsigned int amount);
        std::string GetTargetName();
};
