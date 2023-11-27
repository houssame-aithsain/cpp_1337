/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:41:40 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/11/24 19:55:29 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <fstream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {

    private:
        const std::string name;
        bool isSigned;
        const int signGrade;
        const int executeGrade;
    public:
        virtual ~AForm( void );
        AForm( void );
        AForm( AForm& other );
        AForm( const int signGrade, const int executeGrade, std::string name );
        AForm& operator=( AForm& other );
        virtual std::string getName( void ) const = 0;
        virtual int getSignGrade( void ) = 0;
        virtual int getExecutGrade( void ) = 0;
        virtual void beSigned( Bureaucrat& b) = 0;
        virtual void execute(Bureaucrat const & executor) const = 0;
        class GradeTooHighException : public std::exception {
            
            const char* what() const throw();
        };
        class GradeTooLowException : public std::exception {
            
            const char* what() const throw();
        };
};
    std::ostream& operator<<(std::ostream& os, AForm& other);
