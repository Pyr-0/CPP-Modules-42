/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 17:15:34 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/08/04 19:20:45 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <string>

#define		RED "\e[31m"
#define		GREEN "\e[32m"
#define		RESET "\e[0m"

class	Contact{
	
	private:
		std::string	firstName;
		std::string	lastName;
		std::string	phoneNumber;
		std::string	nickName;
		std::string	darkestSecret;

	public:
	
		Contact(void);
		~Contact(void);
		//============GETTERS=======//
		std::string get_first();
		std::string get_last();
		std::string get_phone();
		std::string get_dark();
		std::string get_nick();
		//============SETTERS=======//
		void set_first(std::string);
		void set_last(std::string);
		void set_phone(std::string);
		void set_dark(std::string);
		void set_nick(std::string);
		
		void	print_contact();
};

std::string	log_data(std::string message);
void	print_menu();

#endif