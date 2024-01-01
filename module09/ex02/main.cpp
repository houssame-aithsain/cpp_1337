/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 15:45:34 by hait-hsa          #+#    #+#             */
/*   Updated: 2024/01/01 20:17:33 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main (int ac, char   *av[]) {

    PmergeMe head;
    clock_t  start;
    clock_t  end;

    if (ac > 1) {
        for (int i = 1; av[i]; i++)
            head.inputParser(av[i]);
        try {
            head.inputCheckToConvert();
            start = clock();
            head.mergeInsertionSort();
            end = clock();
            head.print(start, end);
        } catch(const char  * err) {
            std::cout << RED << err << std::endl;
        } catch (std::exception & e) {
            std::cout << RED << e.what() << std::endl;
        }
    } else
        std::cout << USAGE << std::endl;
}
