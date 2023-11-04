/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 07:40:28 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/11/03 17:51:11 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {

    public:
        ~FragTrap();
        FragTrap();
        FragTrap (std::string name);
        FragTrap (const FragTrap &other);
        void attack(const std::string& target);
        void SetAttackDamage(unsigned int amount);
        unsigned int GetAttackDamage(void);
        void beRepaired(unsigned int amount);
        std::string GetTargetName( void );
        void takeDamage(unsigned int amount);
        FragTrap& operator=(const FragTrap& other);
        void highFivesGuys(void);
};
