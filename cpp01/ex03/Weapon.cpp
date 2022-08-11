/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 21:58:07 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/08/06 23:43:39 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*	This function will create an array of elements in this case Zombies),
	but in the same way that we would with malloc, we must protect against NULL
	and free the created array at the end of our program*/
Zombie* zombieHorde(int N, std::string name)
{
	Zombie	*horde;
	
	horde = new Zombie[N];
	if(!horde)
		return NULL;
	for(int i = 0; i < N; i++){
		horde[i].setName(name, i);
	}
	return horde;
}