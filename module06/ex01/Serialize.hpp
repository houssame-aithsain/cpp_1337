/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialize.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 17:52:13 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/12/03 17:49:04 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

typedef struct t_Data {
    int i;
} Data;

class Serialize {

    private:
        ~Serialize( void );
        Serialize( void );
        Serialize( const Serialize & other );
        Serialize& operator=(const Serialize & other);
    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};
