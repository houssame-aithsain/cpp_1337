/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 13:47:01 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/11/27 19:22:07 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::~PresidentialPardonForm( void ) {}

PresidentialPardonForm::PresidentialPardonForm( void ) : AForm("Presidential reque", 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm( std::string target ) : AForm("Presidential reque", 25, 5), target(target) {}

PresidentialPardonForm::PresidentialPardonForm( PresidentialPardonForm& other ) {

    *this = other;
}

PresidentialPardonForm& PresidentialPardonForm::operator=( PresidentialPardonForm& other ) {

    if (this != &other)
        AForm::operator=(other);
    return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
    
    if (this->getSign() && (executor.getGrade() <= this->getExecutGrade()))
        std::cout << target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
    else
        throw PresidentialPardonForm::GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, PresidentialPardonForm& other) {

    os << "Form Name: " << other.getName() << ", Form sign Grade: " << other.getSignGrade() << ", Form Execut Grade: " << other.getExecutGrade() << ", Form status: ";
    if (other.getSign())
        os << "signed!";
    else
        os << "not signed!";
    return (os);
}
