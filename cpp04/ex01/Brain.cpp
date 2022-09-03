/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 09:48:40 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/09/02 09:52:26 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Brain.hpp"

Brain::Brain()
{
	for (int i = 0; i < 100; i++)
		_ideas[i] = "??";
}

Brain::Brain( std::string idea )
{
	for (int i = 0; i < 100; i++)
		_ideas[i] = idea;
}

Brain::Brain(const Brain& brain)
{
	*this = brain;
}

Brain& Brain::operator=(const Brain &brain)
{
	for(int i = 0; i < 100; i++)
		_ideas[i] = brain._ideas[i];
	return (*this);
}

Brain::~Brain()
{
	std::cout << "brain delete" << std::endl;
}

void Brain::makeSound( void ) const
{
	for (int i = 0; i < 100; i++)
		std::cout << _ideas[i] << std::endl;
}