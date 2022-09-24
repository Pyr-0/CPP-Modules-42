/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 19:28:36 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/09/24 21:25:24 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

/*	By making our Base Destructor VIRTUAL, we must make its first instance in
	our program in order for the compilation to work */

Base::~Base(){}

static void msg(std::string msg){
	std::cout<<YLLW<< msg <<RESET<<std::endl;
}

Base*	generate(void){

	int	randomNumber = arc4random() % 3 ;
	
	switch (randomNumber)
	{
	case 0: msg("A was Created");
			return new A;
			break;
	case 1: msg("B was Created");
			return new B;
			break;
	case 2: msg("C was Created");
			return new C;
			break;
	default:
		;//do nothing
	}
	return NULL;
}

/*	This function identifies the Type by its Address but wont check for errors within itself
	the rule for dynamic cast is that it can only be used
	in VIRTUAL ABSTRACT CLASSES*/

void identify(Base* p)
{
	if (dynamic_cast<A *>(p))
		msg("Type is A pointer");
	else if (dynamic_cast<B *>(p))
		msg("Type is B pointer");
	else if (dynamic_cast<C *>(p))
		msg("Type is C pointer");
	else
		msg("Unknown Type");
}

/*	This function identifies the Type by its refference , and it will protect against errors inside
	of itself in case that the casting isnt possible */
void	identify(Base& p){
	
	try{
		(void)dynamic_cast<A&>(p);
		msg("Type is A reference");
		return;
	}catch (std::bad_cast &bad){
		std::cout<<RED<<"Casting to A was not possible " << bad.what()<<RESET<< std::endl;
	}

	try{
		(void)dynamic_cast<B&>(p);
		msg("Type is B reference");
		return;
	}catch (std::bad_cast &bad){
		std::cout<<RED<<"Casting to B was not possible " << bad.what()<<RESET<< std::endl;
	}
	
	try{
		(void)dynamic_cast<C&>(p);
		msg("Type is C reference");
		return;
	}catch (std::bad_cast &bad){
		std::cout<<RED<<"Casting to C was not possible " << bad.what()<<RESET<< std::endl;
	}
}

void check_leaks(){

	system("leaks dynamic");
}

int	main(){

	for (int i = 0; i < 3; i++){

		Base * randomPtr = generate();
		Base& refRandomBase = *randomPtr;
		identify(randomPtr);
		identify(refRandomBase);
		delete randomPtr;
		std::cout << std::endl;
	}
		//atexit(check_leaks);
		return (0);
}
