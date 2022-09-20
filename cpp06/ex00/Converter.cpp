/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 07:34:31 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/09/20 19:17:12 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Converter.hpp"

Converter::Converter(const std::string &input)
	: input_(input), value_(0.0)
{
	try {
		
	std::cout << "1 "  << value_ << std::endl;
	std::cout << "input "  << input.c_str() << std::endl;
		
		const_cast<double &>(value_) = strtod(input.c_str(), 0);
	std::cout << "2 "  << value_ << std::endl;
		
	} catch (std::exception &e) {
		throw e;
	}
}
Converter::~Converter(void) {}

const std::string &Converter::get_input(void) const { return input_; }

const double& Converter::get_value(void) const { 
	std::cout << "whats happening here "  << value_ << std::endl;
	return value_; }

void Converter::print(void) const {

	std::cout << std::showpoint;
	std::cout.setf(std::ios::fixed);
	std::cout.precision(1);

	print_to_char();
	print_to_int();
	print_to_float();
	print_to_double();

	std::cout.unsetf(std::ios::fixed);
	std::cout.precision(6);
}

static int myIsnan(double x) { return x != x; }
static int myIsinf(double x) { return !myIsnan(x) && myIsnan(x - x); }

void Converter::print_to_char(void) const {
	double value = get_value();
	std::cout << value << std::endl;

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
	if (myIsnan(value) || myIsinf(value))
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