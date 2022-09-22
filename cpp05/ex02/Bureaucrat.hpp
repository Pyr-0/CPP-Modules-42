/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 00:10:06 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/09/22 18:44:59 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include "Form.hpp"

//============COLORS!=======//
#define						RED "\e[31m"
#define						GREEN "\e[32m"
#define						BLUE "\e[36m"
#define						LILA "\e[35m"
#define						YLLW "\e[33m"
#define						RESET "\e[0m"

class	Form;

class	Bureaucrat{

	private:
		const std::string		_name;
		int						_grade;

	public:
		// Constructors / destructor / '=' overload
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		~Bureaucrat();
		Bureaucrat(Bureaucrat const & ref);
		Bureaucrat & operator=(Bureaucrat const & ref);
	void	executeForm(Form const & form)
		;
		
		const std::string	getName()const;
		int					getGrade()const;
		void				setGrade(int grade);
		void				incrementGrade();
		void				decrementGrade();
		void				signForm(Form & form);

		class GradeTooHighException: public std::exception{ //we create a new class  that inherits from exception class in order to use the func what()
			public:
			const char* what() const throw(); // we place throw at the end to avoid for throw to be used inside the what function
		};

		class GradeTooLowException: public std::exception{
			public:
			const char* what() const throw();
		};
};

// << overload
std::ostream & operator<<( std::ostream & o, Bureaucrat const & rhs);


#endif