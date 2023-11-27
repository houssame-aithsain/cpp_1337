/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 13:47:07 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/11/27 17:53:33 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class PresidentialPardonForm : public AForm{

    private:
        std::string target;
    public:
        ~PresidentialPardonForm( void );
        PresidentialPardonForm( void );
        PresidentialPardonForm( PresidentialPardonForm& other );
        PresidentialPardonForm( std::string target );
        PresidentialPardonForm& operator=( PresidentialPardonForm& other );
        void execute(Bureaucrat const & executor) const;
};
    std::ostream& operator<<(std::ostream& os, PresidentialPardonForm& other);
