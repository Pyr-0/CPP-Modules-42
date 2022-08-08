/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 13:53:25 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/08/05 14:58:41 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Zombie.hpp"

/*	This function simply creates and allocates in the HEAP a
	"new" data-type, in this case a new Zombie, which means
	we have to free the memory when we are done using it */
Zombie *newZombie(std::string name){
	Zombie	*undead;
	
	undead = new Zombie(name);
	return (undead);
}