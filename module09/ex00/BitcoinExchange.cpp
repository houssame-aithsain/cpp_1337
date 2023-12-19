/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 10:18:59 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/12/19 18:40:12 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// BitcoinExchange::~BitcoinExchange( void ) {}

// BitcoinExchange::BitcoinExchange( void ) {}

// BitcoinExchange::BitcoinExchange( const BitcoinExchange & other ) {}

// BitcoinExchange & BitcoinExchange::operator=(const BitcoinExchange & other) {}

void BitcoinExchange::loadDataBase( void ) {

    std::ifstream fd("data.csv");
    std::string line;
    std::string tmp;

    if (fd.is_open()) {
        while(std::getline(fd, line, '\n')) {
            tmp = line.substr(0, line.find(","));
            dataBase[tmp] = line.substr(tmp.length() + 1, line.find("\n"));
            // std::cout << dataBase[line.substr(0, line.find(","))] << std::endl;
        }
        std::cout << "database has been loaded successfully!" << std::endl;
        fd.close();
    }
}

void BitcoinExchange::loadUserFile(std::string fileName) {

    std::ifstream fd(fileName);
    std::string line;
    std::string tmp;

    if (fd.is_open()) {
        while(std::getline(fd, line, '\n')) {
            tmp = line.substr(0, line.find(" | "));
            key.push_back(tmp);
            userFile[tmp] = line.substr(tmp.length() + 3, line.find("\n"));
            // std::cout << userFile[line.substr(0, line.find(" "))] << std::endl;
        }
        std::cout << "user file has been loaded successfully!" << std::endl;
        fd.close();
    }
}

void BitcoinExchange::printBitcoinExchange( void ) {

    char* container;
    std::string value;
    float result;

    std::deque<std::string>::iterator it = key.begin();
    if (it != key.end())
        it++;
    for (; it != key.end(); it++) {
        value = userFile[*it];
        result = std::strtod(value.c_str(), &container);
        if (!strcmp(container, "") && !value.empty() && dataBase.size() > 0 && (*it >= underLimit && *it <= uperLimit)) {
            std::map<std::string, std::string>::iterator mt = dataBase.upper_bound(*it);
            mt--;
            value = mt->second;
            result = static_cast<float>(result * std::strtod(value.c_str(), &container));
            if (result < 0)
                std::cout << "Error: not a positive number." << std::endl;
            else if (result > std::numeric_limits<float>::max())
                std::cout << "Error: too large a number." << std::endl;
            else
                std::cout << *it << " => " << userFile[*it] << " = " << std::fixed << std::setprecision(2) << result << std::endl;
        } else if ((std::strcmp(container, "") && container[0]))
            std::cout << "Error: bad input => " << *it << std::endl;
        else
            std::cout << "Error: date out of range => " << *it << std::endl;
    }
}
