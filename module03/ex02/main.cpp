/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:41:52 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/11/03 18:38:35 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {

    ClapTrap clap("man");
    ClapTrap* scav = new ScavTrap("cat");
    ClapTrap* frag = new FragTrap("dog");

    // man attacks cat
    clap.SetAttackDamage(3);
    clap.attack(scav->GetTargetName());
    scav->takeDamage(clap.GetAttackDamage());
    scav->beRepaired(0);
    // cat attacks man
    scav->SetAttackDamage(5);
    scav->attack(clap.GetTargetName());
    clap.takeDamage(scav->GetAttackDamage());
    clap.beRepaired(1);
    // cat and dog attacks man
        //cat
    scav->SetAttackDamage(4);
    scav->attack(clap.GetTargetName());
    clap.takeDamage(scav->GetAttackDamage());
    clap.beRepaired(3);
        // dog
    frag->SetAttackDamage(2);
    frag->attack(clap.GetTargetName());
    clap.takeDamage(frag->GetAttackDamage());
    clap.beRepaired(4);
    // man attacks dog
    clap.SetAttackDamage(10);
    clap.attack(frag->GetTargetName());
    frag->takeDamage(clap.GetAttackDamage());
    frag->beRepaired(2);
}
