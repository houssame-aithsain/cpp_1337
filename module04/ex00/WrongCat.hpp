/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 14:53:46 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/11/05 14:58:53 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {

    public:
        ~WrongCat( void );
        WrongCat( void );
        WrongCat(WrongCat &other);
        WrongCat& operator=(WrongCat& other);
};
