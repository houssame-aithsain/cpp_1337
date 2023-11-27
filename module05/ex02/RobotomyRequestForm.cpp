/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 13:46:38 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/11/27 15:06:48 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::~RobotomyRequestForm( void ) {}

RobotomyRequestForm::RobotomyRequestForm( void ) : name("robotomy reque"), isSigned(false), signGrade(72), executeGrade(45) {}

RobotomyRequestForm::RobotomyRequestForm( std::string target ) : name("Robotomy"), isSigned(false), signGrade(25), executeGrade(5), target(target) {}

RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm& other ) : name(other.name), signGrade(other.signGrade), executeGrade(other.executeGrade) {

    *this = other;
}

RobotomyRequestForm& RobotomyRequestForm::operator=( RobotomyRequestForm& other ) {

    if (this != &other)
        this->isSigned = other.isSigned;
    return (*this);
}

const char* RobotomyRequestForm::GradeTooHighException::what() const throw() {
    
    return ("Grade Too High!");
}

const char* RobotomyRequestForm::GradeTooLowException::what() const throw() {
    
    return ("Grade Too Low!");
}

std::string RobotomyRequestForm::getName( void ) const {

    return (name);
}

int RobotomyRequestForm::getSignGrade( void ) {

    return(signGrade);
}

int RobotomyRequestForm::getExecutGrade( void ) {

    return (executeGrade);
}

void RobotomyRequestForm::beSigned( Bureaucrat& b ) {

    if (b.getGrade() <= this->signGrade)
        this->isSigned = true;
    else
        throw RobotomyRequestForm::GradeTooLowException();
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
    
    if (this->isSigned && (executor.getGrade() <= this->executeGrade)) {
        srand(time(NULL));
        if (rand() % 2) {
            std::cout << "RRRRR... RRRRR... RRRRR..." << std::endl;
            std::cout << target << " has been robotomized successfully 50% of the time" << std::endl;
        }
        else
            std::cout << "robotomy failed " << std::endl;
    }
    else {
        std::cout << executor.getName() << " didn't make it to execute form " << this->name << std::endl;
        throw RobotomyRequestForm::GradeTooLowException();
    }
}

std::ostream& operator<<(std::ostream& os, RobotomyRequestForm& other) {

    os << "RobotomyRequestForm Name: " << other.getName() << ", RobotomyRequestForm sign Grade: " << other.getSignGrade() << ", RobotomyRequestForm Execut Grade: " << other.getExecutGrade();
    return (os);
}
