/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHor.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 16:24:05 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/10/21 16:33:56 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* Zombie::zombieHorde( int N, std::string name ){

    Zombie *z = new Zombie[N];
    for (int i = 0; i < N; i++){
        z[i].SetZombieNmae(name);
        z[i].announce();
    };
    return (z);
}
