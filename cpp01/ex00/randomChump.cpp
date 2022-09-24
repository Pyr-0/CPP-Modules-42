/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 19:33:53 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/09/24 19:33:56 by mrojas-e         ###   ########.fr       */
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