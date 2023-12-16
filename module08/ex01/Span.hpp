/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 18:10:04 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/12/14 18:01:02 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <exception>
#include <vector>
#include <limits>

class Span {

    private:
        std::vector<unsigned int> nArr;
        unsigned int max;
        unsigned int N;
    public:
        ~Span( void );
        Span( void );
        Span(const Span & other);
        Span(unsigned int n);
        Span& operator=(const Span & other);
        void addNumber(unsigned int n);
        unsigned int getNumb(unsigned int);
        int shortestSpan( void );
        int longestSpan( void );
        void addRange(std::vector<unsigned int>::iterator begin, std::vector<unsigned int>::iterator end);
        void printVec(std::vector<unsigned int> vec);
};
