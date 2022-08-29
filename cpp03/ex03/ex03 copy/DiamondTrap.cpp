#include "DiamondTrap.hpp"
 
DiamondTrap::DiamondTrap(): ClapTrap(), FragTrap(), ScavTrap(), Name(ClapTrap::Name) {
 ClapTrap::Name += "_clap_name";
 ClapTrap::damage = 30;
 std::cout << "DiamondTrap_Name : " << this->Name << std::endl;
}
 
DiamondTrap::DiamondTrap(std::string n): ClapTrap(n), FragTrap(n), ScavTrap(n), Name(n) {
 ClapTrap::Name += "_clap_name";
 ClapTrap::damage = 30;
 std::cout << "DiamondTrap_Name : " << this->Name << std::endl;
}
 
DiamondTrap::~DiamondTrap() {
 std::cout << "DiamondTrap " << this->Name << " has been destroyed." << std::endl;
}
 
void DiamondTrap::attack(std::string const & target) {
 ScavTrap::attack(target);
}
 
DiamondTrap& DiamondTrap::operator=( DiamondTrap const& Diamond) {
 ClapTrap::operator=(Diamond);
 std::cout << "DiamondTrap " << this->Name << " operator= is called" << std::endl;
 return *this;
}
 
void  DiamondTrap :: whoAmI () {
 std::cout << "DiamondTrap name is " << this->Name << " and ClapTrap name is " << ClapTrap::Name << std::endl;
}
 
DiamondTrap::DiamondTrap( const DiamondTrap& dia) {
 *this = dia;
}