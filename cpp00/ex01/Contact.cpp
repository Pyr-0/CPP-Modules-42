/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 22:34:03 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/07/21 15:28:57 by mrojas-e         ###   ########.fr       */
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

void	display_data()
{
		std::cout<<"\e[36m"<<std::setw(40)<<std::setfill('-')<<"\n"
				 <<"\e[36m"<<std::setw(11)<< "index|"<< std::setw(11)<<"First name|"
				 <<"\e[36m"<<std::setw(11)<<"Last Name|"<< std::setw(11)<<"Nickname|"<<std::endl
				 <<"\e[36m"<<"********************************************"<<std::endl;
}

void	print_menu()
{
		std::cout<<"\e[36m"<<std::setw(28)<<std::setfill('-')<<"\n"
				 <<"\e[38m"<<std::setw(26)<<std::setfill(' ')<<"RETRO PHONEBOOK MENU!\n"
				 <<"\e[38m"<<std::setw(26)<<"   Please write a command\n"<<std::setfill(' ')
				 <<"\e[36m"<<std::setw(28)<<std::setfill('-')<<"\n"<<std::setfill(' ')
				 <<"\e[36m"<<std::setw(17)<<"[  ADD ]\n"<<std::setfill(' ')
				 <<"\e[36m"<<std::setw(17)<<"[SEARCH]\n"<<std::setfill(' ')
				 <<"\e[36m"<<std::setw(17)<<"[ EXIT ]\n"<<std::setfill(' ');
}

/* void    PhoneBook::display_phonebook(void) const{
    int i;
    i = 0;

    std::cout << std::setw(10) << "index|";
    std::cout << std::setw(10) << "first name|";
    std::cout << std::setw(11) << "last name|";
    std::cout << std::setw(11) << "nickname|" << std::endl;
    while (i < 8)
    {
        std::cout << std::setw(9) << i + 1 << "|";
        if (con_entry[i].get_firstName().size() >= 10)
            std::cout << std::setw(8) <<con_entry[i].get_firstName().substr(0,9) << "." << "|";
        else
        std::cout << std::setw(10) << con_entry[i].get_firstName() << "|";
        if (con_entry[i].get_lastname().size() >= 10)
            std::cout << std::setw(8) <<con_entry[i].get_lastname().substr(0,9) << "." << "|";
        else
        std::cout << std::setw(10) << con_entry[i].get_lastname() << "|";
        if (con_entry[i].get_nickname().size() >= 10)
            std::cout << std::setw(8) <<con_entry[i].get_nickname().substr(0,9) << "." << "|" <<std::endl;
        else
        std::cout << std::setw(10) << con_entry[i].get_nickname() << "|" << std::endl;
        i++;
    }
    std::cout << std::endl;
} */