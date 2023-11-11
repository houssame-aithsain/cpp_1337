/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Materia.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:55:50 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/11/10 18:26:52 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AMateria.hpp"

class Materia : public AMateria {

    public:
        virtual ~Materia (void) {}
        Materia (void);
        Materia (Materia& other);
        Materia(std::string const & type);
        Materia& operator=(Materia& other);
        std::string const & getType() const; //Returns the materia type
        Materia* clone() const;
        virtual void use(ICharacter& target);
};
