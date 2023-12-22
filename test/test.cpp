/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:33:49 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/12/21 12:03:47 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include <exception>
#include <limits>


#define underLimit "2009-01-02"
#define uperLimit "2022-03-29"

int main() {
    // std::cout << (uperLimit < "2009-02-3571101423") << std::endl;
    float is = 206.68888;

    // std::cout.unsetf( std::ios_base::floatfield );
    std::cout.setf(std::ios::fixed, std:: ios::floatfield);
    std::cout << std::setprecision(2) << std::endl;
    std::cout << is << std::endl;
    // std::cout.setf(std::ios::fixed, std:: ios::floatfield);
    // std::cout << is << std::endl;
}