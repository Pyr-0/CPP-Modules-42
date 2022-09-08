/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 07:53:58 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/09/08 12:58:59 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat():Animal(){
	this->_type = "Cat";
	std::cout<<GREEN<<"Cat Was Constructed"<<RESET<<std::endl;
}

Cat::~Cat(){
	std::cout<<RED<<"Cat Was Destructed"<<RESET<<std::endl;
}

Cat::Cat(Cat & ref):Animal(ref){
	this->_type = ref._type;
	std::cout<<GREEN<<"Cat Copy Was Constructed"<<RESET<<std::endl;
}

Cat&		Cat::operator=(const Cat& rhs){
	this->_type = rhs._type;
	return (*this);
}

void		Cat::makeSound()const{
		std::cout<<YLLW<< "( ( (🐱 Meeeeow, prrrrrrrr) ) )"<<RESET<<std::endl;
}
