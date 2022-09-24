/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 21:58:07 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/09/24 19:35:42 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

//============CONSTRUCTOR=========//
Weapon::Weapon(std::string weapon):_type(weapon){
}

//============DESTRUCTOR=========//
Weapon::~Weapon(){}

//============METHODS=========//

const std::string&	Weapon::getType(void){
	return this->_type;
}

void				Weapon::setType(std::string new_type){
	this->_type = new_type;
}
