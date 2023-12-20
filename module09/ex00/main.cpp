/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 10:19:04 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/12/19 21:58:44 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char *argv[]) {

    BitcoinExchange head;

    if (argc == 2) {
        try {
            head.dataBaseLoader();
        } catch(...) {
            std::cout << dataErr << std::endl;
            std::exit(98);
        } try {
            head.userFileLoader(argv[1]);
        } catch (...) {
            std::cout << userErr << std::endl;
            std::exit(99);
        } try {
            head.BitcoinExchangePrinter();
        } catch (...) {
            std::cout << userErr << std::endl;
            std::exit(100);
        }
    }
    else
      std::cout << fdErr << std::endl;  
}
