/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 13:46:35 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/11/27 17:51:32 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class RobotomyRequestForm : public AForm{

    private:
        std::string target;
    public:
        ~RobotomyRequestForm( void );
        RobotomyRequestForm( void );
        RobotomyRequestForm( RobotomyRequestForm& other );
        RobotomyRequestForm( std::string target );
        RobotomyRequestForm& operator=( RobotomyRequestForm& other );
        void execute(Bureaucrat const & executor) const;
};
    std::ostream& operator<<(std::ostream& os, RobotomyRequestForm& other);
