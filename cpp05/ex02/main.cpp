/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 00:17:03 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/09/14 17:40:13 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <exception>

/*	Custom exceptions are stored from the moment that they are thrown in the catch 
	block inside an instance and can be retreived with the func WHAT()*/

int main(void)
{
	Bureaucrat	milton("Milton", -42);
	Bureaucrat	romy("Romy", 1);
	Form		a("Einbürgerungstest", 32, 6);
	Form		b("Karma Points", 146, 111);
	try{
// Constructors
	std::cout <<GREEN<< std::endl;
	std::cout <<GREEN<< "CONSTRUCTION:" << std::endl;
	std::cout <<GREEN<< "----------------------------" << std::endl;
	std::cout<< milton<<std::endl;
	std::cout<< romy<<std::endl;

	std::cout<< a<<std::endl;
	std::cout<< b<<std::endl;

	std::cout << std::endl << std::endl;

	// Increment & Decrement
	std::cout <<GREEN<< std::endl;
	std::cout <<GREEN<< "INCREMENT:" << std::endl;
	std::cout <<GREEN<< "----------------------------" << std::endl;

	milton.decrementGrade();
	milton.decrementGrade();
	milton.incrementGrade();
	
	std::cout<< milton<<std::endl;
	
	// Sign forms
	std::cout <<GREEN<< std::endl;
	std::cout <<GREEN<< "SIGN FORMS:" << std::endl;
	std::cout <<GREEN<< "----------------------------" << std::endl;

	a.beSigned(romy);
	// Sign KO
	// std::cout << "SIGN KO:" << std::endl;
	// milton.signForm(a);
	// std::cout << a << " just showed its current status" << std::endl;
	// std::cout << std::endl << std::endl;
	// Sign OK
	std::cout << "SIGN OK ROMY:" << std::endl;
	romy.signForm(a);
	std::cout << std::endl << std::endl;

	}
	catch(std::exception & e)
	{
		std::cout<< e.what()<<std::endl;
	}
	
	// Sign OK
	std::cout << "SIGN OK MILTON:" << std::endl;
	milton.signForm(a);
	std::cout << std::endl << std::endl;
	
	// // Sign OK
	// std::cout << "SIGN OK:" << std::endl;
	// romy.signForm(b);
	// std::cout << b << " just showed its current status" << std::endl;
	// std::cout << std::endl << std::endl;

	std::cout <<GREEN<< std::endl;
	std::cout <<GREEN<< "DESTRUCTORS:" << std::endl;
	std::cout <<GREEN<< "----------------------------" << std::endl;
	return (0);
	//--------------------
	
}