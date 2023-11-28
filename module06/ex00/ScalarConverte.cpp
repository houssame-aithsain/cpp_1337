/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverte.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 13:12:46 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/11/26 14:24:04 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverte.hpp"

ScalarConverte::~ScalarConverte( void ) {}

ScalarConverte::ScalarConverte( void ) {}

void ScalarConverte::convert(std::string value) {

    int intValue = stoi();
    std::cout << value.c_str() << std::endl;
    std::cout << value.stoi() << std::endl;
    // std::cout << value.c_str << std::endl;
}
