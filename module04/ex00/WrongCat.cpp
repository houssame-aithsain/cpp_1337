/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 14:56:06 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/11/05 14:59:15 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "WrongCat.hpp"

WrongCat::~WrongCat( void ) {}

WrongCat::WrongCat( void ) {

    this->type = "WrongCat";
}

WrongCat::WrongCat( WrongCat& other ) {

    *this = other;
}

WrongCat& WrongCat::operator=(WrongCat& other) {

    if (this != &other)
        this->type = other.type;
    return (other);
}
