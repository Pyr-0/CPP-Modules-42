/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 20:56:49 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/08/25 12:59:43 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"


//============================== CONSTRUCTOR ================================//

FragTrap::FragTrap():ScavTrap(){
	
	std::cout<<RED<< "ScavTrap constructor called"<<RESET<< std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::FragTrap(std::string name ) :ScavTrap(name){
	std::cout<<RED<< "FragTrap String constructor called"<<RESET<< std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::FragTrap( const FragTrap & src ): ScavTrap(src){
	std::cout <<GREEN<< "FragTrap Copy constructor called"<< RESET<<std::endl;
		this->_attackDamage = src._attackDamage;
		this->_energyPoints = src._energyPoints;
		this->_hitPoints = src._hitPoints;
		
}

//=============================== DESTRUCTOR ================================//

FragTrap::~FragTrap(){
	
	std::cout<<RED<< "FragTrap Destructor called"<<RESET<< std::endl;
}

//================================ OVERLOAD =================================//

FragTrap &				FragTrap::operator=( FragTrap const & rhs )
{
	if ( this != &rhs )
	{
		this->_name = rhs._name;
		this->_attackDamage = rhs._attackDamage;
		this->_energyPoints = rhs._energyPoints;
		this->_hitPoints = rhs._hitPoints;
		
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, FragTrap const & i )
{
	o << "Name = " << i.getName();
	o << " Attack Damage = " << i.getAttackDamage();
	o << " Energy Points = " << i.getenergyPoints();
	o << " Hit Points = " << i.gethitPoints();
	return o;
}
//================================ METHODS =================================//

void FragTrap::highFivesGuys(void){
		std::cout <<YLLW<< "Fragtrap "<< this->_name<< " Gives you a HIGH FIVE!!"<< std::endl;
}

