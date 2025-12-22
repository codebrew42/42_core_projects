#include "ClapTrap.hpp"

int main() {
	std::cout << "=== Creating ClapTraps ===" << std::endl;
	ClapTrap jieun("Jieun");
	ClapTrap enemy("Enemy");
	std::cout << std::endl;

	std::cout << "=== Initial Stats ===" << std::endl;
	jieun.scanThisPerson();
	enemy.scanThisPerson();
	std::cout << std::endl;

	std::cout << "=== Battle Sequence ===" << std::endl;
	jieun.attack("Enemy");
	enemy.takeDamage(0);  // Since attackDamage is 0
	std::cout << std::endl;

	enemy.attack("Jieun");
	jieun.takeDamage(0);
	std::cout << std::endl;

	std::cout << "=== Repair Test ===" << std::endl;
	jieun.beRepaired(5);
	jieun.scanThisPerson();
	std::cout << std::endl;

	std::cout << "=== Energy Depletion Test ===" << std::endl;
	for (int i = 0; i < 10; i++) {
		jieun.attack("Enemy");
	}
	jieun.attack("Enemy");  // should fail (no energy)
	std::cout << std::endl;

	std::cout << "=== Death Test ===" << std::endl;
	enemy.takeDamage(15);  // Kill enemy
	enemy.attack("Jieun");  // Should fail (dead)
	enemy.beRepaired(5);    // Should fail (dead)
	std::cout << std::endl;

	std::cout << "=== Copy Constructor Test ===" << std::endl;
	ClapTrap clone(jieun);
	clone.scanThisPerson();
	std::cout << std::endl;

	std::cout << "=== Assignment Operator Test ===" << std::endl;
	ClapTrap assigned("Assigned");
	assigned = enemy;
	assigned.scanThisPerson();
	std::cout << std::endl;

	std::cout << "=== Destructors Called ===" << std::endl;
	return 0;
}