/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 17:52:21 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/08/24 17:34:29 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//===================== CONSTRUCTORS ============================//

Fixed::Fixed(): _value(0){
	std::cout <<YLLW<< "Default constructor called"<<RESET<< std::endl;
}

/* making fixed points out of a int */
Fixed::Fixed(const int i){
	std::cout <<BLUE<< "Int"<<RESET<<" constructor called"<< std::endl;
	this->_value = i << this->_nFractionalBits;
}

/* making fixed points out of a float */
Fixed::Fixed(const float f){
	std::cout <<LILA<< "Float"<<RESET<<" constructor called"<< std::endl;
	this->_value = roundf(f * (float)(1 << _nFractionalBits));
}

//===================== COPY CONSTRUCTOR ======================//
Fixed::Fixed( const Fixed &alreadyExistingObject ){

	std::cout <<GREEN<< "Copy constructor called"<< RESET<<std::endl;
	*this = alreadyExistingObject;
}

//===================== DESTRUCTOR ===========================//

Fixed::~Fixed(void){
		std::cout<<RED<< "Destructor called"<<RESET<< std::endl;
}

//===================== METHODS=============================//


int				Fixed::toInt(void)const{
	int	ret;

	ret = _value / (1 << _nFractionalBits);
	return ret;
}
float			Fixed::toFloat(void)const{
	float	ret;
	
	ret = (float)_value / (float)(1 << _nFractionalBits);
	return ret;
}

//==================== OVERLOAD ============================//

Fixed&			Fixed::operator=( const Fixed & rightSideOfOperator ){

	std::cout<<GREEN << "Copy assignment operator  overload is called." <<RESET<< std::endl;
	if ( this == &rightSideOfOperator )
		return (*this);//check if they are already the same aka self-assignment, basically a guard
	this->_value = rightSideOfOperator.getRawBits();
	return *this;
}

std::ostream&	operator<<( std::ostream & output, Fixed const & i )
{
	output << "Value = " << i.toFloat();
	return output;
}

//=================== ACCESSOR ============================//

void			Fixed::setRawBits(int const rawBits){
	std::cout<<BLUE<<"getRawBits member function called"<<RESET<< std::endl;
	_value = rawBits;
}	

int				Fixed::getRawBits(void)const{
	std::cout<<BLUE<<"getRawBits member function called"<<RESET<< std::endl;
	return _value;
}
