/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 12:29:16 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/09/27 23:27:03 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

void	test1(){
	// Empty
	std::cout<< GREEN<<std::endl << "Empty array" << RESET<<std::endl;
	std::cout<< GREEN<<"----------------------------"<<RESET << std::endl;

	Array<int>	arr;
	try{
		std::cout <<YLLW<< "Acessing element 0: "<<RESET << arr[0] << std::endl;
	}
	catch (std::exception &e){
		std::cout <<RED<< e.what() <<RESET<< std::endl << std::endl;
	}
	try{
		std::cout <<YLLW<< "Assigning element 4: "<<RESET << (arr[4] = 4)<< std::endl;
	}
	catch (std::exception &e){
		std::cout <<RED<< e.what() <<RESET<< std::endl;
	}
	std::cout << arr<< RED<<"HELLO?"<<RESET<<std::endl;

	// INT
	std::cout <<GREEN<<std::endl << "Int array" << RESET<<std::endl;
	std::cout <<GREEN<<"----------------------------" << RESET<<std::endl;
	Array<int> narr(4);
	std::cout <<BLUE<< "Before assigning: \n" << narr << RESET<< std::endl;
	narr[0] = 8;
	narr[1] = 2;
	narr[2] = -64;
	narr[3] = 248;
	std::cout <<YLLW<< "After assigning: \n" << narr << RESET<< std::endl;

	// CHAR
	std::cout <<GREEN<<std::endl << "Char array" << RESET<<std::endl;
	std::cout <<GREEN<<"----------------------------" << RESET<<std::endl;
	Array<char> carr(4);
	std::cout <<BLUE<< "Before assigning: \n" << carr << RESET<< std::endl;
	carr[0] = 'a';
	carr[1] = 'b';
	carr[2] = 'c';
	
	std::cout <<YLLW<< "After assigning: \n" << carr << RESET<< std::endl;

	// FLOAT
	std::cout <<GREEN<<std::endl << "Float array" << RESET<<std::endl;
	std::cout <<GREEN<<"----------------------------" << RESET<<std::endl;
	Array<float> farr(4);
	std::cout <<BLUE<< "Before assigning: \n" << farr << RESET<< std::endl;
	farr[0] = 3.14f;
	farr[1] = -48.49f;
	farr[2] = 0.0f;
	farr[3] = 22.22f;
	std::cout <<YLLW<< "After assigning: \n" << farr << RESET<< std::endl;

	// STRING
	std::cout <<GREEN<<std::endl << "String array" << RESET<<std::endl;
	std::cout <<GREEN<<"----------------------------" << RESET<<std::endl;
	Array<std::string> sarr(4);
	std::cout <<BLUE<< "Before assigning: \n" << sarr << RESET<< std::endl;
	sarr[0] = "First string";
	sarr[1] = "Second string";
	sarr[2] = "Third string";
	sarr[3] = "Fourth string";
	std::cout <<YLLW<< "After assigning: \n" << sarr << RESET<< std::endl;
}

void	test2(){

	Array<int>int_arr(21);
	Array<float>f_arr(21);
	for(int i = 0; (unsigned int)i < 22; i++)
	{
		try{
			int_arr[i] = i;
			std::cout <<GREEN<<"int: " << int_arr[i] << RESET<<std::endl;
		}
		catch (std::exception & ex){		std::cout <<RED<< ex.what() <<RESET<< std::endl;
		}
	}
	for(int i = 0; (unsigned int)i < 22; i++)
	{
		try{
			f_arr[i] = i + 0.1;
			std::cout <<YLLW<< "float: " << f_arr[i] << RESET<<std::endl;
		}
		catch (std::exception & ex)	{
			std::cout <<RED<< ex.what() <<RESET<<std::endl;
		}
	}
}

void	checkLeaks(){

	system("leaks array");
}

int main()
{
	//test1();
	test2();
	//atexit(checkLeaks);
}
