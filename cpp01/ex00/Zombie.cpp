/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 13:37:17 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/08/13 18:08:51 by mrojas-e         ###   ########.fr       */
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
