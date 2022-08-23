/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 17:52:21 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/08/23 20:00:02 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//===================== CONSTRUCTOR ======================//

Fixed::Fixed(): _value(0){
	std::cout <<YLLW<< "Default constructor called"<<RESET<< std::endl;
}

//===================== COPY CONSTRUCTOR ======================//
Fixed::Fixed( const Fixed &alreadyExistingObject ){

	std::cout <<GREEN<< "Copy constructor called"<< RESET<<std::endl;
	*this = alreadyExistingObject;
}

//================================ DESTRUCTOR ================================//

Fixed::~Fixed(void){
		std::cout<<RED<< "Destructor called"<<RESET<< std::endl;
}

//================================= OVERLOAD =================================//

Fixed&	Fixed::operator=( const Fixed& rightSideOfOperator ){

	std::cout<<GREEN << "Copy assignment operator is called." <<RESET<< std::endl;
	if ( this == &rightSideOfOperator )
		return (*this);//check if they are already the same aka self-assignment
	this->_value = rightSideOfOperator.getRawBits();
	return *this;
}

//================================= ACCESSOR =================================//

void	Fixed::setRawBits(int const rawBits){
	std::cout<<BLUE<<"getRawBits member function called"<<RESET<< std::endl;
	_value = rawBits;
}

int		Fixed::getRawBits(void)const{
	std::cout<<BLUE<<"getRawBits member function called"<<RESET<< std::endl;
	return _value;
}
