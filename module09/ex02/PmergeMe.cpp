/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 15:45:36 by hait-hsa          #+#    #+#             */
/*   Updated: 2024/01/01 21:53:09 by hait-hsa         ###   ########.fr       */
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
        std::cout << RED << "<<<<oo0OOPS>>>>" << std::endl;
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
    if (container.size() > MAX)
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
    int ri[] = {3, 7, 15, 31, 63, 127, 255, 511, 1023, 2047, 4095, 8191, 16383, 32767};
    int ti[] = {2, 2, 6, 10, 22, 42, 86, 170, 342, 682, 1366, 2730, 5462, 10922, 21846, 43690, 87382, 174762, 349526, 699050, 1398102, 2796202};
    std::vector<int> rangeInsertion(ri, ri + (sizeof(ri) / sizeof(ri[BEGIN])));
    std::vector<int> totalInsertion(ti, ti + (sizeof(ti) / sizeof(ti[BEGIN])));

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
        std::vector<std::vector<int> >::iterator it = std::lower_bound(mainChain.begin(), mainChain.begin() + rangeToInsert, pendChain[position], vecCmp);
        mainChain.insert(it, pendChain[position]);
        counter += NEXT;
        position -= NEXT;
    }
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

// DEQUE

void    PmergeMe::DinputCheckToConvert( void ) {

    std::string value;
    std::stringstream s(sNumbers);
    std::deque<int> tmp;


    while (s >> value && value.size()) {
        for (size_t i = BEGIN; i < value.size(); i++) {
            if (!Ncheker(value[i]))
                throw BADiNput;
        }
        Dcontainer.push_back(std::atoi(value.c_str()));
    }
    if (Dcontainer.size() > MAX)
        throw "too much input";
    DcopyContainer = Dcontainer;
}

void    PmergeMe::DcontainerToPaires( void ) {
   
    while (Dcontainer.size()) {
        if (count > Dcontainer.size())
            break;
        Dtmp.insert(Dtmp.begin(), Dcontainer.begin(), Dcontainer.begin() + count);
        Dpaires.push_back(Dtmp);
        Dcontainer.erase(Dcontainer.begin(), Dcontainer.begin() + count);
        Dtmp.clear();
    }
}


void    PmergeMe::DcontainerToMainPend( void ) {

    count /= RANGE;
    while (Dcontainer.size() && count > NEXT) {
        Dtmp.clear();
        Dtmp.insert(Dtmp.begin(), Dcontainer.begin(), Dcontainer.begin() + (count / RANGE));
        DpendChain.push_back(Dtmp);
        Dcontainer.erase(Dcontainer.begin(), Dcontainer.begin() + (count / RANGE));
        Dtmp.clear();
        Dtmp.insert(Dtmp.begin(), Dcontainer.begin(), Dcontainer.begin() + (count / RANGE));
        if (Dtmp.size())
            DmainChain.push_back(Dtmp);
        Dtmp.clear();
        Dcontainer.erase(Dcontainer.begin(), Dcontainer.begin() + (count / RANGE));
    }
}

