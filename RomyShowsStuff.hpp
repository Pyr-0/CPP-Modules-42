#ifndef ROMYSHOWSSTUFF_HPP
# define ROMYSHOWSSTUFF_HPP

# include <iostream>
# include <string>

class RomyShowsStuff
{

	public:

		RomyShowsStuff();
		RomyShowsStuff( RomyShowsStuff const & src );
		~RomyShowsStuff();

		RomyShowsStuff &		operator=( RomyShowsStuff const & rhs );

	private:

};

std::ostream &			operator<<( std::ostream & o, RomyShowsStuff const & i );

#endif /* ************************************************** ROMYSHOWSSTUFF_H */