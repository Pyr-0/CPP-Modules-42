
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 07:53:58 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/08/26 08:56:36 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal():_type("WrongAnimal"){
	std::cout<<GREEN<<"WrongAnimal Was Constructed"<<RESET<<std::endl;
}

WrongAnimal::~WrongAnimal(){
	std::cout<<RED<<"WrongAnimal Was Destructed"<<RESET<<std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal & ref){
	this->_type = ref._type;
	std::cout<<GREEN<<"WrongAnimal Copy Was Constructed"<<RESET<<std::endl;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& rhs){
	this->_type = rhs._type;
	return (*this);
}

void			WrongAnimal::makeSound()const{
	std::cout<<YLLW<<"( ( (. . . Generic WrongAnimal sound . . .) ) )"<<RESET<<std::endl;
}

std::string		WrongAnimal::getType()const{
	return(this->_type);
}
