/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:11:46 by mrojas-e          #+#    #+#             */
/*   Updated: 2023/03/18 18:04:04 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: RPN <expression>" << std::endl;
        return 1;
    }

    try {
        RPN rpn(argv[1]);
		rpn.process();
    } catch (const std::exception& e) {
        std::cerr << "\033[31m" << e.what() << "\033[0m" << std::endl;
        return 1;
    }

    return 0;
}
