/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 10:05:43 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/11/27 13:46:52 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::~Intern( void ) {}

Intern::Intern( void ) {}

Intern::Intern( Intern & intern ) {

    (void)intern;
}

AForm* Intern::makeForm(std::string formName, std::string formTarget) {

    int i = 0;
    std::string fForm[3];
    AForm *Forms[3] = {
        new PresidentialPardonForm(formTarget),
        new RobotomyRequestForm(formTarget),
        new ShrubberyCreationForm(formTarget)
    };

    fForm[0] = "Presidential reque";
    fForm[1] = "Robotomy reque";
    fForm[2] = "Shrubbery reque";

    for (; i < 3 && formName != fForm[i]; i++);

    if (i < 3 && fForm[i] == formName)
        return (Forms[i]);
    std::cerr<< "error: form: type not faund!" << std::endl;
    return (NULL);
}
