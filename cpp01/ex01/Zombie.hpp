/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 12:15:15 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/09/24 19:34:33 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <sstream>

//============COLORS!=======//
/*EASTEREGG is only visible in some Terminals ;) (Terminal instead of iTerm)*/
#define			RED "\e[31m"
#define			GREEN "\e[32m"
#define			RESET "\e[0m"
#define			EASTEREGG "\e[05m"

class	Zombie{
	private:

	std::string	_name;

	public:

	Zombie(void);
	~Zombie(void);

	void	announce(void)const;
	void	setName(std::string name, int i);
};

Zombie* zombieHorde(int N, std::string name);

#endif
