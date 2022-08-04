/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 22:34:03 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/08/04 19:21:58 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iomanip>

Contact::Contact(){}
Contact::~Contact(){}

void	resize_string(std::string string)
{
	if(string.size() >= 10)
		std::cout<<std::setw(8)<<string.substr(0,9)<< "." << "|";
	else
		std::cout<<std::setw(10)<<string<< "|";
}

void Contact::print_contact()
{
	std::cout<<GREEN<<"Firstname: "<<RESET<<get_first()<<std::endl;
	std::cout<<GREEN<<"Last name: "<<RESET<<get_last()<<std::endl;
	std::cout<<GREEN<<"Nick Name: "<<RESET<<get_nick()<<std::endl;
	std::cout<<GREEN<<"Phone Number: "<<RESET<<get_phone()<<std::endl;
	std::cout<<GREEN<<"Darkest Secret: "<<RESET<<get_dark()<<std::endl;
}
