/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:37:05 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/11/10 16:05:30 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

int Character::DupNodeCheck(s_list* toCheck) {

    s_list *tmp;

    tmp = this->head;
    while (tmp) {
        if (tmp->materia == toCheck->materia)
            return (false);
        tmp = tmp->link;
    }
    return (true);
}

s_list* Character::getLastNode() {

    s_list* tmp;

    tmp = this->head;
    while (tmp && tmp->link)
        tmp = tmp->link;
    return (tmp);
}

void Character::addMateria(AMateria* m) {

    s_list* lastNode;
    s_list* newNode;

    if (this->head) {
        lastNode = getLastNode();
        newNode = new s_list;
        newNode->link = NULL;
        newNode->materia = m;
        lastNode->link = newNode;
    }
    else {
        newNode = new s_list;
        newNode->materia = m;
        newNode->link = NULL;
        this->head = newNode;
    }
}

Character::~Character( void ) {

    s_list* tmp;


    while (this->head) {
        tmp = this->head;
        this->head = head->link;
        if (this->DupNodeCheck(tmp)) {
            delete tmp->materia;
        }
        delete tmp;
    }
    std::cout << "Character Destructer has been called!" << std::endl;
}

Character::Character( void ) {

    this->inventory[0] = NULL;
    this->inventory[1] = NULL;
    this->inventory[2] = NULL;
    this->inventory[3] = NULL;
    this->head = NULL;
}

Character::Character( std::string str ) {

    this->name = str;
    this->inventory[0] = NULL;
    this->inventory[1] = NULL;
    this->inventory[2] = NULL;
    this->inventory[3] = NULL;
    this->head = NULL;
}

Character::Character( Character& other ) {

    *this = other;
}

Character& Character::operator=(Character& other) {

    if (this != &other) {
        this->name = other.name;
        for (int i = 0; i < 4; i++)
            this->inventory[i] = other.inventory[i];
    }
    return (*this);
}

void Character::equip(AMateria* m) {

    if (!m) {
        std::cerr << "Using a NULL pointer is forbidden!" << std::endl;
        return ;
    }
    addMateria(m);
    for (int i = 0; i < 4; i++) {
        if (!this->inventory[i]) {
            this->inventory[i] = m;
            return ;
        }
    }
}

void Character::unequip(int idx) {

    if (idx < 4 && idx >= 0)
        this->inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target) {

    if (idx < 4 && idx >= 0 && this->inventory[idx])
        this->inventory[idx]->use(target);
    else 
        std::cout << "NULL pointer!, DO NOT attack civilians; they are not armed." << std::endl;
}

std::string const & Character::getName() const {

    return(this->name);
}