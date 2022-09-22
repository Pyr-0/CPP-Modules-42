/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 00:31:37 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/09/22 18:53:01 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"

//====================== CONSTRUCTORS =====================//

Bureaucrat::Bureaucrat():_name("Default Name"), _grade(75){}

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

	o <<GREEN<< rhs.getName() <<YLLW<< " the Bureaucrat, Grade: " <<GREEN<<"["<< rhs.getGrade()<<"]"<<RESET<< std::endl;
	return o;
}

//====================== ACCESSORS =====================//

const std::string	Bureaucrat::getName( void ) const{
	return this->_name;
}

int					Bureaucrat::getGrade( void ) const{
	return this->_grade;
}

void					Bureaucrat::setGrade(int grade){
	this->_grade = grade;
}

//====================== METHODS =====================//
/*	We can throw() our specific error/exceptions 
	inside of other functions */
void				Bureaucrat::incrementGrade( void ){

	this->_grade--;
	if(this->_grade <= 0)
		throw GradeTooHighException();
}

void				Bureaucrat::decrementGrade( void ){

	this->_grade++;
	if(this->_grade > 150)
		throw GradeTooLowException();
}

//====================== EXCEPTIONS =====================//

/*	Here we Overloading the what() function, customizing 
	it so i have my own error message, BUT we cannot THROW() in  here
	and that is why the syntax says "const throw()" */
const char* Bureaucrat::GradeTooLowException::what() const throw(){

	return ("Grade its too Low\n");
}

const char* Bureaucrat::GradeTooHighException::what() const throw(){

	return ("Grade its too High\n");
};

//====================== Ex01 =====================//

void	Bureaucrat::signForm(Form & form){
	
	try{
		form.beSigned(*this);
		std::cout<<GREEN<<this->_name<<RED<<" SIGNED "<<GREEN<<form.getName()<<std::endl;
	}
	catch(std::exception & exception){
		std::cout<<GREEN<<this->_name<<RED<<" COULD NOT SIGN "<<GREEN<<form.getName()
		<<RED<<" because "<< exception.what()<< RESET<<std::endl;
	}
}


//====================== Ex02 =====================//

void Bureaucrat::executeForm(Form const & form)
{
	try{
		form.execute(*this);
		std::cout <<GREEN<< this->_name << YLLW<< " sucesfully executed " <<GREEN<< form <<RESET << std::endl;
	}
	catch (std::exception &e){
		std::cout<< RED<< e.what() <<RESET<< std::endl;
	}
}
