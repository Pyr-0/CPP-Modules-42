/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 18:22:01 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/08/29 14:40:36 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

//============COLORS!=======//
#define						RED "\e[31m"
#define						GREEN "\e[32m"
#define						BLUE "\e[36m"
#define						LILA "\e[35m"
#define						YLLW "\e[33m"
#define						RESET "\e[0m"
#define						ULINE "\e[4m\e[1m"


class	DiamondTrap : public FragTrap, public ScavTrap {

	private:
		std::string _name;

	public:

		DiamondTrap();
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap& DiamondTrap);
		~DiamondTrap();

		DiamondTrap&		operator=( DiamondTrap const & rhs );

		void				takeDamage(unsigned int amount);
		void				attack(const std::string& target);
		void				beRepaired(unsigned int amount);
		
		void				cannotDoTheThing() const;
		std::string			getPrivateName(void);
		void				whoAmI(void);

};

std::ostream &				operator<<( std::ostream & o, DiamondTrap const & i );

#endif
