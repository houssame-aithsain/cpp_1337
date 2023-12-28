/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 15:45:39 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/12/28 11:04:20 by hait-hsa         ###   ########.fr       */
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
#define NEXT 1
#define RANGE 2

class PmergeMe {
    private:
        /*attributes*/
        std::string sNumbers;
        std::vector<int> container;
        std::vector<std::vector<int> > paires;
        std::vector<std::vector<int> > mainChain;
        std::vector<std::vector<int> > pendChain;
        std::vector<int> sorted;
        size_t pairesSize;
        size_t count;
    public:
        // ~PmergeMe( void );
        PmergeMe( void );
        // PmergeMe( const PmergeMe & other );
        // PmergeMe & operator=(const PmergeMe & other);
        void    inputParser(std::string str);
        void    inputCheckToConvert( void );
        static  bool    vecCmp(std::vector<int> a, std::vector<int> b);
        void    mergeSort( void );
            //debugging function
        void    insertSort( void );
};