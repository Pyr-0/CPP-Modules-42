/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 21:58:07 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/08/13 15:58:49 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include "Weapon.hpp"


//============CONSTRUCTOR=========//
HumanB::HumanB(std::string name):_name(name){
}

//============DESTRUCTOR=========//
HumanB::~HumanB(){}

//============METHOD=========//
void HumanB::attack(){
	std::cout<< GREEN << this->_name <<RED<<" attacks with their "
			 << LILA << this->_weapon->getType() << std::endl;
}
void HumanB::setWeapon(Weapon &weapon){
		this->_weapon = &weapon;
}
