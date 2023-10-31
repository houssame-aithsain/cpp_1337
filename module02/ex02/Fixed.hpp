/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 11:23:30 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/10/31 15:50:25 by hait-hsa         ###   ########.fr       */
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
        static Fixed& min(Fixed& fixed1, Fixed& fixed2);
        static Fixed& max(Fixed& obj1, Fixed& obj2);
        static const Fixed& min(const Fixed& fixed1, const Fixed& fixed2);
        static const Fixed& max(const Fixed& obj1, const Fixed& obj2);
        // The 6 comparison operators: >, <, >=, <=, == and !=
        Fixed& operator=(const Fixed& obj);
        const Fixed& operator>(const Fixed& obj);
        const Fixed& operator<(const Fixed& obj);
        bool operator<=(const Fixed& obj);
        bool operator>=(const Fixed& obj);
        bool operator==(const Fixed& obj);
        bool operator!=(const Fixed& obj);
        // The 4 arithmetic operators: +, -, *, and /
        const Fixed operator+(const Fixed& obj);
        const Fixed operator-(const Fixed& obj);
        const Fixed operator*(const Fixed& obj);
        const Fixed operator/(const Fixed& obj);
        // pre-increment and post-increment, pre-decrement and post-decrement
        const Fixed operator++();
        const Fixed operator++(int);
        const Fixed operator--();
        const Fixed operator--(int);
};

std::ostream& operator<<(std::ostream& output, const Fixed& fixed);