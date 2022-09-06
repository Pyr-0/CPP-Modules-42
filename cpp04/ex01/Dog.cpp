/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 07:53:58 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/09/06 20:41:08 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Brain.hpp"

Dog::Dog():Animal(){

	this->_type = "Dog";
	this->_brain = new Brain;
	std::cout<<RED<<"Dog Was Constructed with a new Brain 🧠"<<RESET<<std::endl;
}

Dog::~Dog(){

	delete this->_brain;
	std::cout<<RED<<"Dog and its Brain Were Destroyed"<<RESET<<std::endl;
}

Dog::Dog(const Dog & copy):Animal(copy){
	*this = copy; // here it jumps into the *Asignment operator overload* function
	std::cout<<GREEN<<"Dog Copy Was Constructed"<<RESET<<std::endl;
}

Dog&		Dog::operator=(const Dog& rhs){

	this->_type = rhs._type; // we make the actual copy of the type, same as saying *Animal::operator=rhs)*
	if(this->_brain)
		delete this->_brain;
	this->_brain = new Brain(*(rhs._brain)); // Deep copy created by allocating once more a new copy of the brain.
	return (*this);
}

void		Dog::makeSound()const{
	std::cout<<YLLW<<"( ( (🐕 WOOF! WOOF!) ) )"<<RESET<<std::endl;
}
