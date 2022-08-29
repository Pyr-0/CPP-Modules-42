#include "FragTrap.hpp"
 
FragTrap::FragTrap(): ClapTrap() {
 this->Hitpoints = 100;
 this->energy = 100;
 this->damage = 30;
 std::cout << "FragTrap_Name : " << this->Name << std::endl;
}
 
FragTrap::FragTrap( std::string name): ClapTrap(name) {
 this->Hitpoints = 100;
 this->energy = 100;
 this->damage = 30;
 std::cout << "FragTrap_Name : " << this->Name << std::endl;
}
 
FragTrap::~FragTrap () {
 std::cout << "FragTrap " << this->Name << " has been destroyed." << std::endl;
}
 
FragTrap& FragTrap::operator=( FragTrap const& frag) {
 ClapTrap::operator=(frag);
 std::cout << "FragTrap " << this->Name << " operator= is called" << std::endl;
 return *this;
}
 
void FragTrap::highFivesGuys(void) {
 if(this->energy)
 std::cout << "FragTrap " << this->Name << " asks for a positive high-five" << std::endl;
 else
 std::cout << "FragTrap " << this->Name << " can't ask for a positive high-five because " << this->Name << " is dead" << std::endl;
 
}
 
FragTrap::FragTrap( const FragTrap& frag) {
 *this = frag;
}


