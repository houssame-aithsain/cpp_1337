/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 13:46:38 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/11/27 17:53:39 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::~RobotomyRequestForm( void ) {}

RobotomyRequestForm::RobotomyRequestForm( void ) : AForm("robotomy reque", 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm( std::string target ) : AForm("robotomy reque", 72, 45), target(target) {}

RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm& other ) {

    *this = other;
}

RobotomyRequestForm& RobotomyRequestForm::operator=( RobotomyRequestForm& other ) {

    if (this != &other)
        AForm::operator=(other);
    return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
    
    if (this->getSign() && (executor.getGrade() <= this->getExecutGrade())) {
        srand(time(NULL));
        if (rand() % 2) {
            std::cout << "RRRRR... RRRRR... RRRRR..." << std::endl;
            std::cout << target << " has been robotomized successfully 50% of the time" << std::endl;
        }
        else
            std::cout << "robotomy failed" << std::endl;
    }
    else
        throw RobotomyRequestForm::GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, RobotomyRequestForm& other) {

    os << "Form Name: " << other.getName() << ", Form sign Grade: " << other.getSignGrade() << ", Form Execut Grade: " << other.getExecutGrade();
    return (os);
}
