/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 11:52:17 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/11/12 14:28:57 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main2()
{
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    Animal *animal[4];

    animal[0] = new Dog();
    animal[1] = new Dog();
    animal[2] = new Cat();
    animal[3] = new Cat();
    for (int i = 0; i < 4; i++) { 
        delete animal[i];
    }
    delete j;
    delete i;
    return 0;
}
int main() {

    main2();
    // system("leaks animal");
}