/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 23:07:35 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/09/24 19:38:55 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

//========= CONSTRUCTOR DESTRUCTOR=======//

PhoneBook::PhoneBook(){index = 0; isFull = false;}


PhoneBook::~PhoneBook(){}

//=========METHODS AND HELPER FUNCTIONS =======//

/*	This function takes care of storing/setting the data in
	the respective objects of the Contact class, but it also
	takes care of the possible overflow of the Contact array,
	reseting the index to the first element when the phonebook is full */
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

/*	This function will allows us to create an output message
	and take input from the user right after, the input will be stored
	and returned at the end as a string*/
std::string	log_data(std::string message)
{
		std::string input;
		std::cout<<GREEN<<message<<RESET<<std::endl;
		std::getline(std::cin, input);
		while(input.empty())
		{
			std::cout<<RED<<"Please Enter a valid input!"<<RESET<<std::endl;
			std::getline(std::cin, input);
		}
	return (input);
}

/*	This function will align and output to a grid the desired
	info of the stored contacts as long as it does not surpasses the limit
	of available contacts*/
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

/*	This function will create tabulated grid
	where some Contact's information will be displayed
	and indexed*/
void	display_data(PhoneBook &pb)
{
	std::cout<<GREEN<<std::setw(50)<<std::setfill('_')<<"\n"<<std::setfill(' ')
			<<std::setw(11)<< "index|"<< std::setw(11)<<"First name|"<<std::setfill(' ')
			<<std::setw(11)<<"Last Name|"<< std::setw(11)<<"Nickname|"<<std::endl<<std::setfill(' ')<<RESET;
	pb.display_all();
}

/*	This function will take input as long as it is a numeric value and
	search through the stored contacts the desired index*/
/* void	PhoneBook::ask_index()
{
	int			input;
	char		tmp_index;
	
	std::cout<<GREEN<<"\nPlease enter the Contact's index to display Info"<<RESET<<std::endl;
	//std::cin>>tmp_index;//c runtime library 
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
		
} */
void	PhoneBook::ask_index()
{
	
	std::cout<<GREEN<<"\nPlease enter the Contact's index to display Info"<<RESET<<std::endl;

	std::string		read;
	std::cin.clear();
	std::getline(std::cin,read);

	unsigned int		input;
	if (!(read.size() && isdigit(read[0])))
	{
		std::cout<<RED<<"Please Enter correct input"<<RESET<<std::endl;
		return ;
	}
	
	input = atoi(read.data());
	
	std::cout<<RED<<input<<RESET<<std::endl;
	if(input < CONTACT_SIZE)
	{
		contact[input].print_contact();	
	}
	else
	{
		std::cout<<RED<<"Input falls outside the range of the contacts"<<RESET<<std::endl;
	}
		
	//std::cout<<RED<<"Invalid Entry: No contacts were found Under this index"<<RESET<<std::endl;
	
}

//=================MAIN MENU==============//

/*	This function introduces the main menu and shows the 
	available commands of the phonebook*/
void	menu_input_check(PhoneBook &pb)
{
	std::string input;
	
	PhoneBook phoneBook;
	std::cout<<GREEN<<"_>"<<RESET;
	while (std::getline(std::cin, input) && input.compare("EXIT"))
	{
		phoneBook.action	();
		if(input == "ADD")
		{
			pb.add();
			std::cout<<GREEN<<"\n**Contact was Succesfully Added!**"<<RESET<<std::endl;
		}
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

void	print_menu()
{
		std::cout<<GREEN<<EASTEREGG<<"\n"<<std::setw(28)<<std::setfill('-')<<"\n"
				 <<std::setw(26)<<std::setfill(' ')<<"RETRO PHONEBOOK MENU!\n"
				 <<std::setw(26)<<"   Please write a command\n"<<std::setfill(' ')
				 <<std::setw(28)<<std::setfill('-')<<"\n"<<std::setfill(' ')
				 <<std::setw(17)<<"[  ADD ]\n"<<std::setfill(' ')
				 <<std::setw(17)<<"[SEARCH]\n"<<std::setfill(' ')
				 <<std::setw(17)<<"[ EXIT ]\n"<<std::setfill(' ')<<RESET;
}
