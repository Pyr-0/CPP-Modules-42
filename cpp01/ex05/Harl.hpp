/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 19:28:50 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/08/19 20:21:41 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

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