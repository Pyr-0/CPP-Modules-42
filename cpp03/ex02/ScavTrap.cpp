/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 20:56:49 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/08/28 21:32:47 by mrojas-e         ###   ########.fr       */
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

std::ostream &		operator<<( std::ostream & o, ScavTrap const & i )
{
	o <<GREEN<<ULINE<<"[STATUS REPORT]"<<RESET<<std::endl;
	o << "Name = " <<GREEN<< i.getName()<< RESET;
	o << " | Attack Damage = " << GREEN<< i.getAttackDamage()<<RESET;
	o << " | Energy Points = " << GREEN<< i.getenergyPoints()<<RESET;
	o << " | Hit Points = " <<GREEN<< i.gethitPoints()<<RESET;
	return o;
}
//================================ METHODS =================================//

void ScavTrap::cannotDoTheThing() const{
	if (_hitPoints < 0)
		std::cout <<LILA<< "Scavtrap "<< this->_name<< " IS DEAD! 💀" RESET<< std::endl;
	else if (_energyPoints <= 0)
		std::cout <<LILA<< "Scavtrap "<< this->_name<< " HAS NO MORE ENERGY POINTS! ❌🔋" RESET<< std::endl;
}

void ScavTrap::attack (const std::string& target){
	
	if(_hitPoints > 0  &&_energyPoints > 0)
	{
		std::cout <<YLLW<< "ScavTrap "<< this->_name<<" attacks "<< target<<" causing "<< _attackDamage << " points of damage! [⚔️💥]"<<RESET<< std::endl;
		_energyPoints--;
	}
	cannotDoTheThing();
}

void ScavTrap::guardGate(){
		std::cout <<BLUE<< "Scavtrap " << this->_name<< " is now in Gate Keeper Mode 🚪"<< std::endl;
}
