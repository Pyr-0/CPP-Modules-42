/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 20:57:40 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/08/24 21:02:54 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"
# include <iostream>
# include <string>

//============COLORS!=======//
#define						RED "\e[31m"
#define						GREEN "\e[32m"
#define						BLUE "\e[36m"
#define						LILA "\e[35m"
#define						YLLW "\e[33m"
#define						RESET "\e[0m"

class ScavTrap: public ClapTrap{
	
	
	public:

		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap& ScavTrap);
		~ScavTrap();
	
		ScavTrap&		operator=( ScavTrap const & rhs );
		void guardGate();
		void attack(const std::string& target);
};

std::ostream &			operator<<( std::ostream & o, ScavTrap const & i );

#endif /* ******************************************************** ScavTrap_H */