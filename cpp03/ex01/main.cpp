/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 19:22:33 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/08/28 20:06:30 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

void test1()
{
	ScavTrap	whiteWalker("whiteWalker");
	ScavTrap	Hodor("Hodor");

	whiteWalker.attack("Hodor");
	Hodor.takeDamage(whiteWalker.getAttackDamage());
	whiteWalker.attack("Hodor");
	Hodor.takeDamage(whiteWalker.getAttackDamage());
	Hodor.beRepaired(10);
	Hodor.guardGate();
	std::cout<< Hodor<<std::endl;
	std::cout<< whiteWalker<<std::endl;
}

int	main(){

	test1();
}
