/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 07:53:58 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/08/26 08:54:09 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat():_type("WrongCat"){
	std::cout<<GREEN<<"WrongCat Was Constructed"<<RESET<<std::endl;
}

WrongCat::~WrongCat(){
	std::cout<<RED<<"WrongCat Was Destructed"<<RESET<<std::endl;
}

WrongCat::WrongCat(WrongCat & ref):WrongAnimal(ref){
	this->_type = ref._type;
	std::cout<<GREEN<<"WrongCat Copy Was Constructed"<<RESET<<std::endl;
}

WrongCat&		WrongCat::operator=(const WrongCat& rhs){
	this->_type = rhs._type;
	return (*this);
}

void		WrongCat::makeSound()const{
	std::cout<<YLLW<< "( ( (🐱 Meeeeow, prrrrrrrr) ) )"<<RESET<<std::endl;
}
