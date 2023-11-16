/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:19:31 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/11/16 15:28:09 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::~Bureaucrat(void) {}

Bureaucrat::Bureaucrat(void) : name("Jilali"), grade(150) {}

Bureaucrat::Bureaucrat(std::string name, int n) : name(name), grade(n) {

    if (n < 1)
        throw Bureaucrat::GradeTooHighException();
    if (n > 150)
        throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(Bureaucrat& other) {

    *this = other;
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat& other) {

    if (this != &other)
        this->grade = other.grade;
    return (*this);
}

std::ostream& operator<<(std::ostream& os, Bureaucrat& other) {

    os << other.getName() << ", bureaucrat grade " << other.getGrade() << std::endl;
    return (os);
}

void Bureaucrat::gradeIncremen( int n ) {

    grade +=  n;
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

void Bureaucrat::gradeDecremen( int n ) {

    grade -=  n;
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
}

const std::string Bureaucrat::getName( void ) {

    return (name);
}

int Bureaucrat::getGrade( void ) {

    return (grade);
}
