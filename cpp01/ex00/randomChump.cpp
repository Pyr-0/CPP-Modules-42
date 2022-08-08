/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 14:10:54 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/08/05 14:57:46 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*	This only creates a new instance of a Zombie, and makes
	use of the Class method as well, but this new instace
	will be allocated in the STACK instead */
void	randomChump(std::string name){
	Zombie	undead(name);
	undead.announce();
}