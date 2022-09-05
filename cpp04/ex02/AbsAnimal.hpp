/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AbsAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 07:44:10 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/09/05 22:31:01 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ABSANIMAL_HPP
#define ABSANIMAL_HPP

#include <iostream>

//============COLORS!=======//
#define						RED "\e[31m"
#define						GREEN "\e[32m"
#define						BLUE "\e[36m"
#define						LILA "\e[35m"
#define						YLLW "\e[33m"
#define						RESET "\e[0m"

class	AbsAnimal{

	protected:
		std::string	_type;
	
	public:
		
		AbsAnimal(); //Constructor
		virtual ~AbsAnimal(); //Destructor
		AbsAnimal(const AbsAnimal& ref);// Copy
		
		AbsAnimal&				operator=(const AbsAnimal& rhs); //Overload
		
		virtual std::string	getType()const;
		virtual void		makeSound()const = 0;
};


std::ostream &			operator<<( std::ostream & o, AbsAnimal const & i );

#endif
