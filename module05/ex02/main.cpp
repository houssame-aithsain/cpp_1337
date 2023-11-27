/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:13:00 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/11/25 20:58:27 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main() {

    Bureaucrat b("eabase", 26);
    ShrubberyCreationForm sh("home");
    PresidentialPardonForm pr("cityStreet");
    RobotomyRequestForm ro("robotec");

    // Form a(40, 89, "form01");
    try {
        b.signForm(sh);
        b.signForm(pr);
        b.signForm(ro);
        b.executeForm(sh);
        b.executeForm(pr);
        b.executeForm(ro);
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    try {
        std::cout << "hello world " << std::endl;
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
