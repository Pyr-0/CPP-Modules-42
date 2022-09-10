/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 07:53:58 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/09/09 20:32:13 by mrojas-e         ###   ########.fr       */
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

/*	This is a different waay of making the copy as with the Cat, here we copy directly in the 
	copy constructor without going into the assignment operator*/
Dog::Dog(const Dog & copy):Animal(copy){

	this->_brain = new Brain(*(copy._brain)); // Deep copy created by allocating once more a new copy of the brain.
	this->_type = copy._type; // we make the actual copy of the type, same as saying *Animal::operator=rhs)*
	std::cout<<GREEN<<"Dog Copy Was Constructed"<<RESET<<std::endl;
}

Dog&		Dog::operator=(const Dog& rhs){

	if (this != &rhs)
	{
		this->_type = rhs._type; // we make the actual copy of the type, same as saying *Animal::operator=rhs)*
		*this->_brain = *rhs._brain; //we dereference so we are making the copy of the actual content
	}
	return (*this);
}

void		Dog::makeSound()const{
	std::cout<<YLLW<<"( ( (🐕 WOOF! WOOF!) ) )"<<RESET<<std::endl;
}
