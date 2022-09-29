/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 22:59:05 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/09/28 22:26:46 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int	main(){

	// INT
	int			n1 = 43;
	int			n2 = 42;

	// FLOAT
	float		f1 = 0.0f;
	float		f2 = -475.14f;

	// STRING
	std::string	s1 = "Hallo";
	std::string	s2 = "Aloha dear coder";

	// CHAR
	char		c1 = 'a';
	char		c2 = 'b';

	// DOUBLE
	double		d1 = 4.4;
	double		d2 = 4.4;

	//---------------------------- TESTS -----------------------------------

	// INT
	::printTest(n1, n2, "Int");

	// FLOAT
	printTest(f1, f2, "Float");

	// DOUBLE
	printTest(d1, d2, "Double");

	// STRING
	printTest(s1, s2, "String");

	// CHAR
	printTest(c1, c2, "Char");
	
	int x;
	
	std::cout<<RED<< "TRYING OUT A NEW SYNTAX"<< std::endl;
	x = min<int>(n1,n2);
	std::cout<<RED<< "MINIMUM NUMBER IS: "<<x<< std::endl;
	
	//x = ::min<int>(n1,n2); //Another way of calling the function

}
