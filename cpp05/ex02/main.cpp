/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 00:17:03 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/09/16 19:30:32 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialForm.hpp"
#include <exception>

/*	Custom exceptions are stored from the moment that they are thrown in the catch 
	block inside an instance and can be retreived with the func WHAT()*/

void test(){

	system("leaks bureau");
}
int main(void)
{
	Bureaucrat	milton("Milton", 1);
	Form*		form1 = new ShrubberyCreationForm("Romy");
	Form*		form2 = new PresidentialForm("Milton");
	Form*		form3 = new RobotomyRequestForm("Svenja");
	
	
	//execute all forms 
	try{
		milton.signForm(*form1);
		milton.signForm(*form2);
		milton.signForm(*form3);
		form1->execute(milton);
		form2->execute(milton);
		form3->execute(milton);
	}
	catch (std::exception & e){
		
		std::cout<<RED<<e.what()<<std::endl;
	}
	

	//milton.signForm(*form1);//try catch inbuilt
	//form1->beSigned(milton);//no try catch inbuilt, needs it in main
	
//	form2->execute(milton);//try and catch needed 
//	milton.executeForm(*form1);
	//this is because the orders to sign come from the form class
	//and need a try catch block in order for the program not to crash
	//atexit(test); 
	delete form2;
	delete form3;
	delete form1;
	
	return(0);
}