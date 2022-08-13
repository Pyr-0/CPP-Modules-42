/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 12:15:15 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/08/12 21:02:10 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

//============COLORS!=======//
#define			RED "\e[31m"
#define			GREEN "\e[32m"
#define			LILA "\e[35m"
#define			RESET "\e[0m"

class	HumanB{
	private:

	Weapon	*_weapon;
	std::string	_name;

	public:

	HumanB();
	HumanB(std::string name);
	~HumanB();

	void attack();
	void setWeapon(Weapon &weapon);
};

#endif