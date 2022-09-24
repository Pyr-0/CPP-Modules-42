/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 17:15:34 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/09/24 19:38:57 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

//============COLORS!=======//
/*EASTEREGG is only visible in some Terminals ;) (Terminal instead of iTerm)*/
#define			RED "\e[31m"
#define			GREEN "\e[32m"
#define			RESET "\e[0m"
#define			EASTEREGG "\e[05m"

#define CONTACT_SIZE 8

class IState
{
public:
	virtual ~IState() = default;
	
	virtual void action() = 0;
};

class SearchState : public IState
{
public:
	void action()
	{
		
	}
};

class AddState : public IState
{
public:
	void action()
	{
		
	}
};

class InvalidState : public IState
{
	PhoneBook *_phoneBook;
public:
	InvalidState(PhoneBook *phoneBook)
		: _phoneBook(phoneBook) {}
	void action()
	{
		phoneBook->changeState(new DefaultState());			
	}	
};

class	PhoneBookStateMachine{
	private:
		Contact	contact[CONTACT_SIZE];
		int		index;
		bool	isFull;

		IState *_state;

	public:
		//============CONSTRUCTOR & DESTRUCTOR=======//
		
		PhoneBook(void);
		~PhoneBook(void);
		
		//============METHODS=======//
		
		void changeState(IState *state)
		{
			_state = state;
		}

		void action()
		{
			state->action();
		}
		
		void	add();
		void	ask_index();
		void	display_all();
		void	ask_data(Contact data, PhoneBook *pb);
		void	display_data(PhoneBook &pb);
};

//============HELPER FUNCTIONS=======//

std::string		log_data(std::string message);
void			print_menu();
void			menu_input_check(PhoneBook &pb);
void			resize_string(std::string yall);

#endif
