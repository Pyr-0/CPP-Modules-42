/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 12:15:15 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/08/05 13:51:45 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>

//============COLORS!=======//
/*EASTEREGG is only visible in some Terminals ;) (Terminal instead of iTerm)*/
#define			RED "\e[31m"
#define			GREEN "\e[32m"
#define			RESET "\e[0m"
#define			EASTEREGG "\e[05m"

class	Zombie 
{
	private:

	std::string	name;

	public:

	Zombie(std::string name);
	~Zombie(void);

	void	announce(void);
};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

#endif
