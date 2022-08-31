/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 19:22:33 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/08/31 14:33:53 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

void	test1()
{
	std::string s1 = "Darth Vader";
	std::string s2 = "Luke Skywalker";
	std::string s3 = "Obi-Wan Kenobi";
	std::string s4 = "Darth Maul";

	// Constructors
	std::cout<<GREEN<<ULINE<<"\n[CONSRUCTORS]\n"<<RESET<<std::endl;
	DiamondTrap	diamondtrap(s4);
	std::cout<< diamondtrap<<std::endl;

	// Repairs
	std::cout<<GREEN<<ULINE<<"\n[REPAIRS]\n"<<RESET<<std::endl;
	diamondtrap.takeDamage(14);
	diamondtrap.beRepaired(18);
	std::cout<< diamondtrap<<std::endl;

	// New class attack until exhaustion
	std::cout<<GREEN<<ULINE<<"\n[ATTACKS]\n"<<RESET<<std::endl;
	diamondtrap.attack(s2);
	diamondtrap.attack(s2);
	diamondtrap.attack(s2);
	diamondtrap.attack(s2);

	// New class personal method call or Special functions
	std::cout<<GREEN<<ULINE<<"\n[PERSONAL METHODS]\n"<<RESET<<std::endl;
	diamondtrap.guardGate();
	diamondtrap.highFivesGuys();

	//Who Am I
	std::cout<<GREEN<<ULINE<<"\n[WHO AM I]\n"<<RESET<<std::endl;
	diamondtrap.whoAmI();

	// Die
	diamondtrap.takeDamage(104);
	std::cout<< diamondtrap<<std::endl;
}

void	test2()
{
	DiamondTrap	a("Wall-E");
	a.whoAmI();
	
	DiamondTrap	b("Optimus Prime");
	DiamondTrap	c("Marvin");
	
	std::cout	<<	std::endl;
	
	b.whoAmI();
	c.whoAmI();
	c.highFivesGuys();
	
std::cout	<<	std::endl;
	
	b.attack("C");
	c.takeDamage(30);
	
std::cout	<<	std::endl;
	
	b.attack("C");
	c.takeDamage(30);
	
std::cout	<<	std::endl;
	
	b.guardGate();
	
std::cout << std::endl;
}

void	test3()
{
	ClapTrap ct;
	std::cout << std::endl;
	ScavTrap st;
	std::cout << std::endl;
	FragTrap ft;
	std::cout << std::endl;
	DiamondTrap dt;
	DiamondTrap dt2("test");
	std::cout << std::endl;
	std::cout << ct << "\n" << st << "\n" << ft << "\n" << dt <<  "\n" << dt2 << std::endl;
	std::cout << std::endl;
	dt2.whoAmI();
}
int	main(){

	test1();
	//test2();
	//test3();
}
