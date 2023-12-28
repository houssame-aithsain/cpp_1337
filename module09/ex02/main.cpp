/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 15:45:34 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/12/28 10:49:47 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main (int ac, char   *av[]) {

    PmergeMe head;

    if (ac > 1) {
        for (int i = 1; av[i]; i++)
            head.inputParser(av[i]);
        try {
            head.inputCheckToConvert();
            head.mergeSort();
            head.insertSort();
        } catch(const char  * err) {
            std::cout << err << std::endl;
        }
    } else
        std::cout << USAGE << std::endl;
}
