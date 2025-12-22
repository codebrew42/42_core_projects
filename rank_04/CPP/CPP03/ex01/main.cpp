#include "ScavTrap.hpp"

int main() {
	std::cout << "=== Creating Traps ===" << std::endl;
	ClapTrap clap("Clappy");
//Parent -> child constructor
	ScavTrap scav("Scavvy");
	std::cout << std::endl;

	std::cout << "=== Initial Stats ===" << std::endl;
	clap.scanThisPerson();
	scav.scanThisPerson();
	std::cout << std::endl;

	std::cout << "=== Attack Comparison (ClapTrap vs ScavTrap) ===" << std::endl;
	clap.attack("target");  // ClapTrap message, 0 damage
	scav.attack("target");  // ScavTrap message, 20 damage
	std::cout << std::endl;

	std::cout << "=== Real Battle: ScavTrap vs ClapTrap ===" << std::endl;
	scav.attack("Clappy");
	clap.takeDamage(20);  // ScavTrap does 20 damage!
	clap.scanThisPerson();
	std::cout << std::endl;

	std::cout << "=== ScavTrap Special Ability ===" << std::endl;
	scav.guardGate();
	std::cout << std::endl;

	std::cout << "=== Repair Test ===" << std::endl;
	clap.beRepaired(5);
	clap.scanThisPerson();
	std::cout << std::endl;

	std::cout << "=== Energy Depletion (ScavTrap has 50 energy) ===" << std::endl;
	scav.scanThisPerson();
	std::cout << "Attacking 49 times to drain energy..." << std::endl;
	for (int i = 0; i < 5; i++) {
		scav.attack("dummy");
	}
	scav.scanThisPerson();
	scav.attack("dummy");  // Should fail - no energy left
	std::cout << std::endl;

	std::cout << "=== Death Test ===" << std::endl;
	clap.takeDamage(100);  // Overkill
	clap.attack("someone");   // Should fail (dead)
	clap.beRepaired(10);	  // Should fail (dead)
	std::cout << std::endl;

	std::cout << "=== Copy Constructor Test ===" << std::endl;
	ScavTrap clone(scav);
	clone.scanThisPerson();
	std::cout << std::endl;

	std::cout << "=== Assignment Operator Test ===" << std::endl;
//parent->child
	ScavTrap assigned("Temp");
//child->parent
	assigned = clone;
	assigned.scanThisPerson();
	std::cout << std::endl;

	std::cout << "=== Destruction Chain (watch order!) ===" << std::endl;
	return 0;
}