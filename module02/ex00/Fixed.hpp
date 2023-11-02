/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 11:23:30 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/10/28 14:37:32 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Fixed {

    private:
        int fixed;
        static const int fractionalBits = 8;
    public:
        Fixed ( void );
        Fixed ( const Fixed& fixed);
        Fixed& operator=(const Fixed& other);
        ~Fixed( void );
        int getRawBits( void ) const;
        void setRawBits( int const raw );
};
