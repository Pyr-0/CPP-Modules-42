/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 18:58:35 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/09/30 13:19:49 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <exception>
#include <iostream>
# include <algorithm>
#include <vector>
# include <list>
# include <iterator>
# include <array>
# include <deque>

//============COLORS!=======//
#define						RED "\e[31m"
#define						GREEN "\e[32m"
#define						BLUE "\e[36m"
#define						LILA "\e[35m"
#define						YLLW "\e[33m"
#define						RESET "\e[0m"

template<typename T>
typename T::const_iterator easyfind(const T &container, int element){

	typename T::const_iterator result = std::find(container.begin(), container.end(), element);
	
	if (result == container.end())
		throw std::out_of_range("Error: element not found!");
	return result;
}

#endif
