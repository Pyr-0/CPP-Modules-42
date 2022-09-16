/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialFormidentialFormPresidentialForm.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 17:31:48 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/09/15 23:53:09 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialForm.hpp"

//====================== CONSTRUCTORS =====================//
PresidentialForm::PresidentialForm()
:Form("Default Presidential Form", 25, 5), _target("Default Target"){

}
PresidentialForm::PresidentialForm(std::string target)
:Form("Presidential Form", 25, 5), _target(target){
}

PresidentialForm::~PresidentialForm(){}

PresidentialForm::PresidentialForm(PresidentialForm const & copy)
: Form(copy), _target(copy._target){
}

//====================== OVERLOADS =====================//

/*	In an Assignment Op. we have to asign all atributes 
	that are not const */
PresidentialForm & PresidentialForm::operator=(PresidentialForm const & ref){

	if(this != &ref)
	{
		this->_target = ref._target;
	}
	return (*this);
}

std::ostream & operator<<( std::ostream & o, const PresidentialForm & rhs){
	
	o <<GREEN<< rhs.getName()
		<<YLLW<<" Sign Grade is : "<<GREEN<< rhs.getSignGrade()<<RESET
		<<YLLW<<" and Execute Grade is : "<<GREEN<<rhs.getExecGrade();
		if (rhs.getSignState())
			o<< RED<<" || The PresidentialForm is Signed"<<RESET<< std::endl;
		else
			o<< RED<<" || The PresidentialForm is Not Signed"<< RESET<<std::endl;

	return o;
}

//====================== ACCESSORS =====================//

std::string	PresidentialForm::getTarget( void )const{
	return this->_target;
}

void	PresidentialForm::execute(const Bureaucrat & executor)const{

	if(this->_signedState == false )
		throw FormNotSignedException();
	else if(executor.getGrade() > this->_gradeToBeExec)
		throw GradeTooLowException();
	else
		std::cout <<GREEN<< this->_target <<YLLW<< " was pardoned by Zaphod Beeblebrox\n" <<RESET<<std::endl;
}
//====================== METHODS =====================//

