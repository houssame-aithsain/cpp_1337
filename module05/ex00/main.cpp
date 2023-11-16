/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:13:00 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/11/16 15:27:49 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {

    Bureaucrat b;

        std::cout << b;
    try {
        b.gradeIncremen(10);
        b.gradeDecremen(200);
    }
    catch(const char* errorType) {
       std::cout << "exception: " << errorType << std::endl;
    }
    catch(std::exception & e) {
        std::cout << e.what() << std::endl;
    }
}