/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 17:31:48 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/09/22 18:40:32 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

//====================== CONSTRUCTORS =====================//

Form::Form():_name("Default Name"), _gradeToBeSigned(75), _gradeToBeExec(75), _signedState(0){}

Form::Form(std::string name, int signGrade, int execGrade)
:_name(name), _gradeToBeSigned(signGrade), _gradeToBeExec(execGrade), _signedState(0){

	if(signGrade < 1 || execGrade < 1)
		throw GradeTooHighException();
	if(signGrade > 150 || execGrade > 150)
		throw GradeTooLowException();
}

Form::~Form(){}

/*	Constant atributes can still be initialized in the init 
	list of a constructor */
Form::Form(Form const & copy): _name(copy._name), _gradeToBeSigned(copy._signedState),
_gradeToBeExec(copy._gradeToBeExec), _signedState(copy._signedState){

	*this = copy;
}

//====================== OVERLOADS =====================//

/*	In an Assignment Op. we have to asign all atributes 
	that are not const in this case the _signedState */
Form & Form::operator=(Form const & ref){

	if(this != &ref)
	{
		this->_signedState = ref._signedState;
	}
	return (*this);
}

std::ostream & operator<<( std::ostream & o, const Form & rhs){
	
	o <<GREEN<< rhs.getName()
		<<YLLW<<" Sign Grade is : "<<GREEN<< rhs.getSignGrade()<<RESET
		<<YLLW<<" and Execute Grade is : "<<GREEN<<rhs.getExecGrade();
		if (rhs.getSignState())
			o<< RED<<" || The Form is Signed"<<RESET<< std::endl;
		else
			o<< RED<<" || The Form is Not Signed"<< RESET<<std::endl;

	return o;
}

//====================== ACCESSORS =====================//

std::string	Form::getName( void )const{
	return this->_name;
}

int					Form::getSignGrade( void ) const{
	return this->_gradeToBeSigned;
}

int					Form::getExecGrade( void ) const{
	return this->_gradeToBeExec;
}

bool				Form::getSignState( void )const{
	return this->_signedState;
}

//====================== METHODS =====================//

const char* Form::GradeTooLowException::what() const throw(){

	return ("Grade its TOO Low\n");
}

const char* Form::GradeTooHighException::what() const throw(){

	return ("Grade its TOO High\n");
};

void	Form::beSigned(Bureaucrat & b){

	if(this->_gradeToBeSigned >= b.getGrade())
		this->_signedState = true;
	else
		throw GradeTooLowException();
}
