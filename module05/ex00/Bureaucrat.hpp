/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:10:03 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/11/14 15:54:16 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Bureaucrat {

    private:
        const std::string name;
        int grade;
    public:
        ~Bureaucrat(void);
        Bureaucrat(void);
        Bureaucrat(Bureaucrat& other);
        Bureaucrat& operator=(Bureaucrat& other);
        const std::string getName( void );
        int getGrade( void );
        void gradeIncremen( int n);
        void gradeDecremen( int n);
        void GradeTooHighException( void );
        void GradeTooLowExcepti( void );
};