/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 11:45:29 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/11/12 13:22:00 by hait-hsa         ###   ########.fr       */
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
        virtual Animal& operator=(Animal& other);
        virtual std::string getType ( void ) const;
        virtual void makeSound( void ) const = 0;
};
