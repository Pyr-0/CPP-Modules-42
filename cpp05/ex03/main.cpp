/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 00:17:03 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/09/16 20:12:16 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <exception>
#include <stdlib.h>

void	check_leaks(){
	system("leaks bureau");
}

void test1()
{
	Bureaucrat	milton("Milton", 5);
	Intern		ken;
	Form*		internform;

	// milton.executeForm(*internform);
	try{
		internform = ken.makeForm("Robotomy form", "Simpleton");
		milton.signForm(*internform);
		internform->execute(milton); //FORMS HAVE NO TRY CATCH INBUILT, so either this or line 34 (same)
	}
	catch (std::exception &e){
		std::cout<<RED<< e.what()<<RESET<<std::endl;
	}
	delete internform;
}

int main(void)
{
	test1();
	// atexit(check_leaks);
}
