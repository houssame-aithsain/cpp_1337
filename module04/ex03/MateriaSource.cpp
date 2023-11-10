/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:45:39 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/11/10 15:53:21 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

int MateriaSource::DupNodeCheck(t_list* toCheck) {

    t_list *tmp;

    tmp = this->head;
    while (tmp) {
        if (tmp->materia == toCheck->materia)
            return (false);
        tmp = tmp->link;
    }
    return (true);
}

t_list* MateriaSource::getLastNode() {

    t_list* tmp;

    tmp = this->head;
    while (tmp && tmp->link)
        tmp = tmp->link;
    return (tmp);
}

void MateriaSource::addMateria(AMateria* m) {

    t_list* lastNode;
    t_list* newNode;

    if (this->head) {
        lastNode = getLastNode();
        newNode = new t_list;
        newNode->link = NULL;
        newNode->materia = m;
        lastNode->link = newNode;
    }
    else {
        newNode = new t_list;
        newNode->materia = m;
        newNode->link = NULL;
        this->head = newNode;
    }
}

MateriaSource::~MateriaSource() {

    t_list* tmp;


    while (this->head) {
        tmp = this->head;
        this->head = head->link;
        if (this->DupNodeCheck(tmp)) {
            delete tmp->materia;
        }
        delete tmp;
    }
    std::cout << "MateriaSource Destructer has been called!" << std::endl;
}

MateriaSource::MateriaSource() {

    this->stock[0] = NULL;
    this->stock[1] = NULL;
    this->stock[2] = NULL;
    this->stock[3] = NULL;
    this->head = NULL;
}

void MateriaSource::learnMateria(AMateria* m) {

    if (!m) {
        std::cerr << "Using a NULL pointer is forbidden!" << std::endl;
       return ;
    }
    addMateria(m);
    for (int i = 0; i < 4; i++) {
        if (!this->stock[i])
        {
            this->stock[i] = m;
            return ;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const & type) {

    for (int i = 0; i < 4; i++) {
        if (this->stock[i] && this->stock[i]->getType() == type)
            return (this->stock[i]->clone());
    }
    return 0;
}
