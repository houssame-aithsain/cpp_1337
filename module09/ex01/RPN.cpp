/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 13:25:29 by hait-hsa          #+#    #+#             */
/*   Updated: 2024/01/03 16:30:42 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::~RPN( void ) {}

RPN::RPN( void ) {}

RPN::RPN( const RPN & other ) {

    *this = other;
}

RPN & RPN::operator=(const RPN & other) {

    if (this != &other) {
        Operator = other.Operator;
        Stack = other.Stack;
    }
    return (*this);
}

int RPN::calculation(int first, int second) {

    int i = 0;
    std::string opARR[] = OP;

    if (Operator[0] == '/' && !second)
        throw BADiNPUT;
    for (; i < 4; i++)
        if (Operator == opARR[i])
            break;
    switch (i) {
        case 0:
            return (first + second);
        case 1:
            return (first - second);
        case 2:
            return (first / second);
        case 3:
            return (first * second);
        default:
            throw OPFAILED;
    }
}

void RPN::inputParser(std::string argv) {

    int result;
    std::string value;
    std::stringstream s(argv);

    if (s.fail())
        throw BADiNPUT;
    while (s >> value) {
        if (value.size() == 1 && Stack.size() > 1 && is_operator(value[0])) {
            if (Stack.size() < 2)
                throw BADiNPUT;
            Operator = value;
            result = Stack.top();
            Stack.pop();
            result = calculation(Stack.top(), result);
            Stack.pop();
            Stack.push(result);
        } else if ((value.size() == 1 && is_number(value[0])) || (value.size() == 2 && value[0] == '+' && is_number(value[1])))
            Stack.push(std::atoi(value.c_str()));
        else
            throw BADiNPUT;
    }
    if (Stack.size() == 1)
        std::cout << Stack.top() << std::endl;
    else
        throw BADiNPUT;
}
