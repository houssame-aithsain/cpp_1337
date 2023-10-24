/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 20:17:09 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/10/23 20:17:11 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>
#include <cstring>

class Weapon{
    private:
        std::string type;
    public:
        Weapon( void );
        Weapon(const std::string str);
        const std::string& getType( void );
        void setType(const std::string &str);
};

#endif /*WEAPON_H*/