/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 22:59:11 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/09/28 22:31:07 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>
#include <string>

//============COLORS!=======//
#define						RED "\e[31m"
#define						GREEN "\e[32m"
#define						BLUE "\e[36m"
#define						LILA "\e[35m"
#define						YLLW "\e[33m"
#define						RESET "\e[0m"

//============ FUNCTIONS ============//

template< typename T >
void	swap( T & x, T & y){
	T	temp;
	temp = x;
	x = y;
	y = temp;
}

template< typename T >
const T&	min(  T const & x, T const & y ) {
	return x < y ? x : y;
}

template< typename T >
T const &	max( T const & x, T const & y) {
	return x > y ? x : y;
}

//============ HELPER FUNCTIONS ============//

template< typename T>
void		ft_print_pair(T a, T b){
	std::cout<<GREEN << a << YLLW<<" | "<<GREEN <<  b << RESET<<std::endl;
}

template< typename T>
void		printTest(T a, T b, std::string type){

	std::cout<<RED << type << std::endl;
	std::cout << "------------"<<RESET << std::endl;
	// Swap test
	std::cout <<YLLW<< "SWAP: " << std::endl;
	std::cout << "------" <<RESET <<std::endl;
	std::cout <<YLLW<< "Before swapping: \n";
	ft_print_pair(a, b);
	::swap(a, b);
	std::cout <<YLLW<< "After swapping: \n"<<RESET;
	ft_print_pair(a, b);
	std::cout << std::endl;

	// Min test
	std::cout<< YLLW << "MIN: " <<RESET<< std::endl;
	std::cout<< GREEN << ::min(a, b) <<RESET<< std::endl;

	// Max test	
	std::cout << YLLW << "MAX: " <<RESET<< std::endl;
	std::cout << GREEN<< ::max(a, b) <<RESET<< std::endl;
	std::cout << std::endl;
}
#endif