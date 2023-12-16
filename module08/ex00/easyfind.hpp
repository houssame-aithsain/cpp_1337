/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 12:45:47 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/12/15 15:18:13 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

template <typename T>
void easyFind(T& vec, int n) {
    typename T::iterator it = std::find(vec.begin(), vec.end(), n);
    if (it != vec.end()) {
        std::cout << "Value has been found: " << *it << std::endl;
        return ;
    }
    throw "Value not found";
}
