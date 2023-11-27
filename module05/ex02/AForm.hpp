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
        AForm( std::string name, const int signGrade, const int executeGrade );
        AForm& operator=( AForm& other );
        std::string getName( void ) const;
        int getSignGrade( void );
        int getExecutGrade( void ) const;
        void beSigned( Bureaucrat& b);
        virtual void execute(Bureaucrat const & executor) const = 0;
        int getSign( void ) const;
        class GradeTooHighException : public std::exception {
            
            const char* what() const throw();
        };
        class GradeTooLowException : public std::exception {
            
            const char* what() const throw();
        };
};
    std::ostream& operator<<(std::ostream& os, AForm& other);
