/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:36:59 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/11/11 16:19:03 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Materia.hpp"
#include "ICharacter.hpp"

typedef struct llist {

    AMateria* materia;
    struct llist* link;
} s_list;

class Character : public ICharacter {

    private:
        AMateria* inventory[4];
        std::string name;
        s_list *head;
    public:
        ~Character( void );
        Character( void );
        Character( Character& other );
        Character( std::string str );
        Character& operator=(Character& other);
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
        std::string const & getName() const;
        void addMateria(AMateria* m); 
        s_list* getLastNode( void );
        int DupNodeCheck(s_list* tmp);
        typedef struct llist s_list;
};
