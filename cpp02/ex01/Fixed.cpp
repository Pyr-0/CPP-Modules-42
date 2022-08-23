/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 17:52:21 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/08/23 20:40:38 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//===================== CONSTRUCTORS ======================//

Fixed::Fixed(): _value(0){
	std::cout <<YLLW<< "Default constructor called"<<RESET<< std::endl;
}

Fixed(const int i){ //making fixed points out of an int
	std::cout << "Int constructor called\n";
	this->_value = i << _nb_fractional_bits;

}
Fixed(const float f){//making fixed points out of an float
	std::cout << "Float constructor called\n";
	this->_value = roundf(f * (float)(1 << _nb_fractional_bits));
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

std::ostream &			operator<<( std::ostream & output, Fixed const & input )
{
	output << "Value = " << input.toFloat();
	return output;
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

//================================= METHODS=================================//


int		toInt(void){
	int	ret;

	ret = _fvalue / (1 << _nb_fractional_bits);
	return ret;
}
float	toFloat(void){
	float	ret;
	
	ret = (float)_value / (float)(1 << _nb_fractional_bits)
	return ret
}