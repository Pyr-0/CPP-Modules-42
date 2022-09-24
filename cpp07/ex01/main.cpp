/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 00:18:10 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/09/25 00:23:31 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main(void)
{
	int			iarr[4] = {0, 1, 2, 3};
	char		carr[5] = "abcd";
	float		farr[4] = {0.1f, 2.3f, 4.5f, 6.7f};
	std::string	sarr[4] = {"See?, ", "it", "works", "oke"};

	// INT
	ft_tests(iarr, 4, "INT");

	// CHAR
	ft_tests(carr, 5, "CHAR");

	// FLOAT
	ft_tests(farr, 4, "FLOAT");

	// STRING
	ft_tests(sarr, 4, "STRING");
	return (0);
}
