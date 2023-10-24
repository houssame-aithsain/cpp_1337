/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 20:16:43 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/10/23 20:16:44 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

void HumanA::attack(){

    std::cout << this->name << " attacks with their " << Sclub->getType() << std::endl;
}

HumanA::HumanA(const std::string& str, Weapon& club) : name(str), Sclub(&club){}
