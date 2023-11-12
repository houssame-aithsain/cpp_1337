/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 11:52:17 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/11/12 12:25:38 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main()
{
    Dog *d = new Dog();
    Cat *c = new Cat();

    Dog *d1 = new Dog();
    Cat *c1 = new Cat();

    const Animal* j = new Dog();
    const Animal* i = new Cat();
    Animal *animal[4];

    animal[0] = d;
    animal[1] = d1;
    animal[2] = c;
    animal[3] = c1;
    for (int i = 0; i < 4; i++) { 
        delete animal[i];
    }
    delete j; // should not create a leak
    delete i;
    return 0;
}
