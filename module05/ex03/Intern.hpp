/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 10:05:36 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/11/27 17:25:20 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"

class Intern {
    public:
        ~Intern( void );
        Intern( void );
        Intern( Intern & intern );
        AForm* makeForm(std::string formName, std::string formTarget);
        AForm* getPresidential( std::string formTarget );
        AForm* getRobotomy( std::string formTarget );
        AForm* getShrubbery( std::string formTarget );
        typedef AForm* (Intern::*pointerToFunction)( std::string formName);
};
    typedef AForm Form;
