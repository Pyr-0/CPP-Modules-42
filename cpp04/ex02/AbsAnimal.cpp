/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AbsAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 07:53:58 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/09/05 23:14:28 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AbsAnimal.hpp"

AbsAnimal::AbsAnimal():_type("AbsAnimal"){
	std::cout<<GREEN<<"Abs Animal Was Constructed"<<RESET<<std::endl;
}

AbsAnimal::~AbsAnimal(){
	std::cout<<RED<<"AbsAnimal Was Destroyed"<<RESET<<std::endl;
}

AbsAnimal::AbsAnimal(const AbsAnimal & ref){
	this->_type = ref._type;
	std::cout<<GREEN<<"AbsAnimal Copy Was Constructed"<<RESET<<std::endl;
}

AbsAnimal&		AbsAnimal::operator=(const AbsAnimal& rhs){
	this->_type = rhs._type;
	return (*this);
}

void		AbsAnimal::makeSound()const{
	std::cout<<YLLW<<"( ( (. . . Generic Absanimal sound . . .) ) )"<<RESET<<std::endl;
}

std::string	AbsAnimal::getType()const{
	return(this->_type);
}

std::ostream &			operator<<( std::ostream & o, AbsAnimal const & i )
{
	o << "Type = " << i.getType();
	return o;
}
