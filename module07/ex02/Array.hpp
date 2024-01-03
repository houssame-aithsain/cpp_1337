/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 10:08:33 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/12/08 17:54:08 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template<typename T>
class Array {
    private:
        T *rr;
        unsigned int n;
    public:
        ~Array( void );
        Array( void );
        Array( unsigned int n );
        Array(const Array<T> & other );
        Array<T>& operator=(const Array<T>& other);
        T& operator[](unsigned int index) const;
        unsigned int size( void ) const;
};

#include "Array.tpp"