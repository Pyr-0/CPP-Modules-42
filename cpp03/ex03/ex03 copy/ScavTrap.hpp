 
# ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
 
#include "ClapTrap.hpp"
 
class ScavTrap: public virtual ClapTrap {
 public:
 ScavTrap();
 ScavTrap( std::string _name);
 ~ScavTrap();
 void attack(std::string const & target);
 void takeDamage(unsigned int amount);
 void beRepaired(unsigned int amount);
 void guardGate();
 
 ScavTrap& operator=( ScavTrap const& scav);
 ScavTrap( const ScavTrap& scav);
};
 
#endif