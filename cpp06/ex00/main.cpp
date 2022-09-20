/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 09:12:46 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/09/20 09:12:50 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

#include <iostream>
#include <exception>
#include <iomanip>

int main(int argc, char **argv) {
	if (argc == 2) {
		try {
			Converter convertor(argv[1]);
			convertor.print();
		}
		catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}
	else
		std::cerr << "usage : ./convert [literal] (only one)" << std::endl;
}