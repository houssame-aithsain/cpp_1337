/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 15:18:11 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/11/11 16:50:01 by hait-hsa         ###   ########.fr       */
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

    *this = other;
}

Brain& Brain::operator=(Brain& other) {

    if (this != &other)
        for (int i = 0; i < 100; i++)
            this->ideas[i] = other.ideas[i];
    return (*this);
}
