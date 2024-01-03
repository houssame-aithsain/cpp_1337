/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 15:45:39 by hait-hsa          #+#    #+#             */
/*   Updated: 2024/01/03 17:39:13 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <iomanip>

#define Ncheker(n) ((n >= '0' && n <= '9') ? true : false)
#define USAGE "USAGE: PmergeMe [random numbers]"
#define SPACE " "
#define BADiNput "Error: bad input !!"
#define BEGIN 0
#define NEXT 1
#define RANGE 2

#define MAX 1000

#define RED "\033[31m"    // Set the text to the color red
#define GREEN "\033[32m"  // Set the text to the color green

extern size_t cmpCount;

class PmergeMe {
    private:
        size_t count;
        // vector
        std::string sNumbers;
        std::vector<int> container;
        std::vector<int> copyContainer;
        std::vector<std::vector<int> > paires;
        std::vector<std::vector<int> > mainChain;
        std::vector<std::vector<int> > pendChain;
        std::vector<int> tmp;
        // deque
        std::deque<int> Dcontainer;
        std::deque<int> DcopyContainer;
        std::deque<std::deque<int> > Dpaires;
        std::deque<std::deque<int> > DmainChain;
        std::deque<std::deque<int> > DpendChain;
        std::deque<int> Dtmp;
    public:
        ~PmergeMe( void );
        PmergeMe( void );
        PmergeMe( const PmergeMe & other );
        PmergeMe & operator=(const PmergeMe & other);
        void    inputParser(std::string str);
        void    inputCheckToConvert( void );
        void    mergeInsertionSort( void );
        void    containerToMainPend( void );
        void    containerToPaires( void );
        void    insertPendToMain( void );
        static  bool    vecCmp(std::vector<int> a, std::vector<int> b);
        // deque
        void    DinputCheckToConvert( void );
        void    DmergeInsertionSort( void );
        void    DcontainerToMainPend( void );
        void    DcontainerToPaires( void );
        void    DinsertPendToMain( void );
        static  bool    deqCmp(std::deque<int> a, std::deque<int> b);
        //debugging functions
        void    print( clock_t start, clock_t end, clock_t Dstart, clock_t Dend );
        bool    check( void );
        bool    Dcheck( void );
};