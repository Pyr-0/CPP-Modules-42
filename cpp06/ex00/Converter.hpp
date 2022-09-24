/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 07:34:54 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/09/24 16:58:35 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTER_HPP
#define CONVERTER_HPP

#include <iostream>
#include <exception>
#include <cctype>
#include <cmath>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <limits>
#include <sstream>

//============COLORS!=======//
#define						RED "\e[31m"
#define						GREEN "\e[32m"
#define						BLUE "\e[36m"
#define						LILA "\e[35m"
#define						YLLW "\e[33m"
#define						RESET "\e[0m"

class	Converter{
	private:
		std::string		input_;
		double			value_;

		Converter(void);
		Converter(const Converter& origin);
		Converter& operator=(const Converter &rhs);
		void				printToChar(void)const;
		void				printToInt(void)const;
		void				printToFloat(void)const;
		void				printToDouble(void)const;

	public:
		Converter( const std::string & input);
		~Converter(void);

		void				print(void)const;
		const std::string&	get_input(void)const;
		const double&		get_value(void)const;
		bool				isChar(const std::string & input);
};

#endif

