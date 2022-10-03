/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 16:49:41 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/10/02 21:28:40 by mrojas-e         ###   ########.fr       */
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
	
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		std::cout << std::endl;
	}catch (std::exception &e){
		std::cerr <<RED<< e.what()<< RESET<< std::endl;
	}
	std::cout <<GREEN<< "===== extra test =====" <<RESET<< std::endl;
	std::vector<int> newVec(5, random());
	try{
		Span sp1 = Span(5);
		sp1.addNumber(newVec);
		for(int i = 0; i < 5; i++)
		std::cout << sp1.elems_[i] << std::endl;
		std::cout << std::endl;
	}catch (std::exception &e){
		std::cerr <<RED<< e.what()<< RESET<< std::endl;
	}	
	try{
		std::cout <<GREEN<< "===== exception test =====" <<RESET<< std::endl;
		Span sp2(2);
		sp2.addNumber(6);
		sp2.addNumber(1);
		std::cout << sp2.shortestSpan() << std::endl;
		std::cout << sp2.longestSpan() << std::endl;
		std::cout << std::endl;

	}catch (std::exception &e){
		std::cerr <<RED<< e.what()<< RESET<< std::endl;
	}
	return 0;
}