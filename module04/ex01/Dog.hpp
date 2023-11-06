/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 11:47:47 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/11/06 16:22:05 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {

    private:
        Brain* brain;
    public:
        ~Dog( void );
        Dog( void );
        Dog(Dog &other);
        Dog& operator=(Dog& other);
};
