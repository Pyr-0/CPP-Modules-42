/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 17:31:48 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/09/15 22:04:13 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

//====================== CONSTRUCTORS =====================//
ShrubberyCreationForm::ShrubberyCreationForm()
:Form("Default Name", 145, 137), _target("Default Target"){

}
ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
:Form("Shrubbery Creation Form", 145, 137), _target(target){
}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & copy)
: Form(copy), _target(copy._target){
}

//====================== OVERLOADS =====================//

/*	In an Assignment Op. we have to asign all atributes 
	that are not const */
ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & ref){

	if(this != &ref)
	{
		this->_target = ref._target;
	}
	return (*this);
}

std::ostream & operator<<( std::ostream & o, const ShrubberyCreationForm & rhs){
	
	o <<GREEN<< rhs.getName()
		<<YLLW<<" Sign Grade is : "<<GREEN<< rhs.getSignGrade()<<RESET
		<<YLLW<<" and Execute Grade is : "<<GREEN<<rhs.getExecGrade();
		if (rhs.getSignState())
			o<< RED<<" || The ShrubberyCreationForm is Signed"<<RESET<< std::endl;
		else
			o<< RED<<" || The ShrubberyCreationForm is Not Signed"<< RESET<<std::endl;

	return o;
}

//====================== ACCESSORS =====================//

std::string	ShrubberyCreationForm::getTarget( void )const{
	return this->_target;
}

void	ShrubberyCreationForm::execute(const Bureaucrat & executor)const{

	if(this->_signedState == false )
		throw FormNotSignedException();
	else if(executor.getGrade() > this->_gradeToBeExec)
		throw GradeTooLowException();
	else
	{
		std::cout<<GREEN<<"Shrub Created! 🌳"<<RESET<<std::endl;
		std::string line;
		std::ifstream ini_file;
		ini_file.open("tree.txt");
		std::ofstream file((this->_target + "_shrubbery").c_str());//c_string casts all into a classic C string
		if (ini_file && file)
		{
			while (getline(ini_file, line))
			{
				file << line << "\n";
			}
			ini_file.close();
			file.close();
		}
	}
}
//====================== METHODS =====================//

