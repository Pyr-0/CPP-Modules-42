/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 07:53:58 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/09/03 18:44:55 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

//====== CONSTRUCTORS =========//

Cat::Cat():Animal(){

	this->_type = "Cat";
	_brain = new Brain;
	std::cout<<RED<< getType() << " Was Constructed with a new Brain"<<RESET<< std::endl;
}

Cat::~Cat(){

	delete _brain;
	std::cout<<RED<<"Cat and its Brain Were Destructed"<<RESET<<std::endl;
}

Cat::Cat(const Cat& copy):Animal(copy){
	*this = copy; // here it jumps into the *Asignment operator overload* function
	std::cout<<GREEN<<"Cat Copy Was Constructed"<<RESET<<std::endl;
}

Cat&		Cat::operator=(const Cat& rhs){
	
	this->_type = rhs._type; // we make the actual copy of the type, same as saying *Animal::operator=rhs)*
	if(this->_brain)
		delete this->_brain;
	this->_brain = new Brain(*(rhs._brain)); // Deep copy created by allocating once more a new copy of the brain.
	return (*this);
}

void		Cat::makeSound()const{
		std::cout<<YLLW<< "( ( (🐱 Meeeeow, prrrrrrrr) ) )"<<RESET<<std::endl;
}
