/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 13:46:35 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/11/27 15:08:30 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class RobotomyRequestForm : public AForm{

    private:
        const std::string name;
        bool isSigned;
        const int signGrade;
        const int executeGrade;
        std::string target;
    public:
        ~RobotomyRequestForm( void );
        RobotomyRequestForm( void );
        RobotomyRequestForm( RobotomyRequestForm& other );
        RobotomyRequestForm( std::string target );
        RobotomyRequestForm& operator=( RobotomyRequestForm& other );
        std::string getName( void ) const;
        int getSignGrade( void );
        int getExecutGrade( void );
        void beSigned( Bureaucrat& b);
        void execute(Bureaucrat const & executor) const;
        class GradeTooHighException : public std::exception {
            
            const char* what() const throw();
        };
        class GradeTooLowException : public std::exception {
            
            const char* what() const throw();
        };
};
    std::ostream& operator<<(std::ostream& os, RobotomyRequestForm& other);
