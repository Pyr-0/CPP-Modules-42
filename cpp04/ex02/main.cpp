/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 08:25:36 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/09/08 18:42:30 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AbsAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <stdlib.h>


void	check_leaks(){
	system("leaks brain");
}


//Simple instantiation of an abstract class, [It should throw an error]
// void func1(){

// 	AbsAnimal	test;
// }

void	Array_of_animals(){

	//// Array of animals
	const AbsAnimal	*animal_array[4];
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
	atexit(check_leaks);
}

int main( void )
{
	//func1();
	Array_of_animals();
}

