
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

#include "AbsAnimal.hpp"
#include "Brain.hpp"

//============COLORS!=======//
#define						RED "\e[31m"
#define						GREEN "\e[32m"
#define						BLUE "\e[36m"
#define						LILA "\e[35m"
#define						YLLW "\e[33m"
#define						RESET "\e[0m"

class Dog:public AbsAnimal{

	private:
		Brain*		_brain;
	
	public:
		
		Dog(); //Constructor
		virtual ~Dog(); //Destructor
		Dog(const Dog& ref);// Copy
		
		Dog&		operator=(const Dog& rhs); //Overload
		
		void		makeSound()const;//Overrided from virtual
};


std::ostream &			operator<<( std::ostream & o, Dog const & i );

#endif
