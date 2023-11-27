/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:13:00 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/11/27 14:18:55 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {

    Bureaucrat b("eabase", 60);
    Form a(40, 89, "form01");
    try {
        b.signForm(a);
        std::cout << a << std::endl;
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    // std::cout << a << std::endl;
    // try {
    //     Bureaucrat mourad("mourad", 150);
    //     std::cout << mourad;
    //     b.gradeIncremen(10);
    //     b.gradeDecremen(20);
    // }
    // catch(std::exception & e) {
    //     std::cout << e.what() << std::endl;
    // }
}
