/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 00:17:03 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/09/16 12:13:41 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <exception>

/*	Custom exceptions are stored from the moment that they are thrown in the catch 
	block inside an instance and can be retreived with the func WHAT()*/

int main(void)
{
	Bureaucrat	milton("Milton", 1);
	Form*		form1 = new ShrubberyCreationForm("Milton");
	Form*		form2 = new PresidentialPardonForm("Romy");
	Form*		form3 = new RobotomyRequestForm("Svenja");
	
	milton.executeForm(*form2);
	try{
		milton.signForm(*form1);
		milton.signForm(*form2);
		milton.signForm(*form3);
		form1->execute(milton);
		form2->execute(milton);
		form3->execute(milton);
		form3->execute(milton);
	}
	catch (std::exception & e){
		
		std::cout<<RED<<e.what()<<std::endl;
	}
}