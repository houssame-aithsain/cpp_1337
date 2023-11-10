/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 20:43:31 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/11/09 22:48:53 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "AMateria.hpp"

class Ice : public AMateria {

    public:
        ~Ice ( void );
        Ice ( void );
        Ice ( Ice& other );
        Ice& operator=(Ice& other);
        Ice* clone(void) const;
        void use(ICharacter& target);
};
