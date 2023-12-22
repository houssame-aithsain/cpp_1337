/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 10:18:59 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/12/22 13:29:50 by hait-hsa         ###   ########.fr       */
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
            // std::cout << dataBase[line.substr(0, line.find(","))] << std::endl;
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
            // std::cout << "line=>[" << line << "]" << std::endl;
            if (line.find(SPACE) == std::string::npos)
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
        // std::map<std::string, std::string>::iterator mm = userFile.begin();
        // for (;mm != userFile.end(); mm++) {
        //     std::cout << "tmp=> [" << mm->first << "]" << std::endl;
        //     std::cout << "line=> [" << mm->second << "]" << std::endl;
        // }
        std::cout << "user file has been loaded successfully!" << std::endl;
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
    // insert the valide data
    userFile.erase(*it);
    userFile[date] = value;
    *it = date;
    //end
    // std::cout << "-----------------------------------------\n";
    // for (std::map<std::string, std::string>::iterator mm = userFile.begin(); mm != userFile.end(); mm++) {
        // std::cout << "key===>[" << mm->first << "]" << std::endl;
        // std::cout << "value===>[" << mm->second << "]" << std::endl;
    // }
    // std::cout << "-----------------------------------------\n";
}

bool BitcoinExchange::tokenChecker( std::deque<std::string>::iterator it ) {

    std::string value;
    std::string date;
    int hyphenCount = 0;
    int pointCount = 0;

    date = *it;
    value = userFile[date];
    // std::cout << "date:=> [" << *it << "]" << std::endl;
    // std::cout << "value:=> [" << userFile[date] << "]" << std::endl;
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
        if (!IS_NUMBER(value[i]) || value[i + 1] == '-' || value[i + 1] == '+')
            return false;
    }
    if (date.empty() || value.empty() || hyphenCount < 2 || pointCount > 1)
        return false;
    return true;
}

bool BitcoinExchange::underUperLimits(std::string value) {

    std::string numb;
    char *container;
    size_t x = 0;
    float user;

    // check date format
    
    for (size_t i = 0; i < value.size(); i++) {
        if (value[i] != HYPHEN)
            numb[x++] = value[i];
    }
    user = static_cast<float>(std::strtod(numb.c_str(), &container));
    return (user < underLimit || user > uperLimit);
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
            std::cout << "-----------------------------------------\n";
    for (; it != key.end(); it++) {
        if (!tokenChecker(it)) {
            std::cout << badInput << *it << std::endl;
            continue;
        }
        if (underUperLimits(*it)) {
            std::cout << "Error: out of range => " << *it << std::endl;
            continue;
        }
        tokenCleaner(it);
        userValue = userFile[*it];
        std::map<std::string, std::string>::iterator mm = dataBase.upper_bound(*it);
        mm--;
        dataBaseValue = mm->second;
        if (std::strtod(userValue.c_str(), &container) < 0) {
            std::cout << "Error: not a positive number." << std::endl;
            continue;
        }
        if ((std::strtod(userValue.c_str(), &container) > 1000)) {
            std::cout << "Error: too large a number." << std::endl;
            continue;
        }
        result = (std::strtod(userValue.c_str(), &container) * std::strtod(dataBaseValue.c_str(), &container));
        std::cout << *it << " | " << result << std::endl;
    }
            std::cout << "-----------------------------------------\n";
    // std::map<std::string, std::string>::iterator mm = userFile.begin();
    // for (;mm != userFile.end(); mm++) {
    //     std::cout << "tmp=> [" << mm->first << "]" << std::endl;
    //     std::cout << "line=> [" << mm->second << "]" << std::endl;
    // }
}
