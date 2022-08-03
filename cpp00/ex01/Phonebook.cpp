/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 23:07:35 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/08/03 15:35:07 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iomanip>

PhoneBook::PhoneBook(){index = 0; isFull = false;}
PhoneBook::~PhoneBook(){}

void PhoneBook::add()
{
	contact[index].set_first(log_data("Enter First Name"));
	contact[index].set_last(log_data("Enter Last Name"));
	contact[index].set_nick(log_data("Enter Nickame"));
	contact[index].set_phone(log_data("Enter Phone Number"));
	contact[index].set_dark(log_data("Enter Dark Secret"));
	if (index == 7)
		isFull = true;
	index = (index + 1) % 8;
	
}

std::string	log_data(std::string message)
{
		std::string reader;
		std::cout<<"\e[36m"<<message<<"\e[0m"<<std::endl;
		std::getline(std::cin, reader);
		while(reader.empty())
		{
			std::cout<<"\e[31mPlease Enter a valid input!\e[0m"<<std::endl;
			std::getline(std::cin, reader);
		}
	return (reader);
}

void	PhoneBook::display_all()
{
	int limit;
	
	limit = this->isFull ? 8 : index;
	for(int i = 0; i < limit; i++)
	{
		std::cout<<std::setw(10)<<i<< "|";
		resize_string(this->contact[i].get_first());
		resize_string(this->contact[i].get_last());
		resize_string(this->contact[i].get_nick());
		std::cout<<std::endl;
	}
}
void	display_data(PhoneBook &pb)
{
	std::cout<<"\e[36m"<<std::setw(50)<<std::setfill('_')<<"\n"<<std::setfill(' ')
			<<"\e[36m"<<std::setw(11)<< "index|"<< std::setw(11)<<"First name|"<<std::setfill(' ')
			<<"\e[36m"<<std::setw(11)<<"Last Name|"<< std::setw(11)<<"Nickname|"<<std::endl<<std::setfill(' ');
	pb.display_all();
}

/* void	ask_index()
{
	const char *input;
	std::string i;

	std::cout<<"\e[36mPlease Enter the Contact's index to be display\e[0m"<<std::endl;
	std::getline(std::cin, input);
	i = atoi(input);
	//convert to integers with atoi
	//input checking based on amount of contacts stored
	//call print contact func of contacts[i].print_contact (i will be the stored value of integer conversion)
} */

void	menu_input_check(PhoneBook &pb)
{
	std::string input;
	
	//std::cout<<"\e[38m"<<"Please write any of the following commands \n";
	std::cout<<"\e[36m_>\e[0m";
	while (std::getline(std::cin, input) && input.compare("EXIT"))
	{
		
		if(input == "ADD")
			pb.add();
		else if(input == "SEARCH")
			display_data(pb);
		else
		{
			std::cout<<"\e[31mPlease Enter a valid Command!\e[0m"<<std::endl;
			std::cout<<"\e[36m_>\e[0m";
			continue;
		}
		print_menu();
	}
}



/* void	ask_data(Contact data, PhoneBook *pb)//&pasarlo por referencia
{
	std::string reader;
	
	data.set_first(log_data("Enter First Name . . . "));
	data.set_last(log_data("Enter last Name . . ."));
	data.set_nick(log_data("Enter Nickname . . ."));
	data.set_phone(log_data("Enter Phone Number . . ."));
	data.set_dark(log_data("Enter Dark secret . . ."));
	pb->add(data);
	display_data();
	resize_string(data.get_first());
	resize_string(data.get_last());
	resize_string(data.get_nick());
	resize_string(data.get_phone());
	resize_string(data.get_dark());
}
 */