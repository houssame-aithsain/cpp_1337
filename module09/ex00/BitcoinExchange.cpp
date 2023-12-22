/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 10:18:59 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/12/22 20:32:40 by hait-hsa         ###   ########.fr       */
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
        dataBase = other.dataBase;
        userFile = other.userFile;
        key = other.key;
    }
    return (*this);
}

void BitcoinExchange::dataBaseLoader( void ) {

    std::ifstream fd("data.csv");
    std::string line;
    std::string tmp;

    if (fd.is_open()) {
        while(std::getline(fd, line, '\n')) {
            tmp = line.substr(0, line.find(","));
            dataBase[tmp] = line.substr(tmp.length() + 1, line.find("\n"));
        }
        std::cout << "database has been loaded successfully!" << std::endl;
        fd.close();
        return ;
    }
    std::cout << fdErr << std::endl;
    std::exit(78);
}

void BitcoinExchange::userFileLoader(std::string fileName) {

    std::ifstream fd(fileName);
    std::string line;
    std::string tmp;

    if (fd.is_open()) {
        while(std::getline(fd, line, '\n')) {
            if (line.find(SPACE) == std::string::npos || line.find(PIPE) == std::string::npos)
                tmp = line.substr(0, line.length());
            else
                tmp = line.substr(0, line.find(SPACE));
            key.push_back(tmp);
            if (line.find("\n") == std::string::npos) {
                if (tmp.length() == line.length())
                    line = line.substr(tmp.length(), line.find("\n"));
                else {
                    if (line[tmp.length() + 1] == PIPE && line[tmp.length() + 2] != SPACE)
                        line = line.substr(tmp.length() + 1, line.find("\n"));
                    else
                        line = line.substr(tmp.length() + 2, line.find("\n"));
                }
            } else
                line = line.substr(0, line.find("\n"));
            userFile[tmp] = line;
        }
        std::cout << "user file has been loaded successfully!" << std::endl;
        std::cout << LINE << std::endl;
        fd.close();
        return ;
    }
    std::cout << fdErr << std::endl;
    std::exit(77);
}

void BitcoinExchange::tokenCleaner( std::deque<std::string>::iterator it ) {

    std::string value = userFile[*it];
    std::string date = *it;

    date = date.substr(0, date.find(SPACE));
    value = value.substr(value.find(SPACE) + 1, value.length() - value.find(SPACE));
    userFile.erase(*it);
    userFile[date] = value;
    *it = date;
}

bool BitcoinExchange::tokenChecker( std::deque<std::string>::iterator it ) {

    std::string value;
    std::string date;
    int hyphenCount = 0;
    int pointCount = 0;

    date = *it;
    value = userFile[date];
    for (size_t i = 0; i < date.size(); i++) {
        //check for spaces && pipes && hyphen numb
        if (date[0] == HYPHEN)
            return false;
        if (date[i] == HYPHEN)
            hyphenCount++;
        if (hyphenCount > 2 || (date[i] == HYPHEN && !IS_NUMBER(date[i + 1])))
            return false;
        if (i == 0 && date[i] == SPACE)
            return false;
        if (!date[i] || (date[i] == SPACE && !i))
            return false;
        if ((date[i] == SPACE && date[i + 1]) || date[i] == PIPE)
            return false;
        // check for non numbers
        if (IS_VALIDE(date[i]) && !IS_NUMBER(date[i]))
            return false;
        if (date[i] == HYPHEN && date[i + 1] == HYPHEN)
            return false;
    }
    for (size_t i = 0; i < value.size(); i++) {
        //check for spaces && pipes
         if (value[i] == '.')
            pointCount++;
        if (i == 0 && value[i] == SPACE)
            i++;
        if (!value[i] || (value[i] == SPACE && !i))
            return false;
        if ((value[i] == SPACE && value[i + 1]) || value[i] == PIPE)
            return false;
        //check for non numbers
        if (!IS_NUMBER(value[i]) || value[i + 1] == HYPHEN || value[i + 1] == '+')
            return false;
    }
    if (date.empty() || value.empty() || hyphenCount < 2 || pointCount > 1)
        return false;
    return true;
}

bool BitcoinExchange::formatChecker(std::string value) {

    std::string toNumber;
    std::string tmp;
    // check date format
    std::stringstream s(value);
    for (int i = 0; std::getline(s, tmp, '-') && i < 3; i++) {
        if (i == 0 && tmp.size() != 4)
            return false;
        if (i == 1 && (tmp.size() != 2 || (std::atoi(tmp.c_str()) < 0 || std::atoi(tmp.c_str()) > 12)))
            return false;
        if (i == 2 && (tmp.size() != 2 || (std::atoi(tmp.c_str()) < 0 || std::atoi(tmp.c_str()) > 32)))
            return false;
        toNumber += tmp;
    }
    Date = std::atoi(toNumber.c_str());
    return true;
}

void BitcoinExchange::BitcoinExchangePrinter( void ) {

    char *container;
    std::string userValue;
    std::string dataBaseValue;
    double result;

    std::cout << std::setprecision(std::numeric_limits<double>::digits10 + 1);
    std::deque<std::string>::iterator it = key.begin();
    if (it != key.end())
        it++;
    for (; it != key.end(); it++) {
        if (!tokenChecker(it) || !formatChecker(*it)) {
            std::cout << badInput << *it << std::endl;
            continue;
        } if (underUperLimits(Date)) {
            std::cout << outOfRange << *it << std::endl;
            continue;
        }
        tokenCleaner(it);
        userValue = userFile[*it];
        std::map<std::string, std::string>::iterator mm = dataBase.upper_bound(*it);
        mm--;
        dataBaseValue = mm->second;
        if (std::strtod(userValue.c_str(), &container) < 0) {
            std::cout << Nnumber << std::endl;
            continue;
        } if ((std::strtod(userValue.c_str(), &container) > 1000)) {
            std::cout << Lnumber << std::endl;
            continue;
        }
        result = (std::strtod(userValue.c_str(), &container) * std::strtod(dataBaseValue.c_str(), &container));
        std::cout << *it << " | " << result << std::endl;
    }
}
