/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 11:49:55 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/11/12 14:08:18 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {

    private:
        Brain* brain;
    public:
        ~Cat( void );
        Cat( void );
        Cat(Cat &other);
        Cat& operator=(Cat& other);
        void makeSound( void ) const;
};
