/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 20:56:49 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/08/24 21:28:08 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"


//============================== CONSTRUCTOR ================================//

ScavTrap::ScavTrap():ClapTrap(){
	
	std::cout<<RED<< "ScavTrap constructor called"<<RESET<< std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	
}

ScavTrap::ScavTrap(std::string name ) :ClapTrap(name){
	std::cout<<RED<< "ScavTrap String constructor called"<<RESET<< std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

ScavTrap::ScavTrap( const ScavTrap & src ): ClapTrap(src){
	std::cout <<GREEN<< "ScavTrap Copy constructor called"<< RESET<<std::endl;
		this->_attackDamage = src._attackDamage;
		this->_energyPoints = src._energyPoints;
		this->_hitPoints = src._hitPoints;
		
}

//=============================== DESTRUCTOR ================================//

ScavTrap::~ScavTrap(){
	
	std::cout<<RED<< "ScavTrap Destructor called"<<RESET<< std::endl;
}

//================================ OVERLOAD =================================//

ScavTrap &				ScavTrap::operator=( ScavTrap const & rhs )
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

std::ostream &			operator<<( std::ostream & o, ScavTrap const & i )
{
	o << "Name = " << i.getName();
	o << "Attack Damage = " << i.getAttackDamage();
	o << "Energy Points = " << i.getenergyPoints();
	o << "Hit Points = " << i.gethitPoints();
	return o;
}
//================================ METHODS =================================//

void ScavTrap::attack (const std::string& target){
	
	if(this->_hitPoints > 0 && this->_energyPoints > 0)
	{
		std::cout <<YLLW<< "Scavtrap "<< this->_name<< " attacks "<< target<<" causing "<< this->_attackDamage << " points of damage!"<<RESET<< std::endl;
		this->_energyPoints--;
	}
}

void ScavTrap::guardGate(){
		std::cout <<YLLW<< "Scavtrap " << this->_name<< "is now in Gate Keeper Mode"<< std::endl;
}

