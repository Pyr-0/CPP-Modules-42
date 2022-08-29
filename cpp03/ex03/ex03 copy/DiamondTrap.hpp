#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP
 
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
 
class DiamondTrap: public FragTrap, public ScavTrap {
 private:
 std::string Name;
 public:
 DiamondTrap();
 DiamondTrap( std::string n);
 ~DiamondTrap();
 void attack(std::string const & target);
 DiamondTrap& operator=( DiamondTrap const& Diamond);
 DiamondTrap( const DiamondTrap& dia);
 void  whoAmI ();
};
 
#endif