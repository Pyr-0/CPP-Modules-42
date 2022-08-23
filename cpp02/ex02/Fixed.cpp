/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 17:52:21 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/08/24 00:33:47 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//===================== CONSTRUCTORS ======================//

Fixed::Fixed(): _value(0){
	std::cout <<YLLW<< "Default constructor called"<<RESET<< std::endl;
}

Fixed::Fixed(const int i){ //making fixed points out of an int
	std::cout << "Int constructor called"<< std::endl;
	this->_value = i << this->_nFractionalBits;
}

Fixed::Fixed(const float f){//making fixed points out of an float
	std::cout << "Float constructor called";
	this->_value = roundf(f * (float)(1 << _nFractionalBits));
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

//================================= METHODS=================================//


int Fixed::toInt(void)const{
	int	ret;

	ret = _value / (1 << _nFractionalBits);
	return ret;
}
float	Fixed::toFloat(void)const{
	float	ret;
	
	ret = (float)_value / (float)(1 << _nFractionalBits);
	return ret;
}

//================================= OVERLOAD =================================//

Fixed&	Fixed::operator=( const Fixed & rightSideOfOperator ){

	std::cout<<GREEN << "Copy assignment operator  overload is called." <<RESET<< std::endl;
	if ( this == &rightSideOfOperator )
		return (*this);//check if they are already the same aka self-assignment
	this->_value = rightSideOfOperator.getRawBits();
	return *this;
}

std::ostream &			operator<<( std::ostream & output, Fixed const & i )
{
	output << "Value = " << i.toFloat();
	return output;
}

bool	Fixed::operator>( Fixed const& rhs ) const{

	return (this->toFloat() > rhs.toFloat());
}

bool	Fixed::operator<( Fixed const& rhs ) const{

	return (this->toFloat() < rhs.toFloat());
}

bool	Fixed::operator>=( Fixed const& rhs ) const{

	return (this->toFloat() >= rhs.toFloat());
}

bool	Fixed::operator<=( Fixed const& rhs ) const{

	return (this->toFloat() <= rhs.toFloat());
}

bool	Fixed::operator==( Fixed const& rhs ) const{

	return (this->toFloat() == rhs.toFloat());
}

bool	Fixed::operator!=( Fixed const& rhs ) const{

	return (this->toFloat() != rhs.toFloat());
}

Fixed	Fixed::operator+( Fixed const& rhs ) const{

	return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed	Fixed::operator-( Fixed const& rhs ) const{

	return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed	Fixed::operator*( Fixed const& rhs ) const{

	return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed	Fixed::operator/( Fixed const& rhs ) const{

	return Fixed(this->toFloat() / rhs.toFloat());
}

Fixed&	Fixed::operator++(){

	this->_value++;
	return *this;
}

Fixed&	Fixed::operator--(){

	this->_value--;
	return *this;
}

Fixed	Fixed::operator++(int){

	Fixed tmp(*this);
	this->operator++();
	return (tmp);
}//post

Fixed	Fixed::operator--(int){

	Fixed tmp(*this);
	this->operator--();
	return (tmp);
}//post

/*
** --------------------------------- METHODS ----------------------------------
*/

Fixed&	Fixed::min( Fixed &lhs, Fixed& rhs ){

	if (lhs < rhs)
		return lhs;
	else
		return rhs;
}

Fixed const&	Fixed::min( Fixed const&lhs, Fixed const& rhs ){

	if (lhs < rhs)
		return lhs;
	else
		return rhs;
}

Fixed&	Fixed::max( Fixed &lhs, Fixed& rhs ){

	if (lhs > rhs)
		return lhs;
	else
		return rhs;
}

Fixed const&	Fixed::max( Fixed const&lhs, Fixed const& rhs ){

	if (lhs > rhs)
		return lhs;
	else
		return rhs;
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
