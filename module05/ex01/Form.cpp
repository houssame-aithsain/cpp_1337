/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:41:42 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/11/27 15:00:27 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::~Form( void ) {}

Form::Form( void ) : name("form01"), isSigned(false), signGrade(15), executeGrade(70) {}

Form::Form( const int signGrade, const int executeGrade, std::string name ) : name(name), signGrade(signGrade), executeGrade(executeGrade) {

    if (this->signGrade < 1)
        throw Form::GradeTooHighException();
    if (this->signGrade > 150)
        throw Form::GradeTooLowException();
}

Form::Form( Form& other ) : name(other.name), signGrade(other.signGrade), executeGrade(other.executeGrade) {

    *this = other;
}

Form& Form::operator=( Form& other ) {

    if (this != &other)
        this->isSigned = other.isSigned;
    return (*this);
}

const char* Form::GradeTooHighException::what() const throw() {
    
    return ("Grade Too High!");
}

const char* Form::GradeTooLowException::what() const throw() {
    
    return ("Grade Too Low!");
}

std::string Form::getName( void ) const {

    return (name);
}

int Form::checkIfSigned( void ) {

    return (this->isSigned);
}

int Form::getSignGrade( void ) {

    return(signGrade);
}

int Form::getExecutGrade( void ) {

    return (executeGrade);
}

void Form::beSigned( Bureaucrat& b ) {

    if (b.getGrade() <= this->signGrade)
        this->isSigned = true;
    else
        throw Form::GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, Form& other) {

    os << "Form Name: " << other.getName() << ", Form sign Grade: " << other.getSignGrade() << ", Form Execut Grade: " << other.getExecutGrade() << ", Form status: ";
    if (other.checkIfSigned())
        os << "signed!";
    else
        os << "not signed!";
    return (os);
}
