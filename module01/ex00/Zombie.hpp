/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 09:42:32 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/10/20 14:35:36 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie{
    private:
        std::string name;
    public:
        Zombie* newZombie( std::string name );
        void announce( void ){
            std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
        }
        ~Zombie( void ){
            std::cout << name << std::endl;
        }
        void SetZombieNmae(std::string Sname){
            name = Sname;
        }
        void randomChump( std::string name );
};

#endif /*ZOMBIE_HPP*/