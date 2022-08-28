/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 19:22:33 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/08/28 19:27:54 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

void 	test1()
{
	std::cout<<ULINE<<"First test, creating 3 ClapTraps and testing Raw functions\n"<<RESET<<std::endl;
	ClapTrap	victim;
	ClapTrap	clapTrap("Dude");
	ClapTrap 	claptrapCopy(clapTrap);

	clapTrap.attack(victim.getName());
	victim.takeDamage(clapTrap.getAttackDamage());
	victim.beRepaired(2);
	std::cout<< victim<< std::endl;
	std::cout<< clapTrap << std::endl;
}

void	test2()
{
	std::cout<<ULINE<<"Second test, test if Dead or out of energy\n"<<RESET<<std::endl;
	ClapTrap Thor("Thor");
	ClapTrap Loki("Loki");

	Thor.attack("Loki");
	Loki.takeDamage(3);
	Thor.attack("Loki");
	Loki.takeDamage(3);
	Thor.attack("Loki");
	Loki.takeDamage(3);
	Loki.beRepaired(1);
	Loki.beRepaired(1);
	Loki.beRepaired(1);
	Loki.beRepaired(1);
	Loki.beRepaired(1);
	Loki.beRepaired(1);
	Loki.beRepaired(1);
	Loki.beRepaired(1);
	Loki.beRepaired(1);
	Thor.beRepaired(2);
	std::cout<< Thor<< std::endl;
	std::cout<< Loki<< std::endl;
	Thor.attack("Loki");
	Loki.takeDamage(9);
	Loki.attack("Thor");
	Thor.attack("Loki");
	Loki.takeDamage(2);
	std::cout<< Thor<< std::endl;
	std::cout<< Loki<< std::endl;
}
int	main(){
	
	test1();
	//test2();
}
