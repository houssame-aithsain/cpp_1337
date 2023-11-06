/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 11:49:43 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/11/06 18:09:48 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::~Cat( void ) {

    std::cout << "Cat Destructer called" << std::endl;
    delete this->brain;
}

Cat::Cat( void ) {

    std::cout << "Cat Constructer called" << std::endl;
    this->brain = new Brain();
    this->type = "Cat";
}

Cat::Cat( Cat& other ) {

    std::cout << "=========> Cat's Copy Constructer Called " << std::endl;
    *this = other;
}

Cat& Cat::operator=(Cat& other) {

    std::cout << "=========> operator called!" << std::endl;
    if (this != &other)
        this->type = other.type;
    return (other);
}
