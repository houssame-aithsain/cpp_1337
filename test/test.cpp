/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:33:49 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/12/04 17:10:08 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

template <typename T>
T functionName(T n1, T n2){

    if (n1 > n2)
        return (n1);
    return (n2);
}

int main(int argc, char *argv[]) {

    char grater;

    grater = functionName<char>(1, 2) + 48;
    std::cout << "grater numb===> " << grater << std::endl;
}