/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 00:17:03 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/09/12 21:29:08 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "Bureaucrat.hpp"
// #include <exception>

// #include "Bureaucrat.hpp"

// int main(void)
// {
// 	try
// 	{
// 		Bureaucrat joe("Joe", -40);
// 	}
// 	catch(std::exception& e) // WHATS THE DIFF BETWEEN CALLING THE EXCEP CLASS AND THE PRECISE CUSTOM EXCEPTION
// 	{
// 		std::cout<<RED<< e.what() << '\n';
// 	}
// 	std::cout << std::endl << std::endl;
// 	try
// 	{
// 		Bureaucrat joe("Joe", 1240);
// 	}
// 	catch(Bureaucrat::GradeTooLowException& e)
// 	{
// 		std::cout<<RED<< e.what() << '\n';
// 	}
	
// }
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
	try{
		Bureaucrat bill("Bill", -49);
	}
	catch (std::exception &e){
		std::cout <<RED<< e.what()<<RESET;
	}
	std::cout << std::endl << std::endl;
	//-------------------------------------------------------

	// 256
	std::cout << std::endl;
	std::cout <<GREEN<< "CONSTRUCTING WITH GRADE 256:" <<RESET<< std::endl;
	std::cout <<GREEN<< "----------------------------" <<RESET<< std::endl;
	try{
		Bureaucrat bill("Bill", 256);
	}
	catch (std::exception &e){
		std::cout <<RED<< e.what()<<RESET;
	}
	std::cout << std::endl << std::endl;
	//-------------------------------------------------------

	// Normal increment/decrement and "<<" overload
	std::cout << std::endl;
	std::cout <<GREEN<< "IN/DECREMENT + \"<<\" overload:" <<RESET<< std::endl;
	std::cout <<GREEN<< "----------------------------" <<RESET<< std::endl;
	Bureaucrat bob("Bob", 1);
	try{
		bob.decrementGrade();
	}
	catch (std::exception &e){
		std::cout <<RED<< e.what()<<RESET;
	}
	// "<<" operator overload used
	std::cout << bob << std::endl;
	try{
		bob.incrementGrade();
		bob.incrementGrade();
		bob.incrementGrade();
	}
	catch (std::exception &e){
		std::cout <<RED<< e.what()<<RESET;
	}
	// "<<" operator overload used
	std::cout << bob;
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
	catch (std::exception &e)
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