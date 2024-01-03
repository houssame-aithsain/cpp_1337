/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:54:08 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/10/25 14:03:00 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::printError( void ) {

    std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}

void Harl::debug( void ) {
    std::cout << "DEBUG: love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}
void Harl::info( void ) {
    std::cout << "INFO: cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}
void Harl::warning( void ) {
    std::cout << "WARNING: think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}
void Harl::error( void ) {
    std::cout << "ERROR: This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain( std::string level ) {

    int i = 0;
    std::string name[5];
    Harl::PointerToFunction ptr[4];

    name[0] = "DEBUG";
    name[1] = "INFO";
    name[2] = "WARNING";
    name[3] = "ERROR";
    name[4] = "";

    ptr[0] = &Harl::debug;
    ptr[1] = &Harl::info;
    ptr[2] = &Harl::warning;
    ptr[3] = &Harl::error;

    for (; name[i] != level && i < 4; i++){};
    
    switch(i) {
    case 0:
        (this->*ptr[0])();
    case 1:
        (this->*ptr[1])();
    case 2:
        (this->*ptr[2])();
    case 3:
        (this->*ptr[3])();
        break;
    default:
        this->printError();
    }
}
