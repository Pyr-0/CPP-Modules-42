/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_set.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 21:16:32 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/07/20 12:26:11 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

//=================GETTERS==============//

std::string Contact::get_first()
{
	return (this->firstName);
}

std::string Contact::get_last()
{
	return (this->lastName);
}

std::string Contact::get_phone()
{
	return (this->phoneNumber);
}

std::string Contact::get_dark()
{
	return (this->darkestSecret);
}

std::string Contact::get_nick()
{
	return (this->nickName);
}

//===================SETTERS==============//

void Contact::set_first(std::string first)
{
	this->firstName = first;
}

void Contact::set_last(std::string last)
{
	this->lastName = last;
}

void Contact::set_nick(std::string nick)
{
	this->nickName = nick;
}

void Contact::set_phone(std::string phone)
{
	this->phoneNumber = phone;
}

void Contact::set_dark(std::string dark)
{
	this->darkestSecret = dark;
}
