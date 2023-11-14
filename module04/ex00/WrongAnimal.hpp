/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 14:54:04 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/11/12 14:05:32 by hait-hsa         ###   ########.fr       */
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
        void makeSound( void ) const;
};
