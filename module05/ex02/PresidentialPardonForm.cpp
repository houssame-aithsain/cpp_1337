/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 13:47:01 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/11/27 15:06:28 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::~PresidentialPardonForm( void ) {}

PresidentialPardonForm::PresidentialPardonForm( void ) : name("Presidential reque"), isSigned(false), signGrade(25), executeGrade(5) {}

PresidentialPardonForm::PresidentialPardonForm( std::string target ) : name("President"), isSigned(false), signGrade(25), executeGrade(5), target(target) {}

PresidentialPardonForm::PresidentialPardonForm( PresidentialPardonForm& other ) : name(other.name), signGrade(other.signGrade), executeGrade(other.executeGrade) {

    *this = other;
}

PresidentialPardonForm& PresidentialPardonForm::operator=( PresidentialPardonForm& other ) {

    if (this != &other)
        this->isSigned = other.isSigned;
    return (*this);
}

const char* PresidentialPardonForm::GradeTooHighException::what() const throw() {
    
    return ("Grade Too High!");
}

const char* PresidentialPardonForm::GradeTooLowException::what() const throw() {
    
    return ("Grade Too Low!");
}

std::string PresidentialPardonForm::getName( void ) const {

    return (name);
}

int PresidentialPardonForm::getSignGrade( void ) {

    return(signGrade);
}

int PresidentialPardonForm::getExecutGrade( void ) {

    return (executeGrade);
}

void PresidentialPardonForm::beSigned( Bureaucrat& b ) {

    if (b.getGrade() <= this->signGrade)
        this->isSigned = true;
    else
        throw PresidentialPardonForm::GradeTooLowException();
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
    
    if (this->isSigned && (executor.getGrade() <= this->executeGrade))
        std::cout << target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
    else {
        std::cout << executor.getName() << " didn't make it to execute form " << this->name << std::endl;
        throw PresidentialPardonForm::GradeTooLowException();
    }
}

std::ostream& operator<<(std::ostream& os, PresidentialPardonForm& other) {

    os << "PresidentialPardonForm Name: " << other.getName() << ", PresidentialPardonForm sign Grade: " << other.getSignGrade() << ", PresidentialPardonForm Execut Grade: " << other.getExecutGrade();
    return (os);
}
