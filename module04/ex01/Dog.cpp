/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 11:48:32 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/11/12 14:08:08 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::~Dog( void ) {

    delete this->brain;
    std::cout << "Dog Destructer has been called!" << std::endl;
}

Dog::Dog( void ) {

    this->brain = new Brain();
    std::cout << "Dog constructer has been called!" << std::endl;
    this->type = "Dog";
}

Dog::Dog( Dog& other ) {

    std::cout << "Dog Copy Constructer has been called!" << std::endl;
    *this = other;
}

Dog& Dog::operator=(Dog& other) {

    std::cout << "Dog Operator has been called!" << std::endl;
    if (this != &other) {
        this->type = other.type;
        if (other.brain) {
            delete this->brain;
            this->brain = new Brain(*(other.brain));
        }
    }
    return (*this);
}

void Dog::makeSound( void ) const {

    std::cout <<"dog sound!" << std::endl;
}
