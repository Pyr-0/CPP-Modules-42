/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 07:53:58 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/09/03 18:39:40 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal():_type("Animal"){
	std::cout<<GREEN<<"Animal Was Constructed"<<RESET<<std::endl;
}

Animal::~Animal(){
	std::cout<<RED<<"Animal Was Destructed"<<RESET<<std::endl;
}

Animal::Animal(const Animal & ref){
	this->_type = ref._type;
	std::cout<<GREEN<<"Animal Copy Was Constructed"<<RESET<<std::endl;
}

Animal&		Animal::operator=(const Animal& rhs){
	this->_type = rhs._type;
	return (*this);
}

void		Animal::makeSound()const{
	std::cout<<YLLW<<"( ( (. . . Generic animal sound . . .) ) )"<<RESET<<std::endl;
}

std::string	Animal::getType()const{
	return(this->_type);
}
