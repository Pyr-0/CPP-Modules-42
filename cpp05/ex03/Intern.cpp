/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 17:31:48 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/09/16 15:26:25 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

//====================== CONSTRUCTORS =====================//
Intern::Intern(){}

Intern::~Intern(){}

/*	Nothing to Copy since there are no atributes */
Intern::Intern(Intern const & copy){
	(void)copy;
}

//====================== OVERLOADS =====================//

/*	Nothing to assign all interns are the same */
Intern & Intern::operator=(Intern const & ref){

	(void)ref;
	return (*this);
}

//====================== ACCESSORS =====================//

//====================== METHODS =====================//

const char* Intern::InternException::what() const throw()
{
	return ("\e[31mIntern spills Coffee in the Form and ruins the Form... Intern Cleans full of tears\e[0m");
}

Form	*Intern::new_robo(std::string target)
{
	Form	*robo = new RobotomyRequestForm(target);
	return (robo);
}

Form	*Intern::new_president(std::string target)
{
	Form	*president = new PresidentialPardonForm(target);
	return (president);
}

Form*	Intern::new_shrub(std::string target)
{
	Form	*shrub = new ShrubberyCreationForm(target);
	return (shrub);
}

Form *Intern::makeForm(std::string form_name, std::string form_target)
{
	Form*	(Intern::*functionArray[])(std::string target) = {
			&Intern::new_robo,
			&Intern::new_president,
			&Intern::new_shrub
	};
	std::string	form[3] = {"Robotomy form", "Presidential pardon Form", "Shrubbery creation Form"};
	Form	*ret = NULL;
	for (int i = 0; i < 3; i++)
	{
		if (form[i] == form_name)
		{
			//ret = *(functionArray[i])(form_target);
			ret = (this->*functionArray[i])(form_target);
			std::cout<<GREEN << "Intern creates "<<form[i] <<" for "<<RED<<form_target<<RESET<< std::endl;
			return (ret);
		}
		else
			throw (InternException());
	}
	return (ret);
}

