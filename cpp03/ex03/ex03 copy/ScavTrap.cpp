#include "ScavTrap.hpp"
 
ScavTrap::ScavTrap(): ClapTrap() {
 this->Hitpoints = 100;
 this->energy = 50;
 this->damage = 20;
 std::cout << "ScavTrap_Name : " << this->Name << std::endl;
}
 
ScavTrap::ScavTrap( std::string _name): ClapTrap(_name) {
 this->Hitpoints = 100;
 this->energy = 50;
 this->damage = 20;
 std::cout << "ScavTrap_Name : " << this->Name << std::endl;
}
 
ScavTrap::~ScavTrap() {
 std::cout << "ScavTrap "<< this->Name << " has been destroyed." << std::endl;
}
 
ScavTrap& ScavTrap::operator=( ScavTrap const& scav) {
 ClapTrap::operator=(scav);
 std::cout << "ScavTrap " << this->Name << " operator= is called" << std::endl;
 return *this;
}
 
void ScavTrap::attack(std::string const & target) {
 std::cout << "ScavTrap " << this->Name << \
 " attacks " << target << " , causing " \
 << this->damage << " points of damage!" << std::endl;
}
 
void ScavTrap::takeDamage(unsigned int amount) {
 if (this->energy <= amount) {
 std::cout << this->Name << " is dead" << std::endl;
 this->energy = 0;
 }
 else {
 this->energy -= amount;
 std::cout << "ScavTrap " << this->Name << \
 " take Damage " << amount << " , remaning hp is " \
 << this->energy << std::endl;
 }
}
 
void ScavTrap::beRepaired(unsigned int amount) {
 if (this->energy == 0) {
 std::cout << "ScavTrap " << this->Name << " is repaired by " << amount << " and comes back to life" << std::endl;
 this->energy += amount;
 }
 else {
 this->energy += amount;
 std::cout << "ScavTrap " << this->Name << " is repaired by " << amount << " and remaning hp is " << this->energy << std::endl;
 }
}
 
void ScavTrap::guardGate() {
 if (energy)
 std::cout << "ScavTrap " << this->Name << " has entered gate guard mode." << std::endl;
 else
 std::cout << "ScavTrap " << this->Name << " cannot enter gate guard mode because " << this->Name << " is dead." << std::endl;
}
 
ScavTrap::ScavTrap( const ScavTrap& scav) {
 *this = scav;
}
