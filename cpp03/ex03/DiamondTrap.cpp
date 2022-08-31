/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 18:21:57 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/08/31 14:31:05 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

//============================== CONSTRUCTOR ================================//


DiamondTrap::DiamondTrap():ClapTrap(), FragTrap(), ScavTrap(){

	this->_name = getPrivateName();
	//ClapTrap::_name += "_clap_name";
	this->_hitPoints =  FragTrap(_name).gethitPoints();
	this->_energyPoints = ScavTrap(_name).getenergyPoints();
	this->_attackDamage = FragTrap(_name).getAttackDamage();
	std::cout <<RED<< "DiamondTrap "<< _name << " Default constructor called"<<RESET<< std::endl;
}

DiamondTrap::DiamondTrap(std::string name ): ClapTrap(name), FragTrap(name), ScavTrap(name), _name(name){
	ClapTrap::_name += "_clap_name";
	ClapTrap::_attackDamage = 30;
	std::cout<<RED<< "DiamondTrap "<<LILA<<this->_name<<RED<<" String constructor called"<<RESET<< std::endl;
}

DiamondTrap::DiamondTrap( const DiamondTrap & src ){
	*this = src;
	std::cout <<GREEN<< "DiamondTrap Copy constructor called"<< RESET<<std::endl;
}

//=============================== DESTRUCTOR ================================//

DiamondTrap::~DiamondTrap(){
	
std::cout<<RED<< "DiamondTrap "<<LILA<<this->_name<<RED<<" Destructor called"<<RESET<< std::endl;}

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
	o <<GREEN<<ULINE<<"\n[STATUS REPORT]"<<RESET<<std::endl;
	o <<ULINE<< "Name = " <<ULINE<<GREEN<< i.getPrivateName()<< RESET;
	o <<ULINE<< " | Attack Damage = " <<ULINE<< GREEN<< i.getAttackDamage()<<RESET;
	o <<ULINE<< " | Energy Points = " <<ULINE<< GREEN<< i.getenergyPoints()<<RESET;
	o <<ULINE<< " | Hit Points = " <<ULINE<<GREEN<< i.gethitPoints()<<RESET;
	return o;
}

//================================ METHODS ==================================//

void  DiamondTrap :: whoAmI () {
	std::cout <<ULINE<< "\nDiamondTrap name is " << this->_name << " and ClapTrap name is " << ClapTrap::_name <<"\n"<<RESET<<std::endl;
}
void DiamondTrap::cannotDoTheThing() const{
	if (_hitPoints < 0)
		std::cout <<LILA<< "DiamondTrap "<< this->_name<< " IS DEAD! 💀" RESET<< std::endl;
	else if (_energyPoints <= 0)
		std::cout <<LILA<< "DiamondTrap "<< this->_name<< " HAS NO MORE ENERGY POINTS! ❌🔋" RESET<< std::endl;
}

std::string DiamondTrap::getPrivateName() const {
	return this->_name;
}