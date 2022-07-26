/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 17:32:18 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/09/22 18:55:15 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "Form.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>


//============COLORS!=======//
#define						RED "\e[31m"
#define						GREEN "\e[32m"
#define						BLUE "\e[36m"
#define						LILA "\e[35m"
#define						YLLW "\e[33m"
#define						RESET "\e[0m"


class Form;

class	Intern{

	public:
		Intern();
		Intern(const Intern& copy);
		Intern & operator=(const Intern & ref);
		~Intern();
	
		Form	*makeForm(std::string form_name, std::string form_target);
		Form	*roboForm(std::string target);
		Form	*presiForm(std::string target);
		Form	*shrubForm(std::string target);
		
		class	InternException: public std::exception{
			public:
			const char*	what()const throw();
		};
};

#endif
