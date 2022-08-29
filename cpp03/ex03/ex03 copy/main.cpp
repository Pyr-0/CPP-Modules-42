 
#include "DiamondTrap.hpp"
 
int main(void) {
 DiamondTrap a("slee2");
 a.whoAmI();
 
 DiamondTrap b("B");
 DiamondTrap c("C");
 
 std::cout << std::endl;
 
 b.whoAmI();
 c.whoAmI(); 
 c.highFivesGuys();
 
std::cout << std::endl;
 
 b.attack("C");
 c.takeDamage(20);
 
std::cout << std::endl;
 
 b.attack("C");
 c.takeDamage(30);
 
std::cout << std::endl;
 
 b.guardGate();
 
std::cout << std::endl;
 
 return 0;
}