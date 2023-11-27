/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:13:00 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/11/26 19:23:20 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int main() {

    Intern n;
    Bureaucrat b("eabase", 2);
    Form* sh = n.makeForm("Shrubbery reque", "home");
    Form* pr = n.makeForm("Presidential reque", "philo");
    Form* ro = n.makeForm("Robotomy reque", "moha");

    // Form a(40, 89, "form01");
    try {
        b.signForm(*sh);
        b.signForm(*pr);
        b.signForm(*ro);
        b.executeForm(*sh);
        b.executeForm(*pr);
        b.executeForm(*ro);
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
