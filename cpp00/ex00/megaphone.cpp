/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 17:23:28 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/09/24 19:38:25 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<iostream>

int	main(int argc, char **argv)
{
	int	i = 0;
	int	j = 0;

	if (argc == 1)
	{
		std::cout << "\e[31m* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	else if (argc > 1)
	{
		for (i = 1; i < argc; i++) {
			for (j = 0; argv[i][j]; j++) {
				std::cout << "\e[33m" << (char) std::toupper(argv[i][j]);
			}
			std::cout << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}
