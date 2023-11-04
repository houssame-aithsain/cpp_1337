/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:41:52 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/11/03 18:31:20 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    ClapTrap player2("homas");
    ClapTrap* player1 = new ScavTrap("simba");

    // simba attacks simba
    player1->SetAttackDamage(6);
    player1->attack(player2.GetTargetName());
    player2.takeDamage(player1->GetAttackDamage());
    player2.beRepaired(5);

    // Homas attacks simba
    player2.SetAttackDamage(4);
    player2.attack(player1->GetTargetName());
    player1->takeDamage(player2.GetAttackDamage());
    player1->beRepaired(7);
}
