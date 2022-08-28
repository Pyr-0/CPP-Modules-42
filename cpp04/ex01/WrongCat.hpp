/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 07:44:10 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/08/26 08:06:08 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include <iostream>
#include "WrongAnimal.hpp"

//============COLORS!=======//
#define						RED "\e[31m"
#define						GREEN "\e[32m"
#define						BLUE "\e[36m"
#define						LILA "\e[35m"
#define						YLLW "\e[33m"
#define						RESET "\e[0m"

class WrongCat:public WrongAnimal {

	private:
		std::string	_type;
	
	public:
		
		WrongCat(); //Constructor
		~WrongCat(); //Destructor
		WrongCat(WrongCat& ref);// Copy
		
		WrongCat&		operator=(const WrongCat& rhs); //Overload
		
		void			makeSound()const;//Overrided from virtual
};

#endif
