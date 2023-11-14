/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:19:31 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/11/14 16:06:54 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::~Bureaucrat(void) {}

Bureaucrat::Bureaucrat(void) {}

Bureaucrat::Bureaucrat(Bureaucrat& other) {

    *this = other;
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat& other) {

    if (this != &other)
        this->grade = other.grade;
    return (*this);
}

void Bureaucrate::GradeTooHighException( void ) {

    throw("Grade Too High Exception");
}
void Bureaucrate::GradeTooLowException( void ) {

    throw("Grade Too Low Exception");
}

void Bureaucrat::gradeIncremen( int n ) {

    grade -=  n;       
}

void Bureaucrat::gradeDecremen( int n ) {

    grade +=  n;       
}

const std::string Bureaucrat::getName( void ) {

    return (name);
}

int Bureaucrat::getGrade( void ) {

    return (grade);
}
