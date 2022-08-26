/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 07:53:58 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/08/26 10:41:26 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog():_type("Dog"){
	std::cout<<GREEN<<"Dog Was Constructed"<<RESET<<std::endl;
}

Dog::~Dog(){
	std::cout<<RED<<"Dog Was Destructed"<<RESET<<std::endl;
}

Dog::Dog(Dog & ref):Animal(ref){
	this->_type = ref.getType();
	std::cout<<GREEN<<"Dog Copy Was Constructed"<<RESET<<std::endl;
}

Dog&		Dog::operator=(const Dog& rhs){
	this->_type = rhs._type;
	return (*this);
}

void		Dog::makeSound()const{
	std::cout<<YLLW<<"( ( (🐕 WOOF! WOOF!) ) )"<<RESET<<std::endl;
}

std::string	Dog::getType()const{
	return(this->_type);
}
