/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 17:32:18 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/09/13 21:33:26 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>


//============COLORS!=======//
#define						RED "\e[31m"
#define						GREEN "\e[32m"
#define						BLUE "\e[36m"
#define						LILA "\e[35m"
#define						YLLW "\e[33m"
#define						RESET "\e[0m"

class Bureaucrat;

class Form{
private:
	const std::string	_name;
	const int			_gradeToBeSigned;
	const int			_gradeToBeExec;
	bool				_signedState;
	
public:
	Form();
	Form(const Form& copy);
	Form(std::string name, int signGrade, int execGrade);
	Form & operator=(const Form & ref);
	~Form();

	std::string getName(void)const;
	int		getSignGrade( void ) const;
	bool	getSignState( void ) const;
	int		getExecGrade( void ) const;
	void	beSigned(Bureaucrat & b);

	class GradeTooHighException: public std::exception{
			public:
				const char* what() const throw();
		};

		class GradeTooLowException: public std::exception{
			public:
				const char* what() const throw();
		};
	
};

	std::ostream&	operator<<(std::ostream & o, const Form& rhs);


#endif