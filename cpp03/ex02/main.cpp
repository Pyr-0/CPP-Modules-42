/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 19:22:33 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/08/25 13:11:35 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int	main(){
	FragTrap thor("thor");
	FragTrap loki("loki");

	thor.attack("loki");
	loki.takeDamage(thor.getAttackDamage());
	thor.attack("loki");
	loki.takeDamage(thor.getAttackDamage());
	loki.beRepaired(10);
	thor.highFivesGuys();
	// FragTrap	fragTrap("dude");
	// FragTrap	victim("bob");
	// FragTrap 	fragTrap2(FragTrap);
	
	// fragTrap.attack(victim.getName());
	// victim.takeDamage(fragTrap.getAttackDamage());
	// std::cout<< victim << std::endl;
	// victim.beRepaired(3);
	// std::cout<< victim<< std::endl;
	
	// fragTrap.attack(victim.getName());
	// victim.takeDamage(fragTrap.getAttackDamage());
	// std::cout<< victim << std::endl;
	// victim.beRepaired(3);
	// std::cout<< victim<< std::endl;
	
	// fragTrap.highFivesGuys();
	
	// FragTrap thor("thor");
	// FragTrap loki("loki");


	// thor.attack("loki");
	// loki.takeDamage(thor.getAttackDamage());
	// thor.attack("loki");
	// loki.takeDamage(thor.getAttackDamage());
	// thor.attack("loki");
	// loki.takeDamage(thor.getAttackDamage());
	// thor.attack("loki");
	// loki.takeDamage(thor.getAttackDamage());
	// loki.beRepaired(2);
	// loki.attack("thor");
	// thor.takeDamage(loki.getAttackDamage());
	// thor.beRepaired(2);
	// thor.beRepaired(2);
	// thor.beRepaired(2);
	// thor.beRepaired(2);
	// thor.beRepaired(2);
	// thor.beRepaired(2);
	// thor.beRepaired(2);
}
