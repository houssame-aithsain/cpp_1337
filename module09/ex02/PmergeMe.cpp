/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 15:45:36 by hait-hsa          #+#    #+#             */
/*   Updated: 2024/01/01 20:26:31 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

bool PmergeMe::check( void ) {

    for (size_t i = BEGIN; i < container.size(); i++) {
        if (i + NEXT < container.size() && container[i] > container[i + NEXT])
            return(false);
    }
    for (size_t i = BEGIN; i < container.size();) {
        for (size_t j = BEGIN; j < copyContainer.size(); j++) {
            if (container[i] == copyContainer[j]) {
                copyContainer.erase(copyContainer.begin() + j);
                container.erase(container.begin() + i);
                i = BEGIN;
                break;
            }
            else {
                i++;
                break;
            }
        }
    }
    if (container.empty() && copyContainer.empty())
        return(true);
    return(false);
}

size_t cmpCount = BEGIN;

PmergeMe::~PmergeMe( void ) {

    if (check())
        std::cout << GREEN << "<<<<<ALL GOOD>>>>" << std::endl;
    else
        std::cout << RED << "<<<<ooOOPS>>>>" << std::endl;
}

PmergeMe::PmergeMe( void ) : count(NEXT) {

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
    if (container.size() > 10000)
        throw "too much input";
    copyContainer = container;
}

void    PmergeMe::containerToPaires( void ) {
   
    while (container.size()) {
        if (count > container.size())
            break;
        tmp.insert(tmp.begin(), container.begin(), container.begin() + count);
        paires.push_back(tmp);
        container.erase(container.begin(), container.begin() + count);
        tmp.clear();
    }
}


void    PmergeMe::containerToMainPend( void ) {

    count /= RANGE;
    while (container.size() && count > NEXT) {
        tmp.clear();
        tmp.insert(tmp.begin(), container.begin(), container.begin() + (count / RANGE));
        pendChain.push_back(tmp);
        container.erase(container.begin(), container.begin() + (count / RANGE));
        tmp.clear();
        tmp.insert(tmp.begin(), container.begin(), container.begin() + (count / RANGE));
        if (tmp.size())
            mainChain.push_back(tmp);
        tmp.clear();
        container.erase(container.begin(), container.begin() + (count / RANGE));
    }
}

void    PmergeMe::insertPendToMain( void ) {

    // range
    std::vector<int> rangeInsertion;
    rangeInsertion.push_back(3);
    rangeInsertion.push_back(7);
    rangeInsertion.push_back(15);
    rangeInsertion.push_back(31);
    rangeInsertion.push_back(63);
    rangeInsertion.push_back(127);
    rangeInsertion.push_back(255);
    rangeInsertion.push_back(511);
    rangeInsertion.push_back(1023);
    rangeInsertion.push_back(2047);
    rangeInsertion.push_back(4095);
    rangeInsertion.push_back(8191);
    rangeInsertion.push_back(16383);
    rangeInsertion.push_back(32767);
    // totalInsertion
    std::vector<int> totalInsertion;
    totalInsertion.push_back(2);
    totalInsertion.push_back(2);
    totalInsertion.push_back(6);
    totalInsertion.push_back(10);
    totalInsertion.push_back(22);
    totalInsertion.push_back(42);
    totalInsertion.push_back(86);
    totalInsertion.push_back(170);
    totalInsertion.push_back(342);
    totalInsertion.push_back(682);
    totalInsertion.push_back(1366);
    totalInsertion.push_back(2730);
    totalInsertion.push_back(5462);
    totalInsertion.push_back(10922);
    totalInsertion.push_back(21846);
    totalInsertion.push_back(43690);
    totalInsertion.push_back(87382);
    totalInsertion.push_back(174762);

    size_t counter = BEGIN;
    size_t rangeToInsert = rangeInsertion[BEGIN];
    size_t numberOfInsertion = totalInsertion[BEGIN];
    size_t position = numberOfInsertion - NEXT;
 
    while (pendChain.size()) {
        if (counter >= numberOfInsertion) {
            if (numberOfInsertion < pendChain.size())
                pendChain.erase(pendChain.begin(), pendChain.begin() + numberOfInsertion);
            else
                pendChain.clear();
            rangeInsertion.erase(rangeInsertion.begin());
            totalInsertion.erase(totalInsertion.begin());
            rangeToInsert = rangeInsertion[BEGIN];
            numberOfInsertion = totalInsertion[BEGIN];
            position = numberOfInsertion - NEXT;
            counter = BEGIN;
            continue;
        }
        if (rangeToInsert > mainChain.size())
            rangeToInsert = mainChain.size();
        if (position > pendChain.size() - NEXT)
            position = pendChain.size() - NEXT;
        if (numberOfInsertion > pendChain.size())
            numberOfInsertion = pendChain.size();
        // std::cout << "number of insertion =====> " << numberOfInsertion << std::endl;
        // std::cout << "position ===> " << position << std::endl;
        // std::cout << "------------------" << std::endl;
        std::vector<std::vector<int> >::iterator it = std::lower_bound(mainChain.begin(), mainChain.begin() + rangeToInsert, pendChain[position], vecCmp);
        mainChain.insert(it, pendChain[position]);
        counter += NEXT;
        position -= NEXT;
    }
    // std::cout << "*******************out of while*******************\n";
}

void PmergeMe::mergeInsertionSort( void ) {

    std::vector<int> remainder;

    if (count > container.size())
        return;
    containerToPaires();
    if (!container.empty()) {
        remainder.insert(remainder.begin(), container.begin(), container.end());
        container.clear();
    }
    // swap
    for (size_t i = BEGIN; i < paires.size(); i++) {
        if (i + NEXT < paires.size() && vecCmp(paires[i + NEXT], paires[i]))
            std::swap(paires[i], paires[i + NEXT]);
        i += NEXT;
    }
    // copy to the main
    while (paires.size()) {
        for (size_t i = BEGIN; i < paires[BEGIN].size(); i++)
            container.push_back(paires[BEGIN][i]);
        paires.erase(paires.begin());
    }
    count *= RANGE;
    mergeInsertionSort();
    // insert
    containerToMainPend();
    // insert the remainder
    if (pendChain.size()) {
        mainChain.insert(mainChain.begin(), pendChain[BEGIN]);
        pendChain.erase(pendChain.begin());
    }
    if (remainder.size())
        pendChain.push_back(remainder);
    insertPendToMain();
    while (mainChain.size()) {
        for (size_t i = BEGIN; i < mainChain[BEGIN].size(); i++)
            container.push_back(mainChain[BEGIN][i]);
        mainChain.erase(mainChain.begin());
    }
}

bool PmergeMe::vecCmp(std::vector<int> a, std::vector<int> b) {

    cmpCount++;
    return (a[a.size() - NEXT] < b[b.size() - NEXT]);
}

void PmergeMe::print( clock_t start, clock_t end ) {

    std::cout << "\n--------counter[" << cmpCount << "]---------\n";
    std::cout << "Before: ";
    for (size_t x = BEGIN; x < container.size(); x++)
        std::cout << container[x] << " ";
    std::cout << std::endl << "After: ";
    for (size_t x = BEGIN; x < copyContainer.size(); x++)
        std::cout << copyContainer[x] << " ";
    std::cout << std::endl << "Time to process a range of " << container.size() << " elements with std::vector : " << (double)(end - start) / CLOCKS_PER_SEC * 1e6 << "us" << std::endl;
}
