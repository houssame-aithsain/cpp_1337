/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverte.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 13:12:34 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/12/03 18:04:18 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <iomanip>
#include <limits>
#include <cmath>

class ScalarConverte {
    
    private:
        ~ScalarConverte( void );
        ScalarConverte( void );
        ScalarConverte(const ScalarConverte & other );
        ScalarConverte& operator=(const ScalarConverte & other);
    public:
        static void convert(std::string value);
        void charConverter(double dsNotaion, char c);
};
