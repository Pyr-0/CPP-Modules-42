/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 07:44:10 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/09/08 19:54:41 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

//============COLORS!=======//
#define						RED "\e[31m"
#define						GREEN "\e[32m"
#define						BLUE "\e[36m"
#define						LILA "\e[35m"
#define						YLLW "\e[33m"
#define						RESET "\e[0m"

class	Brain{

	private:
		std::string	*_ideas;
	
	public:
		
		Brain(); //Constructor
		Brain(std::string idea);// Custom Constructor
		Brain(const Brain& ref);// Copy
		~Brain(); //Destructor

		Brain&		operator=(const Brain& rhs); //Overload
		void		brainSound()const; // Method
		std::string	*getIdeas()const; //Accessor
};

#endif
