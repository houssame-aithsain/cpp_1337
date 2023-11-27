/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:13:00 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/11/27 19:25:51 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {

    Bureaucrat b("houssame", 10);
    Form a(1, 60, "eabase");

    try {
        b.signForm(a);
        std::cout << a << std::endl;
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << a << std::endl;
    try {
        Bureaucrat mourad("mourad", 150);
        std::cout << mourad;
        b.gradeIncremen();
        b.gradeDecremen();
    }
    catch(std::exception & e) {
        std::cout << e.what() << std::endl;
    }
}
