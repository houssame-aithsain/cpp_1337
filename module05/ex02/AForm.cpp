/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:41:42 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/11/24 19:41:27 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::~AForm( void ) {}

AForm::AForm( void ) : name("Aform01"), isSigned(false), signGrade(15), executeGrade(70) {}

AForm::AForm( std::string name, const int signGrade, const int executeGrade) : name(name), isSigned(false), signGrade(signGrade), executeGrade(executeGrade) {

    if (this->signGrade < 1)
        throw AForm::GradeTooHighException();
    if (this->signGrade > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm( AForm& other ) : name(other.name), signGrade(other.signGrade), executeGrade(other.executeGrade) {

    *this = other;
}

AForm& AForm::operator=( AForm& other ) {

    if (this != &other)
        this->isSigned = other.isSigned;
    return (*this);
}

const char* AForm::GradeTooHighException::what() const throw() {
    
    return ("Grade Too High!");
}

const char* AForm::GradeTooLowException::what() const throw() {
    
    return ("Grade Too Low!");
}

std::string AForm::getName( void ) const {

    return (name);
}

int AForm::getSignGrade( void ) {

    return(signGrade);
}

int AForm::getExecutGrade( void ) const {

    return (executeGrade);
}

int AForm::getSign( void ) const {

    return (this->isSigned);
}

void AForm::beSigned( Bureaucrat& b ) {

    if (b.getGrade() <= this->signGrade)
        this->isSigned = true;
    else
        throw AForm::GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, AForm& other) {

    os << "AForm Name: " << other.getName() << ", AForm sign Grade: " << other.getSignGrade() << ", AForm Execut Grade: " << other.getExecutGrade();
    return (os);
}
