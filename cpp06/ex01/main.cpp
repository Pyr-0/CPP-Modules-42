/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 09:12:46 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/09/23 22:47:21 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

int main() {
	
	// Data		obj;
	// Data*		result;
	// uintptr_t	any;
	
	// obj.string_ = "String";
	// obj.int_= 42;
	// obj.char_= 'a';

	// std::cout <<GREEN<< obj.char_<<RESET<<std::endl;
	// std::cout <<GREEN<< obj.int_<<RESET<<std::endl;
	// std::cout <<GREEN<< obj.string_<<RESET<<std::endl;
	
	// std::cout <<RED<< result->char_<<RESET<<std::endl;
	// std::cout <<RED<< result->int_<<RESET<<std::endl;
	// std::cout <<RED<< result->string_<<RESET<<std::endl;
	Data	data1;

	// serialize
	uintptr_t	test = serialize(&data1);

	// deserialize
	Data	*data2 = deserialize(test);
	std::cout << std::endl << std::endl;

	// Result should be the same!
	// (Serialization/deserialization keep the same value inside data and same address)

	data1.char_= 'a';
	std::cout << "ADRESSES COMPARED:" << std::endl;
	std::cout << "----------------------------" << std::endl;
	std::cout << "Data1 address: "<< &data1 << std::endl;
	std::cout << "Data2 address: "<< data2 << std::endl;
	std::cout << std::endl << std::endl;

	std::cout << "VALUES INSIDE DATA COMPARED:" << std::endl;
	std::cout << "----------------------------" << std::endl;
	std::cout << "Data1 value: " << data1.char_<< std::endl;
	std::cout << "Data2 value: " << (*data2).char_ << std::endl;
	std::cout << std::endl << std::endl;

}