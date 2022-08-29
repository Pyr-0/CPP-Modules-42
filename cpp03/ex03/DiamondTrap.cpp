/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 18:21:57 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/08/29 16:34:28 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

//============================== CONSTRUCTOR ================================//


DiamondTrap::DiamondTrap():ClapTrap(), FragTrap(), ScavTrap(), _name(ClapTrap::_name){

	ClapTrap::_name += "_clap_name";
	ClapTrap::_attackDamage = 30;
	/* this->_name = getName(); //or this _name = "diamondtrap_default_name";
	this->_hitPoints =  FragTrap(_name).gethitPoints();
	this->_energyPoints = ScavTrap(_name).getenergyPoints();
	this->_attackDamage = FragTrap(_name).getAttackDamage(); */
	std::cout <<RED<< "DiamondTrap "<< _name << " Default constructor called"<<RESET<< std::endl;
	// std::cout <<RED<< "DiamondTrap Default constructor called"<<RESET<< std::endl; ?? 
}

DiamondTrap::DiamondTrap(std::string name ): ClapTrap(name), FragTrap(name), ScavTrap(name), _name(name){
	ClapTrap::_name += "_clap_name";
	ClapTrap::_attackDamage = 30;
	std::cout <<RED<< "DiamondTrap "<< _name << " String constructor called"<<RESET<< std::endl;
}

DiamondTrap::DiamondTrap( const DiamondTrap & src ){
	*this = src;
	std::cout <<GREEN<< "DiamondTrap Copy constructor called"<< RESET<<std::endl;
}

//=============================== DESTRUCTOR ================================//

DiamondTrap::~DiamondTrap(){
	
	std::cout<<RED<< "DiamondTrap" << this->_name<<" Destructor called"<<RESET<< std::endl;
}

//================================ OVERLOAD =================================//

DiamondTrap&			DiamondTrap::operator=( DiamondTrap const & rhs )
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

std::ostream &		operator<<( std::ostream & o, DiamondTrap const & i )
{
	o <<GREEN<<ULINE<<"[STATUS REPORT]"<<RESET<<std::endl;
	o << "Name = " <<GREEN<< i.getName()<< RESET;
	o << " | Attack Damage = " << GREEN<< i.getAttackDamage()<<RESET;
	o << " | Energy Points = " << GREEN<< i.getenergyPoints()<<RESET;
	o << " | Hit Points = " <<GREEN<< i.gethitPoints()<<RESET;
	return o;
}

//================================ METHODS ==================================//

void  DiamondTrap :: whoAmI () {
	std::cout << "DiamondTrap name is " << this->_name << " and ClapTrap name is " << ClapTrap::_name << std::endl;
}
void DiamondTrap::cannotDoTheThing() const{
	if (_hitPoints < 0)
		std::cout <<LILA<< "DiamondTrap "<< this->_name<< " IS DEAD! 💀" RESET<< std::endl;
	else if (_energyPoints <= 0)
		std::cout <<LILA<< "DiamondTrap "<< this->_name<< " HAS NO MORE ENERGY POINTS! ❌🔋" RESET<< std::endl;
}

void DiamondTrap::attack (const std::string& target){
	
	if(_hitPoints > 0  &&_energyPoints > 0)
	{
		std::cout <<YLLW<< "DiamondTrap "<< this->_name<<" attacks "<< target<<" causing "<< _attackDamage << " points of damage! [⚔️💥]"<<RESET<< std::endl;
		_energyPoints--;
	}
	cannotDoTheThing();
}

void DiamondTrap::beRepaired (unsigned int amount){

	if(_hitPoints > 0  && _energyPoints > 0)
	{
		std::cout <<BLUE<< "DiamondTrap "<< this->_name<< " repaired by "<< amount << " hit points! [➕💪]"<<RESET<< std::endl;
		_energyPoints--;
		_hitPoints += amount ;
	}
	cannotDoTheThing();
}

void DiamondTrap::takeDamage (unsigned int amount){

	if(_hitPoints > 0)
	{
		std::cout <<LILA<< "DiamondTrap "<< this->_name<< " takes  "<< amount << " damage points! [➖❤️ ]"<<RESET<< std::endl;
		_hitPoints -= amount ;
	}
	cannotDoTheThing();
}


//================================ ACCESSOR =================================//

 std::string DiamondTrap::getName() const {
	return this->_name;
}

int	DiamondTrap::getAttackDamage() const {
	return this->_attackDamage;
}

int	DiamondTrap::gethitPoints() const {
	return this->_hitPoints;
}

int	DiamondTrap::getenergyPoints() const {
	return this->_energyPoints;
}