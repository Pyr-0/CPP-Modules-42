/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 15:46:10 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/09/24 19:36:54 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_HPP
#define REPLACE_HPP

#include <iostream>
#include <fstream>
#include <string>

//============COLORS!=======//
#define					RED "\e[31m"
#define					GREEN "\e[32m"
#define					LILA "\e[35m"
#define					RESET "\e[0m"

class	myReplace{
	private:
		std::string		_str1;
		std::string		_str2;
		std::ifstream	_readFile;
		std::ofstream	_writeFile;
	
	public:
		myReplace(std::string filename, std::string str1, std::string str2);
		~myReplace();
		bool			check_file();
		void			do_replace();
};

#endif
