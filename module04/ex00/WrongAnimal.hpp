/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 14:54:04 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/11/12 11:38:16 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class WrongAnimal {

    protected:
        std::string type;
    public:
        ~WrongAnimal( void );
        WrongAnimal( void );
        WrongAnimal( WrongAnimal& other );
        WrongAnimal& operator=(WrongAnimal& other);
        std::string getType ( void ) const;
        virtual void makeSound( void ) const;
};