void    PmergeMe::DinsertPendToMain( void ) {

    int ri[] = {3, 7, 15, 31, 63, 127, 255, 511, 1023, 2047, 4095, 8191, 16383, 32767};
    int ti[] = {2, 2, 6, 10, 22, 42, 86, 170, 342, 682, 1366, 2730, 5462, 10922, 21846, 43690, 87382, 174762, 349526, 699050, 1398102, 2796202};
    std::deque<int> rangeInsertion(ri, ri + (sizeof(ri) / sizeof(ri[BEGIN])));
    std::deque<int> totalInsertion(ti, ti + (sizeof(ti) / sizeof(ti[BEGIN])));

    size_t counter = BEGIN;
    size_t rangeToInsert = rangeInsertion[BEGIN];
    size_t numberOfInsertion = totalInsertion[BEGIN];
    size_t position = numberOfInsertion - NEXT;
 
    while (DpendChain.size()) {
        if (counter >= numberOfInsertion) {
            if (numberOfInsertion < DpendChain.size())
                DpendChain.erase(DpendChain.begin(), DpendChain.begin() + numberOfInsertion);
            else
                DpendChain.clear();
            rangeInsertion.erase(rangeInsertion.begin());
            totalInsertion.erase(totalInsertion.begin());
            rangeToInsert = rangeInsertion[BEGIN];
            numberOfInsertion = totalInsertion[BEGIN];
            position = numberOfInsertion - NEXT;
            counter = BEGIN;
            continue;
        }
        if (rangeToInsert > DmainChain.size())
            rangeToInsert = DmainChain.size();
        if (position > DpendChain.size() - NEXT)
            position = DpendChain.size() - NEXT;
        if (numberOfInsertion > DpendChain.size())
            numberOfInsertion = DpendChain.size();
        std::deque<std::deque<int> >::iterator it = std::lower_bound(DmainChain.begin(), DmainChain.begin() + rangeToInsert, DpendChain[position], deqCmp);
        DmainChain.insert(it, DpendChain[position]);
        counter += NEXT;
        position -= NEXT;
    }
}

void PmergeMe::DmergeInsertionSort( void ) {

    std::deque<int> remainder;

    if (count > Dcontainer.size())
        return;
    DcontainerToPaires();
    if (!Dcontainer.empty()) {
        remainder.insert(remainder.begin(), Dcontainer.begin(), Dcontainer.end());
        Dcontainer.clear();
    }
    // swap
    for (size_t i = BEGIN; i < Dpaires.size(); i++) {
        if (i + NEXT < Dpaires.size() && deqCmp(Dpaires[i + NEXT], Dpaires[i]))
            std::swap(Dpaires[i], Dpaires[i + NEXT]);
        i += NEXT;
    }
    // copy to the main
    while (Dpaires.size()) {
        for (size_t i = BEGIN; i < Dpaires[BEGIN].size(); i++)
            Dcontainer.push_back(Dpaires[BEGIN][i]);
        Dpaires.erase(Dpaires.begin());
    }
    count *= RANGE;
    DmergeInsertionSort();
    // insert
    DcontainerToMainPend();
    // insert the remainder
    if (DpendChain.size()) {
        DmainChain.insert(DmainChain.begin(), DpendChain[BEGIN]);
        DpendChain.erase(DpendChain.begin());
    }
    if (remainder.size())
        DpendChain.push_back(remainder);
    DinsertPendToMain();
    while (DmainChain.size()) {
        for (size_t i = BEGIN; i < DmainChain[BEGIN].size(); i++)
            Dcontainer.push_back(DmainChain[BEGIN][i]);
        DmainChain.erase(DmainChain.begin());
    }
}

bool PmergeMe::deqCmp(std::deque<int> a, std::deque<int> b) {

    cmpCount++;
    return (a[a.size() - NEXT] < b[b.size() - NEXT]);
}

// END DEQUE

void PmergeMe::print( clock_t start, clock_t end, clock_t Dstart, clock_t Dend ) {

    // std::cout << "\n--------counter[" << cmpCount / 2 << "]---------\n";
    std::cout << "Before: ";
    for (size_t x = BEGIN; x < Dcontainer.size(); x++)
        std::cout << Dcontainer[x] << " ";
    std::cout << std::endl << "After: ";
    for (size_t x = BEGIN; x < DcopyContainer.size(); x++)
        std::cout << DcopyContainer[x] << " ";
    std::cout << std::endl << "Time to process a range of " << Dcontainer.size() << " elements with std::vector : " << (double)(end - start) / CLOCKS_PER_SEC * 1e6 << "us" << std::endl;
    std::cout << "Time to process a range of " << Dcontainer.size() << " elements with std::deque : " << (double)(Dend - Dstart) / CLOCKS_PER_SEC * 1e6 << "us" << std::endl;
}
