/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:13:00 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/11/27 19:10:20 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

void main1() {

    Intern n;
    Bureaucrat b("eabase", 2);
    Form* sh = n.makeForm("Shrubbery reque", "home");
    Form* pr = n.makeForm("Presidential reque", "philo");
    Form* ro = n.makeForm("Robotomy reque", "moha");

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
    delete sh;
    delete pr;
    delete ro;
}

int main() {

    main1();
    // system("leaks bureaucrat");
}
