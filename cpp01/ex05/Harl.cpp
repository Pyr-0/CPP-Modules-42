/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 19:28:42 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/08/19 20:25:13 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(){}
Harl::~Harl(){}
void	Harl::debug(void){
	std::cout<< "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" 
			 << std::endl;
}
void	Harl::info(void){
	std::cout<<"I cannot believe adding extra bacon costs more money."
			 <<"You didn't putenough bacon in my burger! If you did, I wouldn't be asking for more!"
			 << std::endl;
}
void	Harl::warning(void){
	std::cout<< "I think I deserve to have some extra bacon for free. I've been coming for"
			 <<"years whereas you started working here since last month."
			 << std::endl;
}
void	Harl::error(void){
	std::cout<< "This is unacceptable! I want to speak to the manager now."
			 << std::endl;
}

void	Harl::complain(std::string word){
	//string Array
	
	std::string string_array[] ={"debug", "info", "warning", "error"};
	
	//function Array
	void	(Harl::*function_array[])() = {
		
		&Harl::debug,		//adress of func stored at position 0 of array
		&Harl::info,		//adress of func stored at position 1 of array
		&Harl::warning,		//adress of func stored at position 2 of array
		&Harl::error		//adress of func stored at position 3 of array
	};
	
	//iteration logic 
	
	for(int i = 0; i < 4; i++){
		if(string_array[i] == word)
		{
			(this->*function_array[i])();
			return ;
		}
	}
	std::cout << "Nothing to complain about." <<std::endl;
}

