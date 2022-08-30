/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 18:22:01 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/08/30 20:48:14 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

//============COLORS!=======//
#define					RED "\e[31m"
#define					GREEN "\e[32m"
#define					BLUE "\e[36m"
#define					LILA "\e[35m"
#define					YLLW "\e[33m"
#define					RESET "\e[0m"
#define					ULINE "\e[4m\e[1m"


class ClapTrap
{

	protected:
		std::string		_name;
		int				_hitPoints;
		int				_attackDamage;
		int				_energyPoints;

	public:

		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap& clapTrap);
		~ClapTrap();

		ClapTrap&		operator=( ClapTrap const & rhs );

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		
		std::string		getName() const;
		int				getAttackDamage() const;
		int				gethitPoints() const;
		int				getenergyPoints() const;
		void			cannotDoTheThing() const;

};

std::ostream &			operator<<( std::ostream & o, ClapTrap const & i );

#endif
