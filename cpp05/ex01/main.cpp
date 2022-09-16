/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 00:17:03 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/09/16 21:08:32 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <exception>

/*	Custom exceptions are stored from the moment that they are thrown in the catch 
	block inside an instance and can be retreived with the func WHAT()*/

int main(void)
{
	Bureaucrat	volgon("Volgon", 42);
	Bureaucrat	bob("Bob", 1);
	Form		a("Einbürgerungstest", 32, 6);
	Form		b("Karma Points", 146, 111);
	try{
// Constructors
	std::cout <<GREEN<< std::endl;
	std::cout <<GREEN<< "CONSTRUCTION:" << std::endl;
	std::cout <<GREEN<< "----------------------------" << std::endl;
	std::cout<< volgon<<std::endl;
	std::cout<< bob<<std::endl;

	std::cout<< a<<std::endl;
	std::cout<< b<<std::endl;

	// Increment & Decrement
	std::cout <<GREEN<< "INCREMENT:" << std::endl;
	std::cout <<GREEN<< "----------------------------" << std::endl;

	volgon.decrementGrade();
	volgon.decrementGrade();
	volgon.incrementGrade();
	
	std::cout<< volgon<<std::endl;
	
	// Sign forms
	std::cout <<GREEN<< "SIGN FORMS:" << std::endl;
	std::cout <<GREEN<< "----------------------------" << std::endl;

	a.beSigned(bob);
	// Sign KO
	std::cout<< RED<< "SIGN KO:" << RESET<<std::endl;
	volgon.signForm(a);
	std::cout << std::endl;
	// Sign OK
	std::cout<<GREEN<< "SIGN OK:" << RESET<<std::endl;
	bob.signForm(a);
	std::cout << std::endl;
	}
	catch(std::exception & e){
		std::cout<< e.what()<<std::endl;
	}

	// Sign OK
	std::cout<<GREEN << "SIGN OK volgon:" <<RESET<< std::endl;
	volgon.signForm(a);
	std::cout << std::endl;
	
	// Sign OK
	std::cout<< RED<< "SIGN KO:" << RESET<<std::endl;
	bob.signForm(b);
	std::cout << std::endl;

	std::cout <<GREEN<< "DESTRUCTORS:" << std::endl;
	std::cout <<GREEN<< "----------------------------" << std::endl;
	return (0);
}