/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 21:29:54 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/12/22 20:29:47 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <iostream>
#include <stack>

template<typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
    public:
        typedef typename Container::iterator iterator;
        ~MutantStack() {}
        MutantStack() {}
        MutantStack(const MutantStack& other) : std::stack<T, Container>(other) {}
        MutantStack& operator=(const MutantStack& other) {
            std::stack<T, Container>::operator=(other);
            return *this;
        }
        iterator begin() { return std::stack<T, Container >::c.begin(); }
        iterator end() { return std::stack<T, Container >::c.end(); }
};
