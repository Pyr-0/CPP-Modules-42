
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 07:44:10 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/08/26 08:06:08 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "AbsAnimal.hpp"
#include "Brain.hpp"

//============COLORS!=======//
#define						RED "\e[31m"
#define						GREEN "\e[32m"
#define						BLUE "\e[36m"
#define						LILA "\e[35m"
#define						YLLW "\e[33m"
#define						RESET "\e[0m"

class Cat:public AbsAnimal{

	private:
		Brain*	_brain;
	
	public:
		
		Cat(); //Constructor
		virtual ~Cat(); //Destructor
		Cat(const Cat& ref);// Copy
		
		Cat&		operator=(const Cat& rhs); //Overload
		
		void		makeSound()const;
		void		think()const;
};


// std::ostream &			operator<<( std::ostream & o, Cat const & i );
#endif
