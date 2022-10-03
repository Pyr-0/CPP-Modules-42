/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 16:49:41 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/10/03 17:01:12 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <numeric>
#include <iostream>
#include <vector>
#include <stdexcept>
#include <cstdlib>

#include "Span.hpp"

int main(void) {
	std::cout<<GREEN << "===== basic test =====" <<RESET<< std::endl;
	try{
		Span sp = Span(3);
		sp.addNumber(-100);
		sp.addNumber(-50);
		sp.addNumber(5);
	
		std::cout <<YLLW<< "Shortest span: " <<RESET<< sp.shortestSpan() << std::endl;
		std::cout <<YLLW<< "Longest span:  " <<RESET<< sp.longestSpan() << std::endl;
		std::cout << std::endl;
	}catch (std::exception &e){
		std::cerr <<RED<< e.what()<< RESET<< std::endl;
	}
	std::cout <<GREEN<< "===== extra test =====" <<RESET<< std::endl;
	try{
			// A "Span" which has elements between 1 and 2000000, making thousands of calls to addNumber()
		Span	sp2(0, 2000000,1);
		std::cout <<YLLW<< "Shortest span: " <<RESET<< sp2.shortestSpan() <<  std::endl; // 10, it's in the constructor
		std::cout <<YLLW<< "Longest span:  " <<RESET<< sp2.longestSpan() <<std::endl; // 2000001 - 10 = 1999990
		//show elements in array :)
		// for(int i = 0; i < 10; i++){
		// 	std::cout << sp2.getelems()[i] << std::endl;}
		// std::cout << std::endl;
	}catch (std::exception &e){
		std::cerr <<RED<< e.what()<< RESET<< std::endl;
	}	
	try{
		std::cout <<GREEN<< "===== exception test =====" <<RESET<< std::endl;
		Span sp2(1);
		sp2.addNumber(6);
		sp2.addNumber(1);
		std::cout << sp2.shortestSpan() << std::endl;
		std::cout << sp2.longestSpan() << std::endl;
		std::cout << std::endl;

	}catch (std::exception &e){
		std::cerr <<RED<< e.what()<< RESET<< std::endl;
	}
	std::cout << std::endl;
	return 0;
}