/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 19:19:11 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/11/11 17:27:17 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "ICharacter.hpp"


class AMateria
{
    protected:
        std::string type;
    public:
        virtual ~AMateria (void);
        AMateria (void);
        AMateria (AMateria& other);
        AMateria(std::string const & type);
        AMateria& operator=(AMateria& other);
        std::string const & getType() const; //Returns the materia type
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);
};
