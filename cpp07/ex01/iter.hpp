/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 00:14:43 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/09/25 11:24:26 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>


//============COLORS!=======//
#define						RED "\e[31m"
#define						GREEN "\e[32m"
#define						BLUE "\e[36m"
#define						LILA "\e[35m"
#define						YLLW "\e[33m"
#define						RESET "\e[0m"

template< typename T>
void iter(T *array, int arrayLength, void myFunc(T const &ref))
{
	for(int i = 0; i < arrayLength; i++)
		myFunc(array[i]);
}

// HELPER FUNCTIONS:
template< typename T>
void	doTheThing(T const &t)
{
	std::cout << t << " ";
}

template< typename T>
void ft_tests(T t, int len, std::string type)
{
	std::cout << std::endl;
	std::cout << RED << type <<RESET<< std::endl;
	std::cout << "-------------------" << std::endl;
	iter(t, len, doTheThing);
	std::cout << std::endl<<std::endl;
}

#endif