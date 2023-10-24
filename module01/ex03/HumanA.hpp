/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 20:16:45 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/10/23 20:16:47 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include <iostream>

class HumanA{

    private:
        std::string name;
        Weapon *Sclub;
    public:
        void attack();
        HumanA(const std::string& str, Weapon& club);
};

#endif /*HUMANA_HPP*/
