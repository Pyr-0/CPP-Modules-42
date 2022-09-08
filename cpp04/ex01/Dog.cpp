/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 07:53:58 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/09/08 20:24:57 by mrojas-e         ###   ########.fr       */
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

Brain *Dog::getBrain( void ) const{
	return (this->_brain);
}

void Dog::compareTo(Dog const & other_dog) const
{
	std::cout << std::endl;
	std::cout << "Now comparing two dogs\n";
	std::cout << "My brain's heap address: " << static_cast<void*>(this->_brain) << std::endl;
	std::cout << "Other's heap address: " << static_cast<void*>(other_dog.getBrain()) << std::endl;
	std::cout << std::endl;
	std::cout << "My brain's ideas \t\t | \t\t\t Other brain's ideas\n";
	for (int i = 0; i < 100; i++)
		std::cout << "-";
	std::cout << std::endl;
	for (int i = 0; i < 100; i++)
		std::cout << ((this->_brain)->getIdeas())[i] << "\t\t\t | \t\t\t" << ((other_dog.getBrain())->getIdeas())[i] << std::endl;
	std::cout << std::endl;
}