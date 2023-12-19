/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 10:19:04 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/12/19 15:38:27 by hait-hsa         ###   ########.fr       */
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
        } try {
            head.loadUserFile(argv[1]);
        } catch (...) {
            std::cout << userErr << std::endl;
        } try {
            head.printBitcoinExchange();
        } catch (...) {
            std::cout << userErr << std::endl;
        }
    }
}