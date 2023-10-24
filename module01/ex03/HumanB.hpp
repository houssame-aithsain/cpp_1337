/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 20:16:54 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/10/23 20:16:55 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <iostream>

class HumanB{

    private:
        std::string name;
        Weapon* Sclub;
    public:
        void attack();
        HumanB(const std::string& str);
        void setWeapon(Weapon& club);
};

#endif /*HUMANB_HPP*/
