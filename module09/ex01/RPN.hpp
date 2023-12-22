/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 13:25:31 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/12/22 13:28:11 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <stack>

#define is_operator(op) ((op == '+' || op == '-' || op == '/' || op == '*') ? true : false)
#define is_number(num) ((num >= '0' && num <= '9') ? true : false)
#define C_FAILED -963

#define INVALIDE "Error: invalide operation"
#define BADiNPUT "Error: bad input"
#define OPFAILED "Error: operation failed"

class RPN
{
    private:
        std::stack<std::string> Stack;
        std::stack<std::string> container;
        std::string Operator;
        std::string firstNumb;
        std::string secondNumb;
    public:
        ~RPN( void );
        RPN( void );
        RPN( const RPN & other );
        RPN & operator=(const RPN & other);
        void inputParser(std::string agv);
        bool operationChecker( void );
        int calculation(int first, int second);
};
