/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 13:47:07 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/11/27 15:02:49 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class PresidentialPardonForm : public AForm{

    private:
        const std::string name;
        bool isSigned;
        const int signGrade;
        const int executeGrade;
        std::string target;
    public:
        ~PresidentialPardonForm( void );
        PresidentialPardonForm( void );
        PresidentialPardonForm( PresidentialPardonForm& other );
        PresidentialPardonForm( std::string target );
        PresidentialPardonForm& operator=( PresidentialPardonForm& other );
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
    std::ostream& operator<<(std::ostream& os, PresidentialPardonForm& other);
