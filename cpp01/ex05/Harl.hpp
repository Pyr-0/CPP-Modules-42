/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 19:28:50 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/09/24 19:37:09 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

//============COLORS!=======//
#define					RED "\e[31m"
#define					GREEN "\e[32m"
#define					BLUE "\e[36m"
#define					LILA "\e[35m"
#define					YLLW "\e[33m"
#define					RESET "\e[0m"

class	Harl{
	
	private:
	
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);
	
	public:
		
		std::string level;
		Harl();
		~Harl();
		
		void	complain(std::string level);
};

#endif