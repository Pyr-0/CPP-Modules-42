/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 00:17:03 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/09/13 21:36:04 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <exception>

/*	Custom exceptions are stored from the moment that they are thrown in the catch 
	block inside an instance and can be retreived with the func WHAT()*/

int main(void)
{
// Constructors
	std::cout <<GREEN<< std::endl;
	std::cout <<GREEN<< "CONSTRUCTION:" << std::endl;
	std::cout <<GREEN<< "----------------------------" << std::endl;
	Bureaucrat	bob("Bob", 1);
	Bureaucrat	bill("Bill", 132);
	std::cout<< bob<<std::endl;
	std::cout<< bill<<std::endl;

	Form		a("Einbürgerungstest", 32, 6);
	Form		b("Karma Points", 146, 135);
	std::cout<< a<<std::endl;
	std::cout<< b<<std::endl;

	std::cout << std::endl << std::endl;

	// Increment & Decrement
	std::cout <<GREEN<< std::endl;
	std::cout <<GREEN<< "INCREMENT:" << std::endl;
	std::cout <<GREEN<< "----------------------------" << std::endl;

	bob.decrementGrade();
	bob.decrementGrade();
	bob.incrementGrade();
	
	std::cout<< bob<<std::endl;
	
	// // Sign forms
	// std::cout << std::endl;
	// std::cout << "SIGN FORMS:" << std::endl;
	// std::cout << "----------------------------" << std::endl;

	// // Sign OK
	// std::cout << "SIGN OK:" << std::endl;
	// bob_ref.signForm(a);
	// std::cout << a << " just showed its current status" << std::endl;
	// std::cout << std::endl << std::endl;

	// // Sign KO
	// std::cout << "SIGN KO:" << std::endl;
	// bill_ref.signForm(a);
	// std::cout << a << " just showed its current status" << std::endl;
	// std::cout << std::endl << std::endl;

	// // Sign OK
	// std::cout << "SIGN OK:" << std::endl;
	// bob.signForm(b);
	// std::cout << b << " just showed its current status" << std::endl;
	// std::cout << std::endl << std::endl;
	
	// // Sign OK
	// std::cout << "SIGN OK:" << std::endl;
	// bill.signForm(b);
	// std::cout << b << " just showed its current status" << std::endl;
	// std::cout << std::endl << std::endl;

	std::cout <<GREEN<< std::endl;
	std::cout <<GREEN<< "DESTRUCTORS:" << std::endl;
	std::cout <<GREEN<< "----------------------------" << std::endl;
	return (0);
	//--------------------
	
}