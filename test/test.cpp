/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:33:49 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/11/30 14:08:03 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[]) {

    char *endPtr;

    float output = std::strtod(argv[1], &endPtr);
    std::cout << output << std::endl;
}