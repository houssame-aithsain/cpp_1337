/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 15:45:34 by hait-hsa          #+#    #+#             */
/*   Updated: 2024/01/01 20:56:13 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main (int ac, char   *av[]) {

    PmergeMe head;
    clock_t  start;
    clock_t  end;
    clock_t  Dstart;
    clock_t  Dend;

    if (ac > 1) {
        for (int i = 1; av[i]; i++)
            head.inputParser(av[i]);
        try {
            // vector
            head.inputCheckToConvert();
            start = clock();
            head.mergeInsertionSort();
            end = clock();
            // deque
            head.DinputCheckToConvert();
            Dstart = clock();
            head.DmergeInsertionSort();
            Dend = clock();
            head.print(start, end, Dstart, Dend);
        } catch(const char  * err) {
            std::cout << RED << err << std::endl;
        } catch (std::exception & e) {
            std::cout << RED << e.what() << std::endl;
        }
    } else
        std::cout << USAGE << std::endl;
}
