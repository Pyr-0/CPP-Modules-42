/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 09:48:40 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/09/03 18:32:41 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Brain.hpp"

Brain::Brain(){

	this->_ideas = new std::string[100];
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = "Ergo | Cogito | Soup!";
	std::cout<<RED<< "A Brain has been Created full of ideas"<<RESET<< std::endl;
}

Brain::Brain(const Brain& copy){

	//std::string *copy_ideas = copy.getIdeas();
	std::string *copy_ideas = this->_ideas;
	this->_ideas = new std::string[100];
	for(int i = 0; i < 100; i++)
		this->_ideas[i] = copy_ideas[i] + "COPY";
	*this = copy;
}

Brain& Brain::operator=(const Brain &rhs){

	for(int i = 0; i < 100; i++)
		this->_ideas[i] = rhs._ideas[i];
	return (*this);
}

Brain::~Brain(){

	delete [] this->_ideas;
	std::cout<<RED<< "A Brain has been Destroyed" <<RESET<< std::endl;
}

std::string *Brain::getIdeas()const{
	return this->_ideas;
}

