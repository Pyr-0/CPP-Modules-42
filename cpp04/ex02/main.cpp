/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 08:25:36 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/09/06 20:07:01 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AbsAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <stdlib.h>


void func(){
	// AbsAnimal	*test = new Dog(); // this is an instance of an Abstract class, it wont work since the class method is Purely virtual.
	// Dog			*test = new Dog; // This works because its not an instance of the base class, yet a derived class
	// Cat			test2; // This works because its not an instance of the base class, yet a derived class
	// std::cout<< test<<std::endl;
	// std::cout<< test2<<std::endl;
	
	
	// // //show deep copy
	Dog*		 Dog1 = new  Dog;
	Dog*		 Dog2 = new  Dog(*Dog1);
	
	 std::cout<< <<std::endl;
	//delete Dog1;
	//delete Dog2;
} int main( void )
{
	func();
	system("leaks brain");
}