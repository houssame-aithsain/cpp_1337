/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:57:51 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/12/08 18:34:09 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template <typename T>
void swap(T& Fvalue, T& Svalue) {

    std::swap(Fvalue, Svalue);
}

template <typename T>
T min(T Fvalue, T Svalue) {
    
    if (Fvalue < Svalue)
        return (Fvalue);
    return (Svalue);
}

template <typename T>
T max(T Fvalue, T Svalue) {
    
    if (Fvalue > Svalue)
        return (Fvalue);
    return (Svalue);
}
