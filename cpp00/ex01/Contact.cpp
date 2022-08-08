/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 22:34:03 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/08/05 11:27:59 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

Contact::Contact(){}
Contact::~Contact(){}

/*	The resize_string function takes care of the lenght limit a contact's 
	input should have (10characters), and if it is longer it will trim it
	to fit 10 characters and align it with the contact form using "|" at the end.*/
void	resize_string(std::string string)
{
	if(string.size() >= 10)
		std::cout<<std::setw(8)<<string.substr(0,9)<< "." << "|";
	else
		std::cout<<std::setw(10)<<string<< "|";
}

void Contact::print_contact()
{
	std::cout<<GREEN<<"Firstname: "<<RESET<<get_first()<<std::endl;
	std::cout<<GREEN<<"Last name: "<<RESET<<get_last()<<std::endl;
	std::cout<<GREEN<<"Nick Name: "<<RESET<<get_nick()<<std::endl;
	std::cout<<GREEN<<"Phone Number: "<<RESET<<get_phone()<<std::endl;
	std::cout<<GREEN<<"Darkest Secret: "<<RESET<<get_dark()<<std::endl;
}

//=================GETTERS==============//

std::string Contact::get_first(){
	return (this->firstName);
}

std::string Contact::get_last(){
	return (this->lastName);
}

std::string Contact::get_phone(){
	return (this->phoneNumber);
}

std::string Contact::get_dark(){
	return (this->darkestSecret);
}

std::string Contact::get_nick(){
	return (this->nickName);
}

//===================SETTERS==============//

void Contact::set_first(std::string first){
	this->firstName = first;
}

void Contact::set_last(std::string last){
	this->lastName = last;
}

void Contact::set_nick(std::string nick){
	this->nickName = nick;
}

void Contact::set_phone(std::string phone){
	this->phoneNumber = phone;
}

void Contact::set_dark(std::string dark){
	this->darkestSecret = dark;
}
