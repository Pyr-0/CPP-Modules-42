/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 19:22:33 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/08/25 12:34:07 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(){

	ClapTrap ct;
	
	std::cout << ct.getName() << std::endl;

	ScavTrap	scavTrap("dude");
	ScavTrap	victim("bob");
	ScavTrap 	scavTrap2(scavTrap);
	
	scavTrap.attack(victim.getName());
	victim.takeDamage(scavTrap.getAttackDamage());
	std::cout<< victim << std::endl;
	victim.beRepaired(3);
	std::cout<< victim<< std::endl;
	
	scavTrap.attack(victim.getName());
	victim.takeDamage(scavTrap.getAttackDamage());
	std::cout<< victim << std::endl;
	victim.beRepaired(3);
	std::cout<< victim<< std::endl;
	
	scavTrap.guardGate();
}