/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 11:49:43 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/11/12 11:46:20 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::~Cat( void ) {

    std::cout << "Cat Destructer has been called!" << std::endl;
}

Cat::Cat( void ) {

    std::cout << "Cat constructer has been called!" << std::endl;
    this->type = "Cat";
}

Cat::Cat( Cat& other ) {

    std::cout << "Cat Copy Constructer has been called!" << std::endl;
    *this = other;
}

Cat& Cat::operator=(Cat& other) {

    std::cout << "Cat Operator has been called!" << std::endl;
    if (this != &other)
        this->type = other.type;
    return (other);
}
