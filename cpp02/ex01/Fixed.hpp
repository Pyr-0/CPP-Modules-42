/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 17:52:17 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/08/24 00:20:07 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FIXED_HPP
#define FIXED_HPP

# include <iostream>
# include <string>
# include <cmath>

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
		Fixed( int const i);
		Fixed( float const f);
		Fixed(Fixed const & alreadyExistingObject);
		~Fixed(void);

		float				toFloat(void)const;
		int					toInt(void)const;
		Fixed&				operator=( const Fixed & rightSideOfOperator );
		void				setRawBits(int const raw);
		int					getRawBits(void) const;

};

std::ostream &			operator<<( std::ostream & output, Fixed const & i );

#endif
