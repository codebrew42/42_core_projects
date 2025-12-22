#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main() {
	std::cout << "=== Creating All Trap Types ===" << std::endl;
	ClapTrap clap("Clappy");
	ScavTrap scav("Scavvy");
	FragTrap frag("Fraggy");
	std::cout << std::endl;

	std::cout << "=== Initial Stats Comparison ===" << std::endl;
	clap.scanThisPerson();
	scav.scanThisPerson();
	frag.scanThisPerson();
	std::cout << std::endl;

	std::cout << "=== Attack Comparison (All Types) ===" << std::endl;
	clap.attack("target");  // ClapTrap: 0 damage
	scav.attack("target");  // ScavTrap: 20 damage
	frag.attack("target");  // FragTrap: 30 damage
	std::cout << std::endl;

	std::cout << "=== Special Abilities ===" << std::endl;
	scav.guardGate();       // ScavTrap special
	frag.highFivesGuys();   // FragTrap special
	std::cout << std::endl;

	std::cout << "=== FragTrap Power Demo ===" << std::endl;
	frag.attack("Clappy");
	clap.takeDamage(30);    // FragTrap does 30 damage - kills ClapTrap instantly!
	std::cout << std::endl;

	std::cout << "=== FragTrap Energy Test (has 100 energy) ===" << std::endl;
	frag.scanThisPerson();
	std::cout << "Using some energy..." << std::endl;
	for (int i = 0; i < 5; i++) {
		frag.attack("dummy");
	}
	frag.scanThisPerson();
	std::cout << std::endl;

	std::cout << "=== Copy Constructor Test ===" << std::endl;
	FragTrap clone(frag);
	clone.scanThisPerson();
	std::cout << std::endl;

	std::cout << "=== Assignment Operator Test ===" << std::endl;
	FragTrap assigned("Temp");
	assigned = clone;
	assigned.scanThisPerson();
	std::cout << std::endl;

	std::cout << "=== High Five Request ===" << std::endl;
	assigned.highFivesGuys();
	std::cout << std::endl;

	std::cout << "=== Destruction Chain (watch order!) ===" << std::endl;
	// Order: assigned, clone, frag, scav, clap
	// Each: FragTrap/ScavTrap destroyed → ClapTrap destroyed
	return 0;
}