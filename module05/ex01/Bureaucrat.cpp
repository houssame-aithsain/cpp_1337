/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:19:31 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/11/27 17:37:54 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::~Bureaucrat(void) {}

Bureaucrat::Bureaucrat(void) : name("Jilali"), grade(50) {}

Bureaucrat::Bureaucrat(std::string name, int n) : name(name), grade(n) {

    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(Bureaucrat& other) {

    *this = other;
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat& other) {

    if (this != &other) {
        this->grade = other.grade;
        (std::string)this->name = other.name;
    }
    return (*this);
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    
    return ("Grade Too High!");
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    
    return ("Grade Too Low!");
}

std::ostream& operator<<(std::ostream& os, Bureaucrat& other) {

    os << other.getName() << ", bureaucrat grade " << other.getGrade();
    return (os);
}

void Bureaucrat::gradeIncremen( void ) {

    grade--;
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::gradeDecremen( void ) {

    grade++;
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

const std::string Bureaucrat::getName( void ) const {

    return (name);
}

int Bureaucrat::getGrade( void ) {

    return (grade);
}

void Bureaucrat::signForm( Form& f ) {

    try {
        f.beSigned(*this);
        std::cout << this->name << " signed " << f.getName() << std::endl;
    }
    catch (std::exception& e) {
        std::cout << this->name << " couldn’t sign " << f.getName() << " because " << e.what() << std::endl;
    }
}
