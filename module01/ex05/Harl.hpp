/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:54:05 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/10/25 13:48:11 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

class Harl{
    private:
        void debug( void );
        void info( void );
        void warning( void );
        void error( void );
        typedef void (Harl::*PointerToFunction)();
    public:
        void complain( std::string level );
};

#endif /*HARL_HPP*/