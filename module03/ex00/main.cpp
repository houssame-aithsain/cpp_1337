/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:41:52 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/11/03 14:58:36 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {

    ClapTrap player1("homas");
    ClapTrap player2("simba");

    // homas attacks simba
    player1.SetAttackDamage(6);
    player1.attack(player2.GetTargetName());
    player2.takeDamage(player1.GetAttackDamage());
    player2.beRepaired(5);
    // sima will attack now
    player2.SetAttackDamage(6);
    player2.attack(player1.GetTargetName());
    player1.takeDamage(player2.GetAttackDamage());
    player1.beRepaired(5);
    }
