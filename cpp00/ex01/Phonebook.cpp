/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 23:07:35 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/08/04 19:52:47 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

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
		std::cout<<GREEN<<message<<RESET<<std::endl;
		std::getline(std::cin, reader);
		while(reader.empty())
		{
			std::cout<<RED<<"Please Enter a valid input!"<<RESET<<std::endl;
			std::getline(std::cin, reader);
		}
	return (reader);
}

void	print_menu()
{
		std::cout<<GREEN<<"\n"<<std::setw(28)<<std::setfill('-')<<"\n"
				 <<std::setw(26)<<std::setfill(' ')<<"RETRO PHONEBOOK MENU!\n"
				 <<std::setw(26)<<"   Please write a command\n"<<std::setfill(' ')
				 <<std::setw(28)<<std::setfill('-')<<"\n"<<std::setfill(' ')
				 <<std::setw(17)<<"[  ADD ]\n"<<std::setfill(' ')
				 <<std::setw(17)<<"[SEARCH]\n"<<std::setfill(' ')
				 <<std::setw(17)<<"[ EXIT ]\n"<<std::setfill(' ')<<RESET;
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

void	PhoneBook::ask_index()
{
	int			input;
	char		tmp_index;
	
	std::cout<<GREEN<<"\nPlease enter the Contact's index to display Info"<<RESET<<std::endl;
	std::cin>>tmp_index;
	while(!isdigit(tmp_index))
	{
		std::cin.clear();
		std::cin.ignore(500, '\n');
		std::cout<<RED<<"Please Enter correct input"<<RESET<<std::endl;
		std::cin>>tmp_index;
	}
	input = atoi (&tmp_index);
	if(input < 8)
		contact[input].print_contact();
	else
		std::cout<<RED<<"Invalid Entry: No contacts were found Under this index"<<RESET<<std::endl;
		
}

void	display_data(PhoneBook &pb)
{
	std::cout<<GREEN<<std::setw(50)<<std::setfill('_')<<"\n"<<std::setfill(' ')
			<<std::setw(11)<< "index|"<< std::setw(11)<<"First name|"<<std::setfill(' ')
			<<std::setw(11)<<"Last Name|"<< std::setw(11)<<"Nickname|"<<std::endl<<std::setfill(' ')<<RESET;
	pb.display_all();
}

void	menu_input_check(PhoneBook &pb)
{
	std::string input;
	
	std::cout<<GREEN<<"_>"<<RESET;
	while (std::getline(std::cin, input) && input.compare("EXIT"))
	{
		
		if(input == "ADD")
			pb.add();
		else if(input == "SEARCH")
		{
			display_data(pb);
			pb.ask_index();
		}
		else
		{
			std::cout<<RED<<"Please Enter a valid Command!"<<RESET<<std::endl;
			std::cout<<GREEN<<"_>"<<RESET;
			continue;
		}
		print_menu();
	}
}
