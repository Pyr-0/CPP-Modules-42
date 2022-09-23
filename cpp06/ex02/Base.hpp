#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <exception>


//============COLORS!=======//
#define						RED "\e[31m"
#define						GREEN "\e[32m"
#define						BLUE "\e[36m"
#define						LILA "\e[35m"
#define						YLLW "\e[33m"
#define						RESET "\e[0m"

/*	We are making our Base class an abstract class */
class	Base{
	public:

		virtual ~Base();
};

void	identify(Base& p);
void identify(Base* p);
Base*	generate(void);



#endif
