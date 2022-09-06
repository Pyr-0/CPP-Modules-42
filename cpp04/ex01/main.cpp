/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 08:25:36 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/09/06 20:20:17 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <stdlib.h>


void func(){

	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout<<j<<i<<std::endl;
	delete j;//should not create a leak
	delete i;
	system("leaks brain");
}

void func2()
{
	// Animal	*a = new Dog();
	
	// std::cout<< a;
	// std::cout<< a;
	
	// // //show deep copy
	Dog*		 Dog1 = new  Dog;
	Dog*		 Dog2 = new  Dog(*Dog1);
	delete Dog1;
	delete Dog2;
	//system("leaks brain");
}
int main( void )
{
	func2();
	//delete a;
	
	/* 
	Dog *basic;
	
	basic = new Dog();
	{
		Dog tmp = *basic;
	} */
	
	//delete basic;
	
	// Exercice example
	// const Animal* dog = new Dog();
	// const Animal* cat = new Cat();

	// std::cout << std::endl;

	// delete dog;
	// delete cat;
	// system("leaks ex01");
	// std::cout << std::endl;
	// std::cout << std::endl;

	// // Proof of deep copy
	// Dog medor;
	// Cat fifi;

/* 	Dog & medor_ref = medor;
	Cat & fifi_ref = fifi;

	std::cout << std::endl << "creating copies" << std::endl;
	Dog medor_copy(medor_ref);
	Cat fifi_copy(fifi_ref);

	Dog & medor_copy_ref = medor_copy;
	Cat & fifi_copy_ref = fifi_copy;
 */
/* 	std::cout << std::endl << "comparing" << std::endl;
	medor.compareTo(medor_copy_ref);
	fifi.compareTo(fifi_copy_ref);
	std::cout << std::endl; */


	//// Array of animals
	//const Animal	*animal_array[4];
	//std::cout << std::endl;
	//// Half filled with dogs
	//for (int i = 0; i < 2; i++)
	//	animal_array[i] = new Dog();
	//std::cout << std::endl;
//
	//// Half filled with cats
	//for (int i = 2; i < 4; i++)
	//	animal_array[i] = new Cat();
	//std::cout << std::endl;
//
	//for (int i = 0; i < 4; i++)
	//	delete animal_array[i];
	//std::cout << std::endl;
//
	//system("leaks brain");
}