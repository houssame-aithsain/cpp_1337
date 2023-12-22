/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 13:25:29 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/12/22 13:46:33 by hait-hsa         ###   ########.fr       */
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

int RPN::calculation(int fisrt, int second) {

    if (!Operator.compare("+"))
        return (fisrt + second);
    if (!Operator.compare("-"))
        return (fisrt - second);
    if (!Operator.compare("/"))
        return (fisrt / second);
    if (!Operator.compare("*"))
        return (fisrt * second);
    throw OPFAILED;
    return C_FAILED;
}

bool RPN::operationChecker( void ) {

    char *ptr;

    if (!is_operator(Operator[0]) || Operator.empty())
        return false;
    if (!is_number(firstNumb[0]) || firstNumb.empty())
        return false;
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
