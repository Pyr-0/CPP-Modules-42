/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 17:15:34 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/07/19 21:27:15 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <string>

class	PhoneBook{
	
	private:
		Contact		contact[8];
		int			index;

	public:
		
		PhoneBook(void);
		~PhoneBook(void);
	
		void	add();
		void	search(Contact data);
		void	print_contact(int index);
};

void	menu_input_check(PhoneBook &pb);
void	ask_data(Contact data, PhoneBook *pb);
void	resize_string(std::string yall);



#endif