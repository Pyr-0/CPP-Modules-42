/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:11:03 by mrojas-e          #+#    #+#             */
/*   Updated: 2023/03/18 18:03:56 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP
//============COLORS!=======//
#define						RED "\e[31m"
#define						GREEN "\e[32m"
#define						BLUE "\e[36m"
#define						LILA "\e[35m"
#define						YLLW "\e[33m"
#define						RESET "\e[0m"

#include <stack>
#include <string>

class RPN
{
public:
    RPN(const std::string& expr);

    void process();
    std::stack<int> m_operands;

private:
    void process_digit(const std::string& token);
    void process_operator(const std::string& op);

    std::string m_expr;
};

#endif
