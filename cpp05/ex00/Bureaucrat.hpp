/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 00:10:06 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/09/16 20:44:18 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

//============COLORS!=======//
#define						RED "\e[31m"
#define						GREEN "\e[32m"
#define						BLUE "\e[36m"
#define						LILA "\e[35m"
#define						YLLW "\e[33m"
#define						RESET "\e[0m"

class	Bureaucrat{

		private:
			const std::string		_name;
			int						_grade;

		public:
			Bureaucrat();
			Bureaucrat(std::string name, int grade);
			Bureaucrat(Bureaucrat const & ref);
			~Bureaucrat();
			Bureaucrat & operator=(Bureaucrat const & ref);
	
			const std::string	getName()const;
			int					getGrade()const;
			void				setGrade(int grade);
			void				incrementGrade();
			void				decrementGrade();
	
			//===============Exceptions===============//
			/*	we create a new class  that inherits from exception
				class in order to use the func what() and we place throw()
				at the end to avoid for throw() to be used inside the what function*/
			class GradeTooHighException: public std::exception{
				public:
					const char* what() const throw();
			};
			class GradeTooLowException: public std::exception{
				public:
					const char* what() const throw();
			};
};

		std::ostream & operator<<( std::ostream & o, Bureaucrat const & rhs);


#endif
