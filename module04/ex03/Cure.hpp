/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 20:43:25 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/11/12 12:59:57 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"

class Cure : public AMateria {

    public:
        ~Cure ( void );
        Cure ( void );
        Cure ( Cure& other );
        Cure& operator=(Cure& other);
        Cure* clone(void) const;
        void use(ICharacter& target);
};
