/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 12:15:15 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/08/18 16:41:50 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP


#include "Weapon.hpp"

//============COLORS!=======//
#define			RED "\e[31m"
#define			GREEN "\e[32m"
#define			LILA "\e[35m"
#define			RESET "\e[0m"

class	HumanA{
	private:

	Weapon	&_weapon;
	std::string	_name;

	public:

	HumanA(std::string name, Weapon &weapon);
	~HumanA();

	void attack();
};

HumanA	*newHumanA(std::string name);
void	randomChump(std::string name);

#endif