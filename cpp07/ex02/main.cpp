/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 12:29:16 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/09/27 13:32:13 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main()
{
	// Empty
	std::cout << std::endl << "Empty array" << std::endl;
	std::cout << "----------------------------" << std::endl;
	Array<int>	arr;
	try
	{
		std::cout << "Acessing element 0: " << arr[0] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl << std::endl;
	}
	try
	{
		std::cout << "Assigning element 4: " << std::endl;
		arr[4] = 4;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << arr << std::endl;

	// INT
	std::cout << std::endl << "Int array" << std::endl;
	std::cout << "----------------------------" << std::endl;
	Array<int> narr(4);
	std::cout << "Before assigning: \n" << narr << std::endl;
	narr[0] = 8;
	narr[1] = 2;
	narr[2] = -64;
	narr[3] = 248;
	std::cout << "After assigning: \n" << narr << std::endl;

	// CHAR
	std::cout << std::endl << "Char array" << std::endl;
	std::cout << "----------------------------" << std::endl;
	Array<char> carr(4);
	std::cout << "Before assigning: \n" << carr << std::endl;
	carr[0] = 'a';
	carr[1] = 'b';
	carr[2] = 'c';
	std::cout << "After assigning: \n" << carr << std::endl;

	// FLOAT
	std::cout << std::endl << "Float array" << std::endl;
	std::cout << "----------------------------" << std::endl;
	Array<float> farr(4);
	std::cout << "Before assigning: \n" << farr << std::endl;
	farr[0] = 3.14f;
	farr[1] = -48.49f;
	farr[2] = 0.0f;
	farr[3] = 22.22f;
	std::cout << "After assigning: \n" << farr << std::endl;

	// STRING
	std::cout << std::endl << "String array" << std::endl;
	std::cout << "----------------------------" << std::endl;
	Array<std::string> sarr(4);
	std::cout << "Before assigning: \n" << sarr << std::endl;
	sarr[0] = "First string";
	sarr[1] = "Second string";
	sarr[2] = "Third string";
	sarr[3] = "Fourth string";
	std::cout << "After assigning: \n" << sarr << std::endl;
}
	/* int *a = new int();

	std::cout<<RED<<a<< std::endl; // ?? 
	Array<int>int_arr(21);
	Array<float>f_arr(21);
	for(int i = 0; (unsigned int)i < 21; i++) //bounds how do they work here
	{
		try{
			int_arr[i] = i;
			std::cout <<GREEN<< "int: " << int_arr[i] << RESET<<std::endl;
		}
		catch (Array<int>::BadNumException & ex){
			std::cout <<RED<< ex.what() <<RESET<< std::endl;
		}
	}
	for(int i = 0; (unsigned int)i < 22; i++)
	{
		try{
			f_arr[i] = i + 0.1;
			std::cout <<YLLW<< "float: " << f_arr[i] << RESET<<std::endl;
		}
		catch (Array<float>::BadNumException & ex)
		{
			std::cout <<RED<< ex.what() <<RESET<< std::endl;
		}
	}
 */
}
 
