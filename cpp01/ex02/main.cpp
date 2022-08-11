/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 16:58:00 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/08/11 18:02:23 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

/*	The main difference between a pointer and a reference is that 
	the pointer does NOT have to be initialized in the same line but
	the reference DOES need to be initialized  */
int main()
{
	std::string		str = "HI THIS IS BRAIN";
	
	std::string*	stringPTR;			//A pointer to the string
	stringPTR = &str;
	std::string&	stringREF = str;	//A reference to the string
	
	std::cout<<"\e[36m"<<"The memory address of the string variable: "<<"\e[0m"<< &str <<std::endl;
	std::cout<<"\e[36m"<<"The memory address held by stringPTR: "<<"\e[0m"<< stringPTR <<std::endl;
	std::cout<<"\e[36m"<<"The memory address held by stringREF: "<<"\e[0m"<< &stringREF<<std::endl;
	
	std::cout<<"\e[36m"<<"The value of the string variable: " <<"\e[0m"<< str << std::endl;
	std::cout<<"\e[36m"<< "The value pointed to by stringPTR: "<<"\e[0m"<< *stringPTR << std::endl;
	std::cout<<"\e[36m"<<"The value pointed to by stringREF: "<<"\e[0m"<< stringREF << std::endl;
	
	return 0;
}