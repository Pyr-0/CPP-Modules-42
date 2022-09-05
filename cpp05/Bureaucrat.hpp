/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 00:10:06 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/09/06 00:38:15 by mrojas-e         ###   ########.fr       */
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

class Bureaucrat
{
	public:
		// Constructors / destructor / '=' overload
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		~Bureaucrat();
		Bureaucrat(Bureaucrat const & ref);
		Bureaucrat & operator=(Bureaucrat const & ref);

		// Increment / Decrement grade
		void				incrementGrade( void );
		void				decrementGrade( void );

		// Getters
		const std::string	getName( void ) const;
		int					getGrade( void ) const;

		// Setters
		void				setGrade( const int new_grade);

		// Nested Exception classes:
		class Exception : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public Bureaucrat::Exception
		{
			public:
				virtual const char* what() const throw();
		};
		
		class GradeTooHighException : public Bureaucrat::Exception
		{
			public:
				virtual const char* what() const throw();
		};

	private:
		const std::string	_name;
		int					_grade; //1 = highest, 150 = lowest

};

// << overload
std::ostream & operator<<( std::ostream & o, Bureaucrat const & rhs);


#endif