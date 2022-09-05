/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 00:17:03 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/09/06 00:41:31 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <exception>

#include "Bureaucrat.hpp"

int main(void)
{
	// Constructor with a bad grade
	// -49
	std::cout << std::endl;
	std::cout <<GREEN<< "CONSTRUCTING WITH GRADE -49:" <<RESET<< std::endl;
	std::cout <<GREEN<< "----------------------------" <<RESET<< std::endl;
	try
	{
		Bureaucrat bill("Bill", -49);
	}
	catch (Bureaucrat::Exception &e)
	{
		std::cout <<RED<< e.what()<<RESET;
	}
	std::cout << std::endl << std::endl;
	//-------------------------------------------------------

	// 256
	std::cout << std::endl;
	std::cout <<GREEN<< "CONSTRUCTING WITH GRADE 256:" <<RESET<< std::endl;
	std::cout <<GREEN<< "----------------------------" <<RESET<< std::endl;
	try
	{
		Bureaucrat bill("Bill", 256);
	}
	catch (Bureaucrat::Exception &e)
	{
		std::cout <<RED<< e.what()<<RESET;
	}
	std::cout << std::endl << std::endl;
	//-------------------------------------------------------

	// Normal increment/decrement and "<<" overload
	std::cout << std::endl;
	std::cout <<GREEN<< "IN/DECREMENT + \"<<\" overload:" <<RESET<< std::endl;
	std::cout <<GREEN<< "----------------------------" <<RESET<< std::endl;
	Bureaucrat bob("Bob", 1);
	try
	{
		bob.decrementGrade();
	}
	catch (Bureaucrat::Exception &e)
	{
		std::cout <<RED<< e.what()<<RESET;
	}
	// "<<" operator overload used
	std::cout << bob << std::endl;
	try
	{
		bob.incrementGrade();
	}
	catch (Bureaucrat::Exception &e)
	{
		std::cout <<RED<< e.what()<<RESET;
	}
	// "<<" operator overload used
	std::cout << bob;
	std::cout << std::endl << std::endl;
	//-------------------------------------------------------

	// Increment 1 exception
	std::cout << std::endl;
	std::cout <<GREEN<< "INCREMENT GRADE 1:" <<RESET<< std::endl;
	std::cout <<GREEN<< "----------------------------" <<RESET<< std::endl;
	try
	{
		bob.incrementGrade();
	}
	catch (Bureaucrat::Exception &e)
	{
		std::cout <<RED<< e.what()<<RESET;
	}
	std::cout << std::endl << std::endl;
	//-------------------------------------------------------

	// Decrement 150 exception
	std::cout << std::endl;
	std::cout <<GREEN<< "DECREMENT GRADE 150:" <<RESET<< std::endl;
	std::cout <<GREEN<< "----------------------------" <<RESET<< std::endl;
	bob.setGrade(150);
	try
	{
		bob.decrementGrade();
	}
	catch (Bureaucrat::Exception &e)
	{
		std::cout <<RED<< e.what()<<RESET;
	}
	std::cout << std::endl << std::endl;

	//-------------------------------------------------------
	std::cout << std::endl;
	std::cout <<GREEN<< "DESTRUCTORS:" <<RESET<< std::endl;
	std::cout <<GREEN<< "----------------------------" <<RESET<< std::endl;
	return (0);
}