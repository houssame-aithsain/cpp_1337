/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:33:49 by hait-hsa          #+#    #+#             */
/*   Updated: 2024/01/01 20:29:15 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include <exception>
#include <limits>
#include <deque>

#define LIMITS 10

int main () {

    std::deque<int> de;

    de.erase(de.begin(), de.begin() + 10);
}