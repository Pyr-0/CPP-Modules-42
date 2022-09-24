/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 22:36:21 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/09/24 19:36:39 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

int	main(int argc, char* argv[])
{
	if (argc != 4)
	{
		std::cout <<RED<< "Wrong input please write: ./replace \"filename\" \"s1\" \"s2\"" <<RESET<< std::endl;
		return (1);
	}
	myReplace myreplace(argv[1], argv[2], argv[3]);
	if (!myreplace.check_file())
	{
		std::cout <<RED<< "File Error: file not found " <<RESET<< std::endl;
		return (1);
	}
	myreplace.do_replace();
	std::cout <<LILA<< argv[1] <<GREEN<< " replace finish!\ncheck your " <<LILA<< argv[1] << ".replace" <<RESET<< std::endl;
	return (0);
}