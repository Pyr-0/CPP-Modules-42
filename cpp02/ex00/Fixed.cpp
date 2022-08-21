/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 17:52:21 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/08/21 17:03:35 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//===================== CONSTRUCTOR ======================//

Fixed::Fixed(): _value(0){
	std::cout <<GREEN<< "Default constructor called"<< std::endl;
}

//===================== COPY CONSTRUCTOR ======================//

Fixed::Fixed( const Fixed &alreadyExistingObject ): *this(alreadyExistingObject){

	std::cout <<GREEN<< "Copy constructor called"<< std::endl;
}



//================================ DESTRUCTOR ================================//

Fixed::~Fixed(void){
		std::cout << "Destructor called"<< std::endl;
}

//================================= OVERLOAD =================================//

Fixed&	Fixed::operator=( const Fixed& rightSideOfOperator ){

	std::cout << "Copy assignment operator is called." << std::endl;
	if ( this == &rightSideOfOperator )
		return (*this);//check if they are already the same aka self-assignment
	this->_fpvalue = righhtSideOfOperator.getRawBits();
	return *this;
}

//================================= ACCESSOR =================================//

