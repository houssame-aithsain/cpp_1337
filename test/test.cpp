/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:33:49 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/11/23 10:01:21 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>



int main() { 

    int *ptr;
   try {
        ptr[5] = 158;
   }
   catch(std::exception& e) {

        std::cout << e.what() << std::endl;
   }
}