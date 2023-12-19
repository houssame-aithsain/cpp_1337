/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 10:19:01 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/12/19 19:19:37 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <exception>
#include <limits>
#include <deque>
#include <map>

#define dataErr "failed to load database!"
#define userErr "failed to load user file!"

#define underLimit "2009-01-02"
#define uperLimit "2022-03-29"

#define fdErr "Error: could not open file."

class BitcoinExchange {

    private:
        std::map<std::string, std::string> dataBase;
        std::map<std::string, std::string> userFile;
        std::deque<std::string> key;
    public:
        // ~BitcoinExchange( void );
        // BitcoinExchange( void );
        // BitcoinExchange( const BitcoinExchange & other );
        // BitcoinExchange & operator=(const BitcoinExchange & other);
        void loadDataBase( void );
        void loadUserFile( std::string fileName );
        void printBitcoinExchange( void );
};