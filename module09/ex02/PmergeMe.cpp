/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 15:45:36 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/12/28 11:13:46 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// PmergeMe::~PmergeMe( void ) {

// }
PmergeMe::PmergeMe( void ) : count(RANGE) {

}
// PmergeMe::PmergeMe( const PmergeMe & other ) {

// }
// PmergeMe & PmergeMe::operator=(const PmergeMe & other) {

// }

void PmergeMe::inputParser(std::string str) {

    sNumbers += SPACE + str;
}

void    PmergeMe::inputCheckToConvert( void ) {

    std::string value;
    std::stringstream s(sNumbers);
    std::vector<int> tmp;


    while (s >> value && value.size()) {
        for (size_t i = BEGIN; i < value.size(); i++) {
            if (!Ncheker(value[i]))
                throw BADiNput;
        }
        container.push_back(std::atoi(value.c_str()));
    }
    if (container.size() % 2)
        pairesSize = container.size() - NEXT; // you stile need one comdition here for odds.
    else
        pairesSize = container.size();
    for (size_t count = BEGIN; count < pairesSize; count++) {
        if (container[count] > container[count + NEXT])
            std::swap(container[count], container[count + NEXT]);
        if ((count + NEXT) != pairesSize)
            count++;
    }
    for (size_t max = BEGIN; max < pairesSize; max++) {
        tmp.insert(tmp.begin(), (container.begin() + max), container.begin() + max + RANGE);
        paires.push_back(tmp);
        tmp.clear();
        max += NEXT;
    }
    if (container.size() != pairesSize)
        container.erase(container.begin(), container.begin() + (pairesSize));
}

void PmergeMe::mergeSort( void ) {

    if (paires.size() < 2 || (paires[BEGIN].size() != paires[NEXT].size())) {
        count = RANGE;
        if (container.size() == NEXT)
            paires.push_back(container);
            // just to print result
        for (size_t i = BEGIN; i < paires.size(); i++) {
            std::cout << "{";
            for (size_t x = BEGIN; x < paires[i].size(); x++)
                std::cout << "[" << paires[i][x] << "]";
            std::cout << "}\n";
        }
            // end
        std::cout << "------------------------------\n";
        return ;
    }

    //swap
    for (size_t i = BEGIN; i < paires.size(); i++) {
        if (i + NEXT < paires.size() && (paires[i].size() == paires[i + NEXT].size()) && paires[i][count - NEXT] > paires[i + NEXT][count - NEXT])
            std::swap(paires[i], paires[i + NEXT]);
        i += NEXT;
    }
    //insert
    for (size_t i = BEGIN; i < paires.size(); i++) {
        if (i + NEXT < paires.size() && (paires[i].size() == paires[i + NEXT].size())) {
            paires[i].insert(paires[i].end(), paires[i + NEXT].begin(), paires[i + NEXT].end());
            paires.erase(paires.begin() + (i + NEXT));
        }
    }
    //print
    count *= RANGE;
    mergeSort();
}

bool PmergeMe::vecCmp(std::vector<int> a, std::vector<int> b) {

    std::cout << "================================\n";
    std::cout << "a = > " << a[a.size()] << std::endl;
    std::cout << "b = > " << b[b.size()] << std::endl;
    return (a[a.size() - NEXT] > b[b.size() - NEXT]);
}


void PmergeMe::insertSort( void ) {

    std::vector<int> tmp;
    bool swetcher = true;
    size_t counter;

    // mian puch
    for (size_t i = BEGIN; i < paires.size();) {
        if (mainChain.size() && mainChain[BEGIN].size() == paires[i].size()) {
            pendChain.push_back(paires[i]);
            paires.erase(paires.begin() + i);
            continue;
        }
        if ((i && mainChain.size() && mainChain[BEGIN].size() == paires[i].size()) || swetcher) {
            for (counter = BEGIN; counter < (paires[i].size() / 2); counter++)
                tmp.push_back(paires[i][counter]);
            std::vector<std::vector<int> >::iterator it =  std::lower_bound(mainChain.begin(), mainChain.end(), tmp, vecCmp);
            if (it != mainChain.end()) {
                std::vector<std::vector<int> >::difference_type position = std::distance(mainChain.begin(), it);
                std::cout << position << std::endl;
            }
            exit(0);
            // mainChain.insert(it - mainChain.begin(), mainChain.begin(), mainChain.begin());
            paires[i].erase(paires[i].begin(), paires[i].begin() + counter);
            if (paires.size())
                mainChain.push_back(paires[i]);
            if (paires[i].size())
                paires.erase(paires.begin() + i);
            tmp.clear();
            swetcher = false;
            continue;
        }
        i++;
    }
    
    std::cout << "----------MAIN--------\n";
    for (size_t i = BEGIN; i < mainChain.size(); i++) {
        std::cout << "{";
        for (size_t x = BEGIN; x < mainChain[i].size(); x++)
            std::cout << "[" << mainChain[i][x] << "]";
        std::cout << "}\n";
    }
    std::cout << "----------PEND--------\n";
    for (size_t i = BEGIN; i < pendChain.size(); i++) {
        std::cout << "{";
        for (size_t x = BEGIN; x < pendChain[i].size(); x++)
            std::cout << "[" << pendChain[i][x] << "]";
        std::cout << "}\n";
    }
}
