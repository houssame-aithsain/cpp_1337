/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 14:56:06 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/11/12 11:46:32 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "WrongCat.hpp"

WrongCat::~WrongCat( void ) {

    std::cout << "WrongCat Destructer has been called!" << std::endl;
}

WrongCat::WrongCat( void ) {

    std::cout << "WrongCat Constructer has been called!" << std::endl;
    this->type = "WrongCat";
}

WrongCat::WrongCat( WrongCat& other ) {

    std::cout << "WrongCat Copy Constructer has been called!" << std::endl;
    *this = other;
}

WrongCat& WrongCat::operator=(WrongCat& other) {

    std::cout << "WrongCat Operator has been called!" << std::endl;
    if (this != &other)
        this->type = other.type;
    return (other);
}
