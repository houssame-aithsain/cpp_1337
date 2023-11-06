/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 15:18:07 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/11/06 13:05:09 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class Brain {

    private:
        std::string ideas[100];
    public:
        ~Brain( void );
        Brain( void );
        Brain( Brain& other );
        Brain& operator=(Brain& other);
};