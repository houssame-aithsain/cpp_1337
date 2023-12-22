/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 13:25:29 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/12/22 16:30:25 by hait-hsa         ###   ########.fr       */
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
        firstNumb = other.firstNumb;
        secondNumb = other.secondNumb;
        Operator = other.Operator;
        Stack = other.Stack;
        container = other.container;
    }
    return (*this);
}

int RPN::calculation(int first, int second) {

    int i = 0;
    std::string opARR[] = OP;

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

bool RPN::operationChecker( void ) {

    char *ptr;

    if (!is_operator(Operator[0]) || Operator.empty())
        return false;
        // check for first number
    if (firstNumb[0] == '+' || firstNumb[0] == '-') {
        if (!is_number(firstNumb[1]) || firstNumb.empty())
            return false;
    } else
        if (!is_number(firstNumb[0]) || firstNumb.empty())
            return false;
        // check for second number
    if (secondNumb[0] == '+' || secondNumb[0] == '-') {
        if (!is_number(secondNumb[1]) || secondNumb.empty())
            return false;
    } else
        if (!is_number(secondNumb[0]) || secondNumb.empty())
            return false;
    std::strtod(firstNumb.c_str(), &ptr);
    if (std::strcmp(ptr, ""))
        return false;
    std::strtod(secondNumb.c_str(), &ptr);
    if (std::strcmp(ptr, ""))
        return false;
    return true;
}

void RPN::inputParser(std::string argv) {

    std::string value;

    std::stringstream s(argv);
    while (s >> value)
        Stack.push(value);
    if (Stack.size() < 3)
        throw BADiNPUT;
    while (container.size() || Stack.size() >= 3) {
        if (Stack.size() == 3) {
            Operator = Stack.top();
            Stack.pop();
            firstNumb = Stack.top();
            Stack.pop();
            secondNumb = Stack.top();
            Stack.pop();
            if (!operationChecker())
                throw INVALIDE;
            Stack.push(std::to_string(calculation(std::atoi(secondNumb.c_str()), std::atoi(firstNumb.c_str()))));
        } while (Stack.size() > 3) {
            container.push(Stack.top());
            Stack.pop();
        } while (container.size() && Stack.size() < 3) {
            Stack.push(container.top());
            container.pop();
        }
    }
    if (Stack.size() != 1)
        throw BADiNPUT;
    std::cout << Stack.top() << std::endl;
}
