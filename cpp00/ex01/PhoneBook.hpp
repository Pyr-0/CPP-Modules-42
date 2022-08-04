/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 17:15:34 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/08/04 19:08:15 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <string>
#include <iomanip>
#include <stdlib.h>
#include <ctype.h>

#define		RED "\e[31m"
#define		GREEN "\e[32m"
#define		RESET "\e[0m"
	
class	PhoneBook{
	
	private:
		Contact		contact[8];
		int			index;
		bool		isFull;

	public:
		
		PhoneBook(void);
		~PhoneBook(void);
	
		void	add();
		void	search(Contact data);
		void	display_all();
		void	ask_data(Contact data, PhoneBook *pb);
		void	display_data(PhoneBook &pb);
		void	ask_index();
};

void	menu_input_check(PhoneBook &pb);
void	resize_string(std::string yall);



#endif