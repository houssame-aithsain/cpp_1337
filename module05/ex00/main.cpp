/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:13:00 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/11/27 15:39:00 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {

    Bureaucrat b;

    try {
        Bureaucrat mourad("jilali", 2);
        mourad.gradeIncremen();
        std::cout << mourad;
        b.gradeDecremen();
    }
    catch(std::exception & e) {
        std::cout << e.what() << std::endl;
    }
}
