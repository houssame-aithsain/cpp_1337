/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 11:48:32 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/11/06 18:09:25 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::~Dog( void ) {

    std::cout << "Dog Destructer called" << std::endl;
    delete this->brain;
}

Dog::Dog( void ) {

    std::cout << "Dog Constructer called" << std::endl;
    this->brain = new Brain();
    this->type = "Dog";
}

Dog::Dog( Dog& other ) {

    std::cout << "=========> Dog's Copy Constructer Called " << std::endl;
    *this = other;
}

Dog& Dog::operator=(Dog& other) {

    std::cout << "=========> operator called!" << std::endl;
    if (this != &other)
        this->type = other.type;
    return (other);
}
