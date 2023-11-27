/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:41:40 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/11/27 14:59:13 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {

    private:
        const std::string name;
        bool isSigned;
        const int signGrade;
        const int executeGrade;
    public:
        ~Form( void );
        Form( void );
        Form( Form& other );
        Form( const int signGrade, const int executeGrade, std::string name );
        Form& operator=( Form& other );
        std::string getName( void ) const;
        int getSignGrade( void );
        int getExecutGrade( void );
        int checkIfSigned( void );
        void beSigned( Bureaucrat& b);
        class GradeTooHighException : public std::exception {
            
            const char* what() const throw();
        };
        class GradeTooLowException : public std::exception {
            
            const char* what() const throw();
        };
};
    std::ostream& operator<<(std::ostream& os, Form& other);
