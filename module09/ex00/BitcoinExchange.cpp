/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 10:18:59 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/12/19 19:40:08 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::~BitcoinExchange( void ) {}

BitcoinExchange::BitcoinExchange( void ) {}

BitcoinExchange::BitcoinExchange( const BitcoinExchange & other ) {

    *this = other;
}

BitcoinExchange & BitcoinExchange::operator=(const BitcoinExchange & other) {

    if (this != &other) {
        dataBase.clear();
        userFile.clear();
        key.clear();
        dataBase.insert(other.dataBase.begin(), other.dataBase.end());
        userFile.insert(other.userFile.begin(), other.userFile.end());
        key.insert(key.begin(), other.key.begin(), other.key.end());
    }
    return (*this);
}

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
        return ;
    }
    std::cout << fdErr << std::endl;
    std::exit(78);
}

void BitcoinExchange::loadUserFile(std::string fileName) {

    std::ifstream fd(fileName);
    std::string line;
    std::string tmp;

    if (fd.is_open()) {
        while(std::getline(fd, line, '\n')) {
            tmp = line.substr(0, line.find(" | "));
            if (tmp.find(" ") != std::string::npos)
                throw "";
            else
                key.push_back(tmp);
            line = line.substr(tmp.length() + 3, line.find("\n"));
            if (line.find(" ") != std::string::npos)
                throw "";
            else
                userFile[tmp] = line;
            // std::cout << userFile[line.substr(0, line.find(" "))] << std::endl;
        }
        std::cout << "user file has been loaded successfully!" << std::endl;
        fd.close();
        return ;
    }
    std::cout << fdErr << std::endl;
    std::exit(77);
}

void BitcoinExchange::printBitcoinExchange( void ) {

    float result;
    char* container;
    std::string value;

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
        else if (*it < underLimit || *it > uperLimit)
            std::cout << "Error: date out of range => " << *it << std::endl;
    }
}
