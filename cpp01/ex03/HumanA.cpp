/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 13:37:17 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/08/12 20:47:24 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp" 
#include "Weapon.hpp"

//============CONSTRUCTOR=========//
HumanA::HumanA(std::string name, Weapon &weapon):_weapon(weapon),_name(name){
}
//============DESTRUCTOR=========//
HumanA::~HumanA(){}

//============METHOD=========//
void HumanA::attack(){
	std::cout<< GREEN << this->_name <<RED<<" attacks with their "
			 << LILA << this->_weapon.getType() << std::endl;
}