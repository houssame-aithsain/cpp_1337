/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 11:47:47 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/11/12 13:58:20 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class Dog : public Animal {

    public:
        ~Dog( void );
        Dog( void );
        Dog(Dog &other);
        Dog& operator=(Dog& other);
        void makeSound( void ) const;
};
