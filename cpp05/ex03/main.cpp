/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 00:17:03 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/09/16 15:23:21 by mrojas-e         ###   ########.fr       */
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
	Bureaucrat	milton("Milton", 1);
	Intern		jojo;
	Form*		internform;
	
	internform = jojo.makeForm("robotomy", "simpleton");
	milton.signForm(*internform);
	milton.executeForm(*internform);
	internform->execute(milton); //WHY ERROR????

	atexit(check_leaks);
}
int main(void)
{
	test1();
}