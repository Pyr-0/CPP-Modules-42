/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 18:21:57 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/08/28 19:50:51 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"


//============================== CONSTRUCTOR ================================//

ClapTrap::ClapTrap():_name("Default ClapTrap"),_hitPoints(10), _attackDamage(0), _energyPoints(10){
	
	std::cout<<RED<< "Claptrap Default constructor called"<<RESET<< std::endl;
}

ClapTrap::ClapTrap(std::string name ): _name(name), _hitPoints(10), _attackDamage(0), _energyPoints(10){
	std::cout<<RED<< "Claptrap String constructor called"<<RESET<< std::endl;
	
}

ClapTrap::ClapTrap( const ClapTrap & src )
			: _name(src._name), _hitPoints(src._hitPoints), _attackDamage(src._attackDamage), _energyPoints(src._energyPoints){
	std::cout <<RED<< "Claptrap Copy constructor called"<< RESET<<std::endl;
}

//=============================== DESTRUCTOR ================================//

ClapTrap::~ClapTrap(){
	
	std::cout<<RED<< "Destructor called"<<RESET<< std::endl;
}

//================================ OVERLOAD =================================//

ClapTrap &			ClapTrap::operator=( ClapTrap const & rhs )
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

std::ostream &		operator<<( std::ostream & o, ClapTrap const & i )
{
	o <<GREEN<<ULINE<<"[STATUS REPORT]"<<RESET<<std::endl;
	o << "Name = " <<GREEN<< i.getName()<< RESET;
	o << " | Attack Damage = " << GREEN<< i.getAttackDamage()<<RESET;
	o << " | Energy Points = " << GREEN<< i.getenergyPoints()<<RESET;
	o << " | Hit Points = " <<GREEN<< i.gethitPoints()<<RESET;
	return o;
}

//================================ METHODS ==================================//
void ClapTrap::cannotDoTheThing() const{
	if (_hitPoints < 0)
		std::cout <<LILA<< "Claptrap "<< this->_name<< " IS DEAD! 💀" RESET<< std::endl;
	else if (_energyPoints <= 0)
		std::cout <<LILA<< "Claptrap "<< this->_name<< " HAS NO MORE ENERGY POINTS! ❌🔋" RESET<< std::endl;
}

void ClapTrap::attack (const std::string& target){
	
	if(_hitPoints > 0  &&_energyPoints > 0)
	{
		std::cout <<YLLW<< "Claptrap "<< this->_name<<" attacks "<< target<<" causing "<< _attackDamage << " points of damage! [⚔️💥]"<<RESET<< std::endl;
		_energyPoints--;
	}
	cannotDoTheThing();
}

void ClapTrap::beRepaired (unsigned int amount){

	if(_hitPoints > 0  && _energyPoints > 0)
	{
		std::cout <<BLUE<< "Claptrap "<< this->_name<< " repaired by "<< amount << " hit points! [➕💪]"<<RESET<< std::endl;
		_energyPoints--;
		_hitPoints += amount ;
	}
	cannotDoTheThing();
}

void ClapTrap::takeDamage (unsigned int amount){

	if(_hitPoints > 0)
	{
		std::cout <<LILA<< "Claptrap "<< this->_name<< " takes  "<< amount << " damage points! [➖❤️ ]"<<RESET<< std::endl;
		_hitPoints -= amount ;
	}
	cannotDoTheThing();
}

//================================ ACCESSOR =================================//

std::string ClapTrap::getName() const {
	return this->_name;
 }
 
int	ClapTrap::getAttackDamage() const {
	return this->_attackDamage;
 }
 
int	ClapTrap::gethitPoints() const {
	return this->_hitPoints;
 }
 
int	ClapTrap::getenergyPoints() const {
	return this->_energyPoints;
 }