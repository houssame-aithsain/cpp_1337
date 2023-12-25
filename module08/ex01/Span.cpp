/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 18:10:01 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/12/25 16:50:35 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::~Span( void ) {}

Span::Span( void ) : max(0) , N(0) {}

Span::Span(const Span & other) {

    *this = other;
}

Span::Span(unsigned int n): max(0), N(n) {}

Span& Span::operator=(const Span & other) {

    if (this != &other) {
        this->N = other.N;
        this->max = other.max;
        nArr.clear();
        for (unsigned int i = 0; i < N; i++)
            this->nArr.push_back(other.nArr.at(i));
    }
    return (*this);
}

unsigned int Span::getNumb(unsigned int n) {

    if (n < 0 || n >= N)
        throw "error: index out of range";
    return nArr.at(n);
}

void Span::addNumber(unsigned int n) {

    if (max >= N)
        throw "error: Array is full!!";
    nArr.push_back(n);
    max++;
}

int Span::shortestSpan( void ) {

    std::vector<unsigned int> tmp = nArr;
    
    if (N < 2)
        throw "span error! don't play games please";
    unsigned int result = std::numeric_limits<unsigned int>::max();
    std::sort(tmp.begin(), tmp.end());
    for (std::vector<unsigned int>::iterator i = tmp.begin(); i != tmp.end(); i++) {
        if (i + 1 != tmp.end() && *(i + 1) - (*i) < result)
            result = *(i + 1) - (*i);
    }
    return static_cast<int>(result);
}

int Span::longestSpan( void ) {

    if (N < 2)
        throw "span error! don't play games please";
    return static_cast<int>(*(std::max_element(nArr.begin(), nArr.end())) - *(std::min_element(nArr.begin(), nArr.end())));
}

void Span::addRange(const std::vector<unsigned int>::iterator begin, const std::vector<unsigned int>::iterator end) {

    unsigned int i = 0;

    for (std::vector<unsigned int>::iterator tmp = begin; tmp != end; tmp++)
        i++;
    if (i > (N - max))
        throw "error: vector: out of range";
    nArr.insert(nArr.begin(), begin, end);
    max += i;
}

void Span::printVec(std::vector<unsigned int> vec) {

    // std::cout << "copy vector values: " << std::endl;
    // for (std::vector<unsigned int>::iterator it = vec.begin(); it != vec.end(); it++)
    //     std::cout << *it << std::endl;
    std::cout << "original vector values: " << std::endl;
    for (std::vector<unsigned int>::iterator it = nArr.begin(); it != nArr.end(); it++)
        std::cout << *it << std::endl;
}