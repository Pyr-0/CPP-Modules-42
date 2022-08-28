
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 07:44:10 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/08/26 08:06:08 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include "Animal.hpp"

//============COLORS!=======//
#define						RED "\e[31m"
#define						GREEN "\e[32m"
#define						BLUE "\e[36m"
#define						LILA "\e[35m"
#define						YLLW "\e[33m"
#define						RESET "\e[0m"

class Dog:public Animal{

	private:
		std::string	_type;
	
	public:
		
		Dog(); //Constructor
		~Dog(); //Destructor
		Dog(Dog& ref);// Copy
		
		Dog&				operator=(const Dog& rhs); //Overload
		
		std::string	getType()const; //Overrided from virtual
		void		makeSound()const;//Overrided from virtual
};

#endif
