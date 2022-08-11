/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 13:37:17 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/08/08 17:14:10 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

//============CONSTRUCTOR=========//

Zombie::Zombie(void){}

//============DESTRUCTOR=========//

Zombie::~Zombie(void) {
	std::cout<<RED<< this->_name << " destroyed" <<RESET<< std::endl;
}

//============METHOD=========//

void	Zombie::announce(void)const{
	std::cout<<GREEN<<EASTEREGG<< this->_name <<" 🧟: BraiiiiiiinnnzzzZ..."<<RESET<< std::endl;
}

/*	This finction sets the name of the zombies while also
	enumerating them by basically storing the integer we
	have into a STREAM and the stream gets converted
	into a STRING for later be added on our original string
	(see lines 40-42)*/
void	Zombie::setName(std::string name, int i){
	i++;
	std::string s;

	std::ostringstream temp;
	temp << i;
	s = temp.str();
	
	name = name + " " + s;
	this->_name = name;
}
