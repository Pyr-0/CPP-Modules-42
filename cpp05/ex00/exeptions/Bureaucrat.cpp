/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 00:31:37 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/09/12 21:28:38 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"

//====================== CONSTRUCTORS =====================//
Bureaucrat::Bureaucrat():_name("Default Name"), _grade(75){

}
/*	what is printing the error and throw returns the error*/
Bureaucrat::Bureaucrat(std::string name, int grade):_name(name), _grade(grade){

	if(grade < 1)
		throw GradeTooHighException();
	if(grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::~Bureaucrat(){
	std::cout<<RED<< "A Bureaucrat "<<BLUE<< _name <<RED<<" with a grade "
				 <<BLUE<< _grade <<RED<< " has beed destroyed\n"<<RESET;
}

Bureaucrat::Bureaucrat(Bureaucrat const & copy){
	*this = copy;
}

//====================== OVERLOADS =====================//

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & ref){

	if(this != &ref)
		this->_grade = ref._grade;
	return (*this);
}

std::ostream & operator<<( std::ostream & o, Bureaucrat const & rhs){
	
	o <<GREEN<< rhs.getName() <<YLLW<< "'s Bureaucrat Grade is : " <<GREEN<< rhs.getGrade() <<RESET<< std::endl;
	return o;
}

//====================== ACCESSORS =====================//

const std::string	Bureaucrat::getName( void ) const{
	return this->_name;
}

int					Bureaucrat::getGrade( void ) const{
	return this->_grade;
}
int					Bureaucrat::setGrade(int grade){
	this->_grade = grade;
	return grade;
}

//====================== METHODS =====================//

void				Bureaucrat::incrementGrade( void ){

	this->_grade--;
	if(this->_grade > 150)
		throw GradeTooLowException();
}

void				Bureaucrat::decrementGrade( void ){

	this->_grade++;
	if(this->_grade <= 0)
		throw GradeTooHighException();
}

//====================== EXCEPTIONS =====================//

const char* Bureaucrat::GradeTooLowException::what() const throw(){

	return ("Grade its too Low\n");
}

const char* Bureaucrat::GradeTooHighException::what() const throw(){

	return ("Grade its too High\n");
};