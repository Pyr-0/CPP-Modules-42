/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonFormidentialFormPresidentialPardonForm.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 17:31:48 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/09/15 23:53:09 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

//====================== CONSTRUCTORS =====================//
PresidentialPardonForm::PresidentialPardonForm()
:Form("Default Presidential Form", 25, 5), _target("Default Target"){

}
PresidentialPardonForm::PresidentialPardonForm(std::string target)
:Form("Presidential Form", 25, 5), _target(target){
}

PresidentialPardonForm::~PresidentialPardonForm(){}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & copy)
: Form(copy), _target(copy._target){
}

//====================== OVERLOADS =====================//

/*	In an Assignment Op. we have to asign all atributes 
	that are not const */
PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const & ref){

	if(this != &ref)
	{
		this->_target = ref._target;
	}
	return (*this);
}

std::ostream & operator<<( std::ostream & o, const PresidentialPardonForm & rhs){
	
	o <<GREEN<< rhs.getName()
		<<YLLW<<" Sign Grade is : "<<GREEN<< rhs.getSignGrade()<<RESET
		<<YLLW<<" and Execute Grade is : "<<GREEN<<rhs.getExecGrade();
		if (rhs.getSignState())
			o<< RED<<" || The PresidentialPardonForm is Signed"<<RESET<< std::endl;
		else
			o<< RED<<" || The PresidentialPardonForm is Not Signed"<< RESET<<std::endl;

	return o;
}

//====================== ACCESSORS =====================//

std::string	PresidentialPardonForm::getTarget( void )const{
	return this->_target;
}

void	PresidentialPardonForm::execute(const Bureaucrat & executor)const{

	if(this->_signedState == false )
		throw FormNotSignedException();
	else if(executor.getGrade() > this->_gradeToBeExec)
		throw GradeTooLowException();
	else
		std::cout <<GREEN<< this->_target <<YLLW<< " was pardoned by Zaphod Beeblebrox\n" <<RESET<<std::endl;
}
//====================== METHODS =====================//

