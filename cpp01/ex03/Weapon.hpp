/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 12:15:15 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/09/24 19:35:44 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP
#include <iostream>

//============COLORS!=======//
#define			RED "\e[31m"
#define			GREEN "\e[32m"
#define			LILA "\e[35m"
#define			RESET "\e[0m"


class	Weapon{
	private:

	std::string	_type;

	public:

	Weapon(std::string weapon);
	~Weapon();

	const std::string&	getType(void);
	void				setType(std::string new_type);
};

#endif