/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 07:53:58 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/09/02 09:54:38 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat():Animal(){
	_brain = new Brain;
	setType("Cat");
	std::cout << getType() << " created" << std::endl;
	std::cout<<GREEN<<"Cat Was Constructed"<<RESET<<std::endl;
}

Cat::~Cat(){
	std::cout<<RED<<"Cat Was Destructed"<<RESET<<std::endl;
	delete[] Brain;
}

Cat::Cat(Cat & ref):Animal(ref){
	_brain = new Brain("Cat");
	*this = cat;
	std::cout<<GREEN<<"Cat Copy Was Constructed"<<RESET<<std::endl;
}

Cat&		Cat::operator=(const Cat& rhs){
	this->_type = rhs._type;
	return (*this);
}

void		Cat::makeSound()const{
		std::cout<<YLLW<< "( ( (🐱 Meeeeow, prrrrrrrr) ) )"<<RESET<<std::endl;
}

std::string	Cat::getType()const{
	return(this->_type);
}


#include "Cat.hpp"

Cat::Cat()
	:Animal()
{
	_brain = new Brain;
	setType("Cat");
	std::cout << getType() << " created" << std::endl;
}

Cat::Cat(std::string idea)
	:Animal()
{
	_brain = new Brain(idea);
	setType("Cat");
	std::cout << getType() << " created" << std::endl;
}

Cat::Cat( const Cat& cat )
	:Animal()
{
	_brain = new Brain("dog");
	*this = cat;
}


Cat& Cat::operator=( const Cat& cat )
{
	(*this->_brain) = (*cat._brain);
	this->setType(cat.getType());
	return (*this);
}

Cat::~Cat()
{
	delete _brain;
	std::cout << getType() << " deleted" << std::endl;
}

void Cat::makeSound( void ) const
{
	std::cout << "..." << std::endl;
}

void Cat::makeThink( void ) const
{
	_brain->brainSound();
}