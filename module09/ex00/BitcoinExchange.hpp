/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 10:19:01 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/12/30 20:06:34 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <exception>
#include <limits>
#include <list>
#include <map>

#define dataErr "failed to load database!"
#define userErr "failed to load user file!"
#define fdErr "Error: could not open file."
#define badInput "Error: bad input => "
#define outOfRange "Error: out of range => "
#define Nnumber "Error: not a positive number."
#define Lnumber "Error: too large a number."
#define LINE "---------------------------------------"

#define underLimit 20090102
#define uperLimit 20220329

#define SPACE 32
#define PIPE 124
#define HYPHEN 45
#define NEWLINE 10
#define NUll 0

#define IS_NUMBER(numb) (((numb >= '0' && numb <= '9') || numb == '-' || numb == '+' || numb == '.') ? true : false)
#define IS_VALIDE(c) (((c != SPACE) && (c != HYPHEN) && (c != NEWLINE) && (c != NUll)) ? true : false)
#define underUperLimits(date) ((date < underLimit || date > uperLimit) ? true : false)

class BitcoinExchange {

    private:
        std::map<std::string, std::string> dataBase;
        std::list<std::pair<std::string, std::string> > userFile;
        int Date;
    public:
        ~BitcoinExchange( void );
        BitcoinExchange( void );
        BitcoinExchange( const BitcoinExchange & other );
        BitcoinExchange & operator=(const BitcoinExchange & other);
        void dataBaseLoader( void );
        void userFileLoader( std::string fileName );
        void BitcoinExchangePrinter( void );
        bool tokenChecker( std::list<std::pair<std::string, std::string> >::iterator it ); 
        void tokenCleaner( std::list<std::pair<std::string, std::string> >::iterator it );
        bool formatChecker(std::string value);
};
