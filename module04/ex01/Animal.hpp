/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 11:45:29 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/11/06 16:19:33 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Animal {

    protected:
        std::string type;
    public:
        virtual ~Animal( void );
        Animal( void );
        Animal( Animal& other );
        Animal& operator=(Animal& other);
        std::string getType ( void ) const;
        void makeSound( void ) const;
};