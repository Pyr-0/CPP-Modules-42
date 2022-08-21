/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 17:52:17 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/08/21 18:53:29 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FIXED_HPP
#define FIXED_HPP

# include <iostream>
# include <string>

//============COLORS!=======//
#define						RED "\e[31m"
#define						GREEN "\e[32m"
#define						BLUE "\e[36m"
#define						LILA "\e[35m"
#define						YLLW "\e[33m"
#define						RESET "\e[0m"


class	Fixed{

	private:

		int					_value;
		static const int	_nFractionalBits = 8;

	public:

		Fixed(void);
		Fixed(Fixed const & src);
		~Fixed(void);

		Fixed&				operator=( Fixed const & rightSide );
		int				getRawBits(void) const;
		void				setRawBits(int const raw);

};

#endif
