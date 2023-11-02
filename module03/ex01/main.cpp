/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:41:52 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/11/02 18:51:40 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {

    // ClapTrap player1("homas");
    // ClapTrap player2("simba");

    // // homas attacks simba
    // player1.SetAttackDamage(6);
    // player1.attack(player2.GetTargetName());
    // player2.takeDamage(player1.GetAttackDamage());
    // player2.beRepaired(5);
    // // sima will attack now
    // player2.SetAttackDamage(6);
    // player2.attack(player1.GetTargetName());
    // player1.takeDamage(player2.GetAttackDamage());
    // player1.beRepaired(5);
    ClapTrap player2("homas");
    ClapTrap* player1 = new ScavTrap("simba");
    player1->SetAttackDamage(6);
    player1->attack(player2.GetTargetName());
    // player1->SetAttackDamage(10);
    player2.takeDamage(player1->GetAttackDamage());
    player2.beRepaired(5);
    
}
