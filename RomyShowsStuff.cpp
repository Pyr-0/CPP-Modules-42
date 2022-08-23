#include "RomyShowsStuff.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

RomyShowsStuff::RomyShowsStuff()
{
}

RomyShowsStuff::RomyShowsStuff( const RomyShowsStuff & src )
{
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

RomyShowsStuff::~RomyShowsStuff()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

RomyShowsStuff &				RomyShowsStuff::operator=( RomyShowsStuff const & rhs )
{
	//if ( this != &rhs )
	//{
		//this->_value = rhs.getValue();
	//}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, RomyShowsStuff const & i )
{
	o << "Value = " << i.getInt();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */