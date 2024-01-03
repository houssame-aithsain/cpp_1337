/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 10:05:43 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/11/27 19:21:30 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::~Intern( void ) {}

Intern::Intern( void ) {}

Intern::Intern( Intern & intern ) {

    *this = intern;
}

Intern& Intern::operator=(Intern& other) {

    (void)other;
    return (*this);
}

AForm* Intern::getPresidential( std::string formTarget ) {

    return (new PresidentialPardonForm(formTarget));
}

AForm* Intern::getRobotomy( std::string formTarget ) {

    return (new RobotomyRequestForm(formTarget));
}

AForm* Intern::getShrubbery( std::string formTarget ) {

    return (new ShrubberyCreationForm(formTarget));
}

AForm* Intern::makeForm(std::string formName, std::string formTarget) {

    int i = 0;
    std::string fForm[3];
    Intern::pointerToFunction Forms[3];

    Forms[0] = &Intern::getPresidential;
    Forms[1] = &Intern::getRobotomy;
    Forms[2] = &Intern::getShrubbery;

    fForm[0] = "Presidential reque";
    fForm[1] = "Robotomy reque";
    fForm[2] = "Shrubbery reque";

    for (; i < 3 && formName != fForm[i]; i++);

    if (i < 3 && fForm[i] == formName)
        return (this->*Forms[i])(formTarget);
    std::cerr<< "error: form: type not faund!" << std::endl;
    return (NULL);
}
