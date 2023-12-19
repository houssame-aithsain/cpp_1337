/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 10:19:04 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/12/19 19:41:09 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char *argv[]) {

    BitcoinExchange head;

    if (argc == 2) {
        try {
            head.loadDataBase();
        } catch(...) {
            std::cout << dataErr << std::endl;
            std::exit(98);
        } try {
            head.loadUserFile(argv[1]);
        } catch (...) {
            std::cout << userErr << std::endl;
            std::exit(99);
        } try {
            head.printBitcoinExchange();
        } catch (...) {
            std::cout << userErr << std::endl;
            std::exit(100);
        }
    }
    else
      std::cout << fdErr << std::endl;  
}
