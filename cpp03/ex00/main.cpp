/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 19:22:33 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/08/24 20:14:27 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(){

	ClapTrap	clapTrap("dude");
	ClapTrap	victim("bob");
	ClapTrap 	clapTrap2(clapTrap);
	
	clapTrap.attack(victim.getName());
	victim.takeDamage(clapTrap.getAttackDamage());
	std::cout<< victim << std::endl;
	victim.beRepaired(3);
	std::cout<< victim<< std::endl;
	
	clapTrap.attack(victim.getName());
	victim.takeDamage(clapTrap.getAttackDamage());
	std::cout<< victim << std::endl;
	victim.beRepaired(3);
	std::cout<< victim<< std::endl;
}
