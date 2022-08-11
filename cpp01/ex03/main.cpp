/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 22:36:21 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/08/06 23:45:15 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	func()
{
	Zombie	*horde;
	
	horde = NULL;
	horde = zombieHorde(15, "Moar");
	for(int i = 0; i < 15; i++){
		horde[i].announce();
	}
	delete [] horde;
}

int	main(void)
{

	func();
	//system("leaks zombie");
	return 0;
}
