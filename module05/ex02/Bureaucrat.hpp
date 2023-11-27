/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:10:03 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/11/27 15:02:41 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stdexcept>
#include "AForm.hpp"

class AForm;

class Bureaucrat {

    private:
        const std::string name;
        int grade;
    public:
        ~Bureaucrat(void);
        Bureaucrat(void);
        Bureaucrat(std::string name, int n);
        Bureaucrat(Bureaucrat& other);
        Bureaucrat& operator=(Bureaucrat& other);
        const std::string getName( void ) const;
        int getGrade( void ) const;
        void gradeIncremen( int n);
        void gradeDecremen( int n);
        void signForm( AForm& f );
        void executeForm(AForm const & form);
        class GradeTooHighException : public std::exception {
            
            const char* what() const throw();
        };
        class GradeTooLowException : public std::exception {
            
            const char* what() const throw();
        };
};
    std::ostream& operator<<(std::ostream& os, Bureaucrat& other);
