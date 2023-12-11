/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 12:45:47 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/12/11 18:03:19 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <exception>
#include <algorithm>
#include <vector>

template<typename T>
void easyfind(T vec, int n) {

    std::vector<int>::iterator it;
    it = std::find(vec.begin(), vec.end(), n);
    if (it == vec.end())
        throw("");
    std::cout << "value has been found: " << *it << std::endl;
}
