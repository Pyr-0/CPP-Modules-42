/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 07:44:10 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/09/08 12:57:40 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

//============COLORS!=======//
#define						RED "\e[31m"
#define						GREEN "\e[32m"
#define						BLUE "\e[36m"
#define						LILA "\e[35m"
#define						YLLW "\e[33m"
#define						RESET "\e[0m"

/* Virtual Method needs virtual destructor else it will only call its base class destructor */

class	Animal{

	protected:
		std::string	_type;
	
	public:
		
		Animal(); //Constructor
		virtual ~Animal(); //Destructor
		Animal(Animal& ref);// Copy
		
		Animal&				operator=(const Animal& rhs); //Overload
		
		std::string	getType()const;
		virtual void		makeSound()const;
};

#endif
