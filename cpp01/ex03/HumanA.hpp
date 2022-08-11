/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 12:15:15 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/08/11 18:28:52 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <iostream>
#include <Weapon.hpp>

//============COLORS!=======//
/*EASTEREGG is only visible in some Terminals ;) (Terminal instead of iTerm)*/
#define			RED "\e[31m"
#define			GREEN "\e[32m"
#define			RESET "\e[0m"
#define			EASTEREGG "\e[05m"

class	HumanA{
	private:

	Weapon	_weapon;
	std::string	_name;

	public:

	HumanA();
	~HumanA();

	const void attack(){
		std::cout<<RED<<this->_name<<" attacks with their "<< this->_weapon.getType();
	}
};

HumanA	*newHumanA(std::string name);
void	randomChump(std::string name);

#endif
