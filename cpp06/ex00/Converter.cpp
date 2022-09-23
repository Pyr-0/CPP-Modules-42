/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 07:34:31 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/09/23 22:24:04 by mrojas-e         ###   ########.fr       */
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

static int myIsnan(double x) { return x != x; }
static int myIsinf(double x) { return !myIsnan(x) && myIsnan(x - x); }

void Converter::print(void) const {

	std::cout << std::showpoint;//displays decimal value
	std::cout.setf(std::ios::fixed);//write floating-point values in fixed-point notation
	std::cout.precision(2);//write as many decimals as needed

	print_to_char();
	print_to_int();
	print_to_float();
	print_to_double();

	std::cout.unsetf(std::ios::fixed);//Flags must be unset
	std::cout.precision(2);
}

void	Converter::print_to_char(void) const {
	double value = get_value();

	std::cout << "char: ";
	if (myIsnan(value) || myIsinf(value))
		std::cout << "impossible" << std::endl;
	else if (not std::isprint(value))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
}

void Converter::print_to_int(void) const {
	double value = get_value();

	std::cout << "int: ";
	if (myIsnan(value) || myIsinf(value) )
		std::cout << "impossible" << std::endl;
	else if (value > std::numeric_limits<int>::max()
			|| value < std::numeric_limits<int>::lowest())
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(value) << std::endl;
}

void Converter::print_to_float(void) const {
	float value = static_cast<float>(get_value());

	if (myIsnan(value) || myIsinf(value)) {
		std::cout << std::showpos;
		std::cout << "float: " << value << "f" << std::endl;
		std::cout << std::noshowpos;
	}
	else
		std::cout << "float: " << value << "f" << std::endl;
}

void Converter::print_to_double(void) const {
	double value = get_value();

	if (myIsnan(value) || myIsinf(value)) {
		std::cout << std::showpos;
		std::cout << "double: " << value << std::endl;
		std::cout << std::noshowpos;
	}
	else
		std::cout << "double: " << value << std::endl;
}

bool	Converter::isChar(const std::string & input){
	if(std::isprint(input[0]) && input.length() == 1)
	{
		static_cast<double &>(value_) = input[0];
		return true;
	}
	return false;
}
