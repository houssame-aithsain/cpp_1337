/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 09:42:32 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/10/25 13:17:11 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie {
    private:
        std::string name;
    public:
        Zombie( void );
        ~Zombie( void );
        Zombie( std::string name );
        void announce( void );
};

void randomChump( std::string name );
Zombie* newZombie( std::string name );

#endif /*ZOMBIE_HPP*/