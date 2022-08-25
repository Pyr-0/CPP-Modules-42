/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 18:21:57 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/08/25 12:59:10 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

//============================== CONSTRUCTOR ================================//

ClapTrap::ClapTrap():_name("undefined"),_hitPoints(10), _attackDamage(0), _energyPoints(10){
	
	std::cout<<RED<< "ClapTrap constructor called"<<RESET<< std::endl;
}

ClapTrap::ClapTrap(std::string name ): _name(name), _hitPoints(10), _attackDamage(0), _energyPoints(10){
	std::cout<<RED<< "ClapTrap String constructor called"<<RESET<< std::endl;
	
}

ClapTrap::ClapTrap( const ClapTrap & src )
			: _name(src._name + "copy"), _hitPoints(src._hitPoints), _attackDamage(src._attackDamage), _energyPoints(src._energyPoints){
	std::cout <<GREEN<< "ScavTrap Copy constructor called"<< RESET<<std::endl;
}

//=============================== DESTRUCTOR ================================//

ClapTrap::~ClapTrap(){
	
	std::cout<<RED<< "ClapTrap Destructor called"<<RESET<< std::endl;
}

//================================ OVERLOAD =================================//

ClapTrap&				ClapTrap::operator=( ClapTrap const & rhs )
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
	o << "Name = " << i.getName();
	o << " Attack Damage = " << i.getAttackDamage();
	o << " Energy Points = " << i.getenergyPoints();
	o << " Hit Points = " << i.gethitPoints();
	return o;
}

//================================ METHODS ==================================//

void ClapTrap::attack (const std::string& target){
	
	if(_hitPoints > 0 && _energyPoints > 0)
	{
		std::cout <<YLLW<< "Claptrap "<< this->_name<< " attacks "<< target<<" causing "<< _attackDamage << " points of damage!"<<RESET<< std::endl;
		_energyPoints--;
	}
}

void ClapTrap::beRepaired (unsigned int amount){

	if(_hitPoints > 0 && _energyPoints > 0)
	{
		std::cout <<YLLW<< "Claptrap "<< this->_name<< " repaired by "<< amount << " hit points!"<<RESET<< std::endl;
		_energyPoints--;
		_hitPoints += amount ;
	}
}

void ClapTrap::takeDamage (unsigned int amount){

	if(_hitPoints > 0)
	{
		std::cout <<YLLW<< "Claptrap "<< this->_name<< " takes  "<< amount << " damage points!"<<RESET<< std::endl;
		_hitPoints -= amount ;
	}
}

//================================ ACCESSOR =================================//

 std::string ClapTrap::getName() const {
	return this->_name;
 }
unsigned int	ClapTrap::getAttackDamage() const {
	return this->_attackDamage;
 }
unsigned int	ClapTrap::gethitPoints() const {
	return this->_hitPoints;
 }
unsigned int	ClapTrap::getenergyPoints() const {
	return this->_energyPoints;
 }