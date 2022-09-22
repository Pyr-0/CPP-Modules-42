/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 09:12:46 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/09/21 13:42:06 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

int main() {
	
	Data		obj;
	Data*		result;
	uintptr_t	any;
	
	obj.string_ = "String";
	obj.int_= 42;
	obj.char_= 'a';

	std::cout <<GREEN<< obj.char_<<RESET<<std::endl;
	std::cout <<GREEN<< obj.int_<<RESET<<std::endl;
	std::cout <<GREEN<< obj.string_<<RESET<<std::endl;
	
	std::cout <<RED<< result->char_<<RESET<<std::endl;
	std::cout <<RED<< result->int_<<RESET<<std::endl;
	std::cout <<RED<< result->string_<<RESET<<std::endl;
}