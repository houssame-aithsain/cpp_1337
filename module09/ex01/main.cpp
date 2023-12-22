/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 13:25:25 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/12/22 11:52:48 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char *av[]) {

    RPN head;
    if (ac == 2) {
        try {
            head.inputParser(av[1]);
        } catch (const char *err) {
            std::cout << err << std::endl;
        }
    }
    else
        std::cout << "error" << std::endl;
}
