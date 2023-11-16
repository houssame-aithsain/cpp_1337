/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:10:03 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/11/16 15:27:24 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stdexcept>

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
        const std::string getName( void );
        int getGrade( void );
        void gradeIncremen( int n);
        void gradeDecremen( int n);
        class GradeTooHighException : public std::exception {
        const char* what() const _NOEXCEPT {
                return ("Grade Too High!");
            }
        };
        class GradeTooLowException  : public std::exception {

            const char* what() const _NOEXCEPT {
                return ("Grade Too Low!");
            }
        };
};
    std::ostream& operator<<(std::ostream& os, Bureaucrat& other);
