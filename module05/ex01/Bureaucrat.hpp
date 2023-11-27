/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:10:03 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/11/27 15:00:13 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stdexcept>
#include "Form.hpp"

class Form;

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
        int getGrade( void );
        void gradeIncremen( void );
        void gradeDecremen( void );
        void signForm( Form& f );
        class GradeTooHighException : public std::exception {
            
            const char* what() const throw();
        };
        class GradeTooLowException : public std::exception {
            
            const char* what() const throw();
        };
};
    std::ostream& operator<<(std::ostream& os, Bureaucrat& other);
