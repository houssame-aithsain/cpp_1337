/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 15:18:11 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/11/06 16:27:53 by hait-hsa         ###   ########.fr       */
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

    // if (this != &other)
    //     this->ideas = other.ideas;
    return (other);
}
