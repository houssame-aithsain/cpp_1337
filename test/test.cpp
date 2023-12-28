/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:33:49 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/12/28 11:15:12 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include <exception>
#include <limits>
#include <vector>

#define LIMITS 10

bool toCmp(int first, int second) {

    return (first > second);
}

int main() {

    std::vector<int> vec;

    srand(time(NULL));
    int num = 10;

    for (size_t i = 0; i < LIMITS; i++)
        vec.push_back(rand() % 20);

    std::vector<int>::iterator it = std::lower_bound(vec.begin(), vec.end(), num);

    std::cout << "it===> " << *it << std::endl;

    for (size_t i = 0; i < LIMITS; i++)
        std::cout << vec.at(i) << std::endl;
}