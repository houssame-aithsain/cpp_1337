/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:54:11 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/10/24 20:50:56 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av) {
    
    Harl obj;

    if (ac == 2)
        obj.complain(av[1]);
    else
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}
