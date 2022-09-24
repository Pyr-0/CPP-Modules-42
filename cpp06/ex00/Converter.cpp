/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 07:34:31 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/09/24 17:00:35 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Converter.hpp"
//====================== CONSTRUCTORS =====================//

Converter::Converter( const std::string &input)
	: input_(input), value_(0.0){

	try {
		if (isChar(input))
			return ;
		static_cast<double &>(value_) = std::stod(input, NULL);
	}
	catch (std::exception &e) {
		throw e;
	}
}

Converter::~Converter(void) {}

//====================== ACCESSORS =====================//

const std::string &Converter::get_input(void) const { return input_; }

const double& Converter::get_value(void) const { 
	return value_; }

//====================== METHODS =====================//

static int myIsnan(double x) { return x != x; }//checks if its not a Number
static int myIsinf(double x) { return !myIsnan(x) && myIsnan(x - x); }//check if its an infinite number

void	Converter::print(void) const {

	std::cout << std::showpoint;//displays decimal value
	std::cout.setf(std::ios::fixed);//write floating-point values in fixed-point notation
	std::cout.precision(2);//write as many decimals as needed

	printToChar();
	printToInt();
	printToFloat();
	printToDouble();

	std::cout.unsetf(std::ios::fixed);//Flags must be unset
	std::cout.precision(2);
}

void	Converter::printToChar(void) const {
	double value = get_value();

	std::cout << YLLW<<"char: "<<RESET;
	if (myIsnan(value) || myIsinf(value))
		std::cout << RED<<"impossible" <<RESET<< std::endl;
	else if (! std::isprint(value))
		std::cout<<RED << "Non displayable" <<RESET<<std::endl;
	else
		std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
}

void	Converter::printToInt(void) const {
	double value = get_value();

	std::cout<<YLLW << "int: "<<RESET;
	if (myIsnan(value) || myIsinf(value) )
		std::cout << RED<<"impossible" <<RESET<< std::endl;
	else if (value > std::numeric_limits<int>::max()
			|| value < std::numeric_limits<int>::lowest())
		std::cout << RED<<"impossible" <<RESET<< std::endl;
	else
		std::cout << static_cast<int>(value) << std::endl;
}

void	Converter::printToFloat(void) const {
	float value = static_cast<float>(get_value());

	if (myIsnan(value) || myIsinf(value)) {
		std::cout << std::showpos;
		std::cout << YLLW<<"float: " <<RESET<< value << "f" << std::endl;
		std::cout << std::noshowpos;
	}
	else
		std::cout << YLLW<<"float: " <<RESET<< value << "f" << std::endl;
}

void	Converter::printToDouble(void) const {
	double value = get_value();

	if (myIsnan(value) || myIsinf(value)) {
		std::cout << std::showpos;
		std::cout << YLLW<<"double: " <<RESET<< value << std::endl;
		std::cout << std::noshowpos;
	}
	else
		std::cout << YLLW<<"double: " <<RESET<< value << std::endl;
}

bool	Converter::isChar(const std::string & input){
	if(std::isprint(input[0]) && input.length() == 1)
	{
		if(isdigit(input.c_str()[0]))
			static_cast<double &>(value_) = stoi(input);
		else 
			static_cast<double &>(value_) = input[0];
		return true;
	}
	return false;
}
