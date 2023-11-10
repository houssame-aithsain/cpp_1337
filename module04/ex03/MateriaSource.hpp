/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:45:36 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/11/10 15:45:15 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"
#include <iostream>


typedef struct list {

    AMateria* materia;
    struct list* link;
} t_list;

class MateriaSource : public IMateriaSource {

    private:
        AMateria* stock[4];
        t_list *head;
    public:
        ~MateriaSource();
        MateriaSource();
        void learnMateria(AMateria*);
        AMateria* createMateria(std::string const & type);
        void addMateria(AMateria* m); 
        t_list* getLastNode( void );
        int DupNodeCheck(t_list* tmp);
        typedef struct list t_list;
};
