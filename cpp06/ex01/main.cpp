/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 09:12:46 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/09/24 19:05:09 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

void	test1(){

	Data	data1;

	// serialize
	uintptr_t	test = serialize(&data1);

	// deserialize
	Data	*data2 = deserialize(test);
	std::cout << std::endl;

	// Result should be the same!
	// (Serialization/deserialization keep the same value inside data and same address)
	data1.char_= 'a';
	std::cout<<GREEN << "ADRESSES COMPARED:" <<RESET<< std::endl;
	std::cout<<GREEN << "----------------------------" <<RESET<< std::endl;
	std::cout<<GREEN << "Data1 address: "<< RED<<&data1 <<RESET<< std::endl;
	std::cout<<GREEN << "Data2 address: "<<RED<< data2 <<RESET<< std::endl;
	std::cout << std::endl;

	std::cout<<GREEN << "VALUES INSIDE DATA COMPARED:"<<RESET<< std::endl;
	std::cout<<GREEN << "----------------------------" <<RESET<< std::endl;
	std::cout<<GREEN << "Data1 value: "<< YLLW<< data1.char_ <<RESET<<std::endl;
	std::cout<<GREEN << "Data2 value: "<<YLLW<< (*data2).char_ <<RESET<< std::endl;
	std::cout << std::endl;
}

void	test2(){

	Data		obj;
	Data*		result;
	uintptr_t	any = 0;
	
	obj.string_ = "String";
	obj.int_= 42;
	obj.char_= 'a';

	// serialize
	any = serialize(&obj);

	// deserialize
	result = deserialize(any);
	std::cout << std::endl;
	std::cout<<GREEN << "VALUES FROM DESERIALIZING:"<<RESET<< std::endl;
	std::cout<<GREEN << "----------------------------" <<RESET<< std::endl;
	std::cout <<GREEN<< obj.char_<<RESET<<std::endl;
	std::cout <<GREEN<< obj.int_<<RESET<<std::endl;
	std::cout <<GREEN<< obj.string_<<RESET<<std::endl;
	
	std::cout << std::endl;
	std::cout<<GREEN << "VALUES FROM DESERIALIZING:"<<RESET<< std::endl;
	std::cout<<GREEN << "----------------------------" <<RESET<< std::endl;
	std::cout <<RED<< result->char_<<RESET<<std::endl;
	std::cout <<RED<< result->int_<<RESET<<std::endl;
	std::cout <<RED<< result->string_<<RESET<<std::endl;
	std::cout << std::endl;
}

int main() {

	//test1();
	test2();

}