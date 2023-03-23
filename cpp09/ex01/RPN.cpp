/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:11:00 by mrojas-e          #+#    #+#             */
/*   Updated: 2023/03/20 18:42:20 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>
#include <stack>
#include <sstream>
#include <cstdlib>

RPN::RPN(const std::string& expr) : m_expr(expr){}

void RPN::process()
{
    std::istringstream iss(m_expr);
    std::string token;

    while (iss >> token)
    {
        if (isdigit(token[0]))
            process_digit(token);
        else
            process_operator(token);
    }

    if (m_operands.size() == 1)
        std::cout<<GREEN << m_operands.top() <<RESET<< std::endl;
    else
    {
        std::cerr << "Error: Invalid expression" << std::endl;
        std::exit(EXIT_FAILURE);
    }
}

void RPN::process_operator(const std::string& op)
{
    if (m_operands.size() < 2)
    {
        std::cerr << "Error: Invalid expression" << std::endl;
        std::exit(EXIT_FAILURE);
    }

    int operand2 = m_operands.top();
    m_operands.pop();
    int operand1 = m_operands.top();
    m_operands.pop();

    int result = 0;
    if (op == "+")
        result = operand1 + operand2;
    else if (op == "-")
        result = operand1 - operand2;
    else if (op == "*")
        result = operand1 * operand2;
    else if (op == "/")
    {
        if (operand2 == 0)
        {
            std::cerr << "Error: Cant Divide by zero" << std::endl;
            std::exit(EXIT_FAILURE);
        }
        result = operand1 / operand2;
    }
    else
    {
        std::cerr << "Error: Invalid operator" << std::endl;
        std::exit(EXIT_FAILURE);
    }

    m_operands.push(result);
}

void RPN::process_digit(const std::string& token)
{
    int operand = std::atoi(token.c_str());
    m_operands.push(operand);
}
