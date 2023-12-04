/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialize.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 17:52:16 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/12/03 17:49:59 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialize.hpp"

Serialize::~Serialize( void ) {}

Serialize::Serialize( void ) {}

Serialize::Serialize( const Serialize & other ) {

    *this = other;
}

Serialize& Serialize::operator=(const Serialize & other) {
    
    (void)other;
    return(*this);
}

uintptr_t Serialize::serialize(Data* ptr) {

    return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serialize::deserialize(uintptr_t raw) {

    return (reinterpret_cast<Data*>(raw));
}
