/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 15:45:39 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/12/25 20:07:24 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>

#define Ncheker(n) ((n >= '0' && n <= '9') ? true : false)
#define USAGE "USAGE: PmergeMe [random numbers]"
#define SPACE " "
#define BADiNput "Error: bad input !!"
#define BEGIN 0

class PmergeMe {
    private:
        /*attributes*/
        std::string sNumbers;
        std::vector<int> container;
        std::vector<int> *paires;
        std::vector<int> mainChain;
        std::vector<int> pendElements;
        size_t pairesSize;
    public:
        // ~PmergeMe( void );
        // PmergeMe( void );
        // PmergeMe( const PmergeMe & other );
        // PmergeMe & operator=(const PmergeMe & other);
        void    inputParser(std::string str);
        void    inputCheckToConvert( void );
        void    mergeSort( void );
        void    pairesSorting( void );
        void    splitMainPendElements( void );
            //debugging function
        void    printPaires( void );
};