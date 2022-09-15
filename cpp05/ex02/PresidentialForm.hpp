/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialForm.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 17:32:18 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/09/15 23:52:34 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALFORM_HPP
#define PRESIDENTIALFORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>


//============COLORS!=======//
#define						RED "\e[31m"
#define						GREEN "\e[32m"
#define						BLUE "\e[36m"
#define						LILA "\e[35m"
#define						YLLW "\e[33m"
#define						RESET "\e[0m"


class PresidentialForm: public Form{
private:
	std::string	_target;
	
public:
	PresidentialForm();
	PresidentialForm(std::string target);
	PresidentialForm(const PresidentialForm& copy);
	PresidentialForm & operator=(const PresidentialForm & ref);
	virtual ~PresidentialForm();

	std::string	getTarget(void)const;
	void	execute(const Bureaucrat & executor)const;
};

	std::ostream&	operator<<(std::ostream & o, const PresidentialForm& rhs);


#endif
