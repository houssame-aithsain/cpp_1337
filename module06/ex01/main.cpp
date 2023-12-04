/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:16:15 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/12/03 17:42:58 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialize.hpp"

int main() {

    Data before;
    Data *after;

    before.i = 106981;
    std::cout << &before << std::endl; 
    after = Serialize::deserialize(Serialize::serialize(&before));
    std::cout << after << std::endl; 
    if (&before == after)
        std::cout << "the same address!" << std::endl;
}
