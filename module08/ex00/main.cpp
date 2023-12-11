/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 12:45:50 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/12/11 18:03:37 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main( void ) {

    try {
        srand(time(NULL));
        std::vector<int> vec;
        for (int i = 0; i < 20; i++)
            vec.push_back(rand() % 40);
        int n = 2;
        easyfind(vec, n);
    }
    catch(...) {
        std::cout << "value not found!!" << std::endl;
    }
}
