/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 13:45:39 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/11/27 17:54:12 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class ShrubberyCreationForm : public AForm {

    private:
        std::string target;
    public:
        ~ShrubberyCreationForm( void );
        ShrubberyCreationForm( void );
        ShrubberyCreationForm( ShrubberyCreationForm& other );
        ShrubberyCreationForm( std::string target );
        ShrubberyCreationForm& operator=( ShrubberyCreationForm& other );
        void execute(Bureaucrat const & executor) const;
        void treeMaker( void ) const;
};
    std::ostream& operator<<(std::ostream& os, ShrubberyCreationForm& other);
