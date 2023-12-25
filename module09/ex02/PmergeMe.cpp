/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 15:45:36 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/12/25 20:28:49 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// PmergeMe::~PmergeMe( void ) {

// }
// PmergeMe::PmergeMe( void ) {

// }
// PmergeMe::PmergeMe( const PmergeMe & other ) {

// }
// PmergeMe & PmergeMe::operator=(const PmergeMe & other) {

// }

void PmergeMe::printPaires( void ) {

    for (size_t i = 0; i < pairesSize; i++) {
        std::cout << "{";
        for (size_t j = 0; j < paires[i].size(); j++) {
            std::cout << "[" << paires[i][j] << "]";
        }
        std::cout << "}\n";
    }
}

void PmergeMe::inputParser(std::string str) {

    sNumbers += SPACE + str;
}

void    PmergeMe::inputCheckToConvert( void ) {

    std::string value;
    std::stringstream s(sNumbers);

    while (s >> value && value.size()) {
        for (size_t i = BEGIN; i < value.size(); i++) {
            if (!Ncheker(value[i]))
                throw BADiNput;
        }
        container.push_back(std::atoi(value.c_str()));
    }
        // print the container values to check
    // for (size_t i = 0; i < container.size(); i++)
    //     std::cout << "[" << container[i] << "]" << std::endl;
}

void PmergeMe::mergeSort( void ) {

    size_t x = 0;
    size_t i = 0;

    if (!(container.size() % 2))
        pairesSize = container.size();
    else
        pairesSize = container.size() - 1;
    // paires sorting...
    for (size_t count = 0; count < pairesSize; count++) {
        if (container[count] > container[count + 1])
            std::swap(container[count], container[count + 1]);
        if ((count + 1) != pairesSize)
            count++;
    }
    // print the container values to check
    // for (size_t i = 0; i < container.size(); i++) {
    //         std::cout << "[" << container[i] << "]" << std::endl;
    // }
    // std::cout << "---------------" << std::endl;
    // paires allocater
    paires =  new std::vector<int>[pairesSize / 2];
    // split paires
    for (; i < pairesSize; i++) {
        if (i < pairesSize) {
            paires[x].insert(paires[x].begin(), (container.begin() + i), container.begin() + i + 2);
            i++;
            x++;
        }
    }
    container.erase(container.begin(), container.begin() + pairesSize);
    std::cout << container.size() << std::endl;
    pairesSize = pairesSize / 2;
}

void PmergeMe::pairesSorting( void ) {
    
    for (size_t i = 0; i < pairesSize; i++) {
        for (size_t j = 0; j < pairesSize - i - 1; j++) {
            if (i + 1 < pairesSize && paires[j][1] > paires[j + 1][1])
                std::swap(paires[j], paires[j + 1]);
        }
    }
    printPaires();
}

void PmergeMe::splitMainPendElements( void ) {

    // get the main chain values
    for (size_t i = 0; i < pairesSize; i++)
        mainChain.push_back(paires[i].at(1));
    // get the pend values
    for (size_t i = 0; i < pairesSize; i++)
        pendElements.push_back(paires[i].at(0));
    if (container.size())
        pendElements.push_back(container.at(0));
    // print main && pending chains
    // for (size_t i = 0; i < mainChain.size(); i++)
    //     std::cout << "main chain ==> [" << mainChain[i] << "]" << std::endl;
    // std::cout << "*********\n";
    // for (size_t i = 0; i < pendElements.size(); i++)
    //     std::cout << "main chain ==> [" << pendElements[i] << "]" << std::endl;
}
