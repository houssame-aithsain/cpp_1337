/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 12:45:50 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/12/15 15:15:53 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main( void ) {

    try {
        int n = 2;

        srand(time(NULL));
        std::deque<int> vec;
        for (int i = 0; i < 20; i++)
            vec.push_back(rand() % 40);
        easyFind<std::deque<int> >(vec, n);
    }
    catch(...) {
        std::cout << "value not found!!" << std::endl;
    }
}
