/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 19:34:00 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/09/24 19:34:03 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

//============CONSTRUCTOR=========//

Zombie::Zombie(std::string z_name):_name(z_name){}

//============DESTRUCTOR=========//

Zombie::~Zombie(void) {
	std::cout<<RED<< _name << " destroyed" <<RESET<< std::endl;
}

//============METHOD=========//

void	Zombie::announce(void){
	std::cout<<GREEN<< _name <<" 🧟: BraiiiiiiinnnzzzZ..."<<RESET<< std::endl;
}
