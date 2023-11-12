/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 15:18:11 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/11/12 12:19:17 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::~Brain( void ) {

    std::cout << "Brain Destructer called" << std::endl;
}

Brain::Brain( void ) {

    std::cout << "Brain Constructer called" << std::endl;
}

Brain::Brain( Brain& other ) { 

    std::cout << "Brain Copy Constructer has been called!" << std::endl;
    *this = other;
}

Brain& Brain::operator=(Brain& other) {

    std::cout << "Brain Operator has been called!" << std::endl;
    if (this != &other)
        for (int i = 0; i < 100; i++)
            this->ideas[i] = other.ideas[i];
    return (*this);
}
