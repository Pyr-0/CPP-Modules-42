/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 08:25:36 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/09/09 20:33:07 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

void	check_leaks(){
	system("leaks brain");
}

/*	Test according to the example given in the pdf*/
void func(){

	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout<<j<<i<<std::endl;
	delete j;//should not create a leak
	delete i;
}

/*	Testing simple instance creation with 3 leaks if not deleted
	one is for the class animal m the otherone is for the dog created
	and the last belongs to the brain */
void	func2()
{
	Animal	*a = new Dog();
	std::cout<<GREEN<< "Address of Dog is: "<< a<< std::endl;
	delete a;
}

/*	Testing the deep copy created from an already created instance
	which will create also the derived classes and the brains independently */
void	func3(){
	Dog*		 Dog1 = new  Dog;
	Dog*		 Dog2 = new  Dog(*Dog1);
	delete Dog1;
	delete Dog2;
	std::cout<<YLLW<<"The Dog's Address is: "<< Dog1<< RESET<< std::endl;
	std::cout<<YLLW <<"Dog's Copy Address is: "<< Dog2<<RESET<< std::endl;
}

void	Array_of_animals(){

	//// Array of animals
	const Animal	*animal_array[4];
	std::cout << std::endl;
	// Half filled with dogs
	for (int i = 0; i < 2; i++)
		animal_array[i] = new Dog();
	std::cout << std::endl;

	// Half filled with cats
	for (int i = 2; i < 4; i++)
		animal_array[i] = new Cat();
	std::cout << std::endl;

	//Deletion Loop
	for (int i = 0; i < 4; i++)
		delete animal_array[i];
	std::cout << std::endl;
}

int main( void )
{
	// func();
	// func2();
	func3();
	//Array_of_animals();
	//atexit(check_leaks);
}