/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 07:34:54 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/09/20 18:36:00 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTER_HPP
#define CONVERTER_HPP

#include <iostream>
#include <exception>
#include <cctype>
#include <cmath>
#include <string>


class	Converter{
	private:
		const std::string		input_;
		const double			value_;

		Converter(void);
		Converter(const Converter& origin);
		Converter& operator=(const Converter &rhs);
		void				print_to_char(void)const;
		void				print_to_int(void)const;
		void				print_to_float(void)const;
		void				print_to_double(void)const;

	public:
		Converter(const std::string& input);
		~Converter(void);

		void				print(void)const;
		const std::string&	get_input(void)const;
		const double&		get_value(void)const;
};

#endif

