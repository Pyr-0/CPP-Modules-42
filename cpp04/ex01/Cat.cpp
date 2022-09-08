/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 07:53:58 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/09/08 20:18:06 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

//====== CONSTRUCTORS =========//

Cat::Cat():Animal(){

	this->_type = "Cat";
	_brain = new Brain;
	std::cout<<RED<< "A Cat was Constructed with a new Brain 🧠"<<RESET<< std::endl;
}

Cat::~Cat(){

	delete this->_brain;
	std::cout<<RED<<"Cat and its Brain Were Destroyed"<<RESET<<std::endl;
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

Brain *Cat::getBrain( void ) const
{
	return (this->_brain);
}

void Cat::compareTo(Cat const & other_cat) const
{
	std::cout << std::endl;
	std::cout <<YLLW<< "Now comparing two cats\n";
	std::cout <<YLLW<< "My brain's heap address: " << static_cast<void*>(this->_brain) << std::endl;
	std::cout <<YLLW<< "Other's heap address: " << static_cast<void*>(other_cat.getBrain()) << std::endl;
	std::cout <<YLLW<< std::endl;
	std::cout <<YLLW<< "My brain's ideas \t\t | \t\t\t Other brain's ideas\n";
	for (int i = 0; i < 100; i++)
		std::cout << "-";
	std::cout << std::endl;
	for (int i = 0; i < 100; i++)
		std::cout << ((this->_brain)->getIdeas())[i] << "\t\t\t | \t\t\t" << ((other_cat.getBrain())->getIdeas())[i] << std::endl;
	std::cout << std::endl;
}