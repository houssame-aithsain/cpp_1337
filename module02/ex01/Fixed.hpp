/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 11:23:30 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/10/31 20:55:12 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cmath>

class Fixed {

    private:
        int fixed;
        static const int fractionalBits = 8;
    public:
        Fixed ( void );
        Fixed ( const Fixed& fixed);
        Fixed ( const int num);
        Fixed ( const float num);
        ~Fixed( void );
        float toFloat( void ) const;
        int toInt( void ) const;
        Fixed& operator=(const Fixed& other);
        int getRawBits( void ) const;
        void setRawBits( int const raw );
};

std::ostream& operator<<(std::ostream& output, const Fixed& fixed);