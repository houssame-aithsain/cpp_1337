/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 10:07:58 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/12/08 21:10:16 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Array.hpp"

template<typename T>
Array<T>::~Array( void ) {

    delete[] this->rr;
}

template<typename T>
Array<T>::Array( void ) : n(0) {

    this->rr = new T[n];
}

template<typename T>
Array<T>::Array( unsigned int size ) : rr(new T[size]), n(size) {}

template<typename T>
Array<T>::Array(const Array<T> & other ) {

    std::cout << "test" << std::endl;
    n = other.n;
    rr = new T[n];
    for (unsigned int i = 0; i < n; i++)
        rr[i] = other.rr[i];
}

template<typename T>
Array<T>& Array<T>::operator=(const Array<T>& other) {
    if (this != &other) {
        delete[] this->rr;
        this->rr = new T[other.n];
        for(unsigned int i = 0; i < other.n; i++)
            this->rr[i] = other.rr[i];
        n = other.n;
    }
    return *this;
}

template<typename T>
T& Array<T>::operator[](unsigned int index) const {

    if ((index < 0) || (index >= this->size()))
        throw std::out_of_range("error: index out of range!");
    return (rr[index]);
}

template<typename T>
unsigned int Array<T>::size( void ) const{

    return (n);
}
