/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 20:56:49 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/08/28 19:05:18 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"


//============================== CONSTRUCTOR ================================//

FragTrap::FragTrap():ClapTrap(){
	
	std::cout<<RED<< "FragTrap constructor called"<<RESET<< std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::FragTrap(std::string name ) :ClapTrap(name){
	std::cout<<RED<< "FragTrap String constructor called"<<RESET<< std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::FragTrap( const FragTrap & src ): ClapTrap(src){
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

std::ostream &		operator<<(std::ostream & o, FragTrap const & i)
{
	o <<GREEN<<ULINE<<"[STATUS REPORT]"<<RESET<<std::endl;
	o << "Name = " <<GREEN<< i.getName()<< RESET;
	o << " | Attack Damage = " << GREEN<< i.getAttackDamage()<<RESET;
	o << " | Energy Points = " << GREEN<< i.getenergyPoints()<<RESET;
	o << " | Hit Points = " <<GREEN<< i.gethitPoints()<<RESET;
	return o;
}

//================================ METHODS =================================//

void FragTrap::highFivesGuys(void){
		std::cout <<BLUE<< "Fragtrap "<< this->_name<< " Gives you a HIGH FIVE!! ✋"<< std::endl;
}
