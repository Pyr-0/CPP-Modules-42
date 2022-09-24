/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 22:59:11 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/09/25 00:03:16 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>

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
T const &	min( T const & x, T const & y) {
	return x<y ? x : y;
}

template< typename T >
T const &	max( T const & x, T const & y) {
	return x>y ? x : y;
}

// -------------------------- HELPER FUNCTIONS ------------------------------
template< typename T>
void	ft_print_pair(T a, T b)
{
	std::cout<<GREEN << a << YLLW<<" | "<<GREEN <<  b << RESET<<std::endl;
}

template< typename T>
void printTest(T a, T b, std::string type)
{

	std::cout<<RED << type <<RESET<< std::endl;
	std::cout << "------------" << std::endl;
	// Swap test
	std::cout <<YLLW<< "SWAP: " << std::endl;
	std::cout << "------" <<RESET <<std::endl;
	std::cout <<YLLW<< "Before swapping: \n";
	ft_print_pair(a, b);
	swap(a, b);
	std::cout << "After swapping: \n";
	ft_print_pair(a, b);
	std::cout << std::endl;

	// Min test
	std::cout << "MIN: " << std::endl;
	std::cout << ::min(a, b) << std::endl;

	// Max test	
	std::cout << "MAX: " << std::endl;
	std::cout << ::max(a, b) << std::endl;
	std::cout << std::endl << std::endl;
}
#endif