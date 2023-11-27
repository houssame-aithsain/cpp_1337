/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:13:00 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/11/27 19:20:41 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main() {

    // Bureaucrat b("eabase", 26);
    // ShrubberyCreationForm sh("Shrubbery");
    // PresidentialPardonForm pr("Presidential");
    // RobotomyRequestForm ro("Robotomy");

    // try {
    //     b.signForm(sh);
    //     b.signForm(pr);
    //     b.signForm(ro);
    //     b.executeForm(sh);
    //     b.executeForm(pr);
    //     b.executeForm(ro);
    // }
    // catch (std::exception& e) {
    //     std::cout << e.what() << std::endl;
    // }

    Bureaucrat b("eabase", 26);
    ShrubberyCreationForm sh("Shrubbery");
    ShrubberyCreationForm sb("Shrubbery1");

    b.signForm(sh);
    sb = sh;

    std::cout << sh << std::endl;
    std::cout << sb << std::endl;
}
