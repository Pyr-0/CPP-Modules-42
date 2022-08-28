/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 19:22:33 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/08/28 21:45:21 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

/*	Scavtrap and FragTrap are derived clases from ClapTrap
	therefore both their instances will inherit the functions 
	of its base class, and thats why they will all still be
	called Claptrap in the output */
void	test1()
{
	ClapTrap	clapTrap;
	ScavTrap	scavTrap("ScavTrap");
	FragTrap	fragTrap("FragTrap");
	
	clapTrap.attack("ScavTrap");
	fragTrap.attack("ScavTrap");
	scavTrap.attack("Bob");
	scavTrap.takeDamage(clapTrap.getAttackDamage());
	scavTrap.takeDamage(fragTrap.getAttackDamage());
	scavTrap.takeDamage(fragTrap.getAttackDamage());
	scavTrap.takeDamage(fragTrap.getAttackDamage());
	scavTrap.takeDamage(fragTrap.getAttackDamage());
	fragTrap.highFivesGuys();
	std::cout<< clapTrap<<std::endl;
	std::cout<< scavTrap<<std::endl;
	std::cout<< fragTrap<<std::endl;
}

void	test2()
{
	FragTrap	clapTrap("clapTrap");
	FragTrap	fragTrap("fragTrap");

	clapTrap.attack("fragTrap");
	fragTrap.takeDamage(clapTrap.getAttackDamage());
	clapTrap.attack("fragTrap");
	fragTrap.takeDamage(clapTrap.getAttackDamage());
	fragTrap.beRepaired(10);
	clapTrap.highFivesGuys();
	std::cout<< clapTrap<<std::endl;
	std::cout<< fragTrap<<std::endl;
}
int	main(){

	test1();
	//test2();
}
