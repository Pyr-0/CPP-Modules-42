/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 17:31:48 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/09/15 23:59:52 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

//====================== CONSTRUCTORS =====================//
RobotomyRequestForm::RobotomyRequestForm()
:Form("Default Robotomy Form", 25, 45), _target("Default Target"){

}
RobotomyRequestForm::RobotomyRequestForm(std::string target)
:Form("Robotomy Form", 25, 45), _target(target){
}

RobotomyRequestForm::~RobotomyRequestForm(){}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & copy)
: Form(copy), _target(copy._target){
}

//====================== OVERLOADS =====================//

/*	In an Assignment Op. we have to asign all atributes 
	that are not const */
RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const & ref){

	if(this != &ref)
	{
		this->_target = ref._target;
	}
	return (*this);
}

std::ostream & operator<<( std::ostream & o, const RobotomyRequestForm & rhs){
	
	o <<GREEN<< rhs.getName()
		<<YLLW<<" Sign Grade is : "<<GREEN<< rhs.getSignGrade()<<RESET
		<<YLLW<<" and Execute Grade is : "<<GREEN<<rhs.getExecGrade();
		if (rhs.getSignState())
			o<< RED<<" || The RobotomyRequestForm is Signed"<<RESET<< std::endl;
		else
			o<< RED<<" || The RobotomyRequestForm is Not Signed"<< RESET<<std::endl;

	return o;
}

//====================== ACCESSORS =====================//

std::string	RobotomyRequestForm::getTarget( void )const{
	return this->_target;
}

void	RobotomyRequestForm::execute(const Bureaucrat & executor)const{

	std::cout <<RED<< "<<<<<INTENSE DRILLING NOISES!!!>>>>\n" <<RESET<<std::endl;
	if(this->_signedState == false )
		throw FormNotSignedException();
	else if(executor.getGrade() > this->_gradeToBeExec)
		throw GradeTooLowException();
	int success = std::rand() % 2;
	std::cout <<RED<< "<<<<<INTENSE DRILLING NOISES!!!>>>>\n" <<RESET<<std::endl;
	if (success == 1)
		std::cout <<GREEN<< this->_target <<YLLW<< " Has been robotomized\n" <<RESET<<std::endl;
	else
		throw FailureException();
}
//====================== METHODS =====================//

