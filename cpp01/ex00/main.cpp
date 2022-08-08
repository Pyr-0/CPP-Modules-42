/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 22:36:21 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/08/06 21:31:06 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"


void func()
{
	Zombie	zombie("Zone-B");
	zombie.announce();
	Zombie	*undead;
	undead = newZombie("Sum-bee");
	(*undead).announce();
	randomChump("Son-bi");
	delete undead;
}

int	main()
{
	func();
	//system("leaks zombie");
}
