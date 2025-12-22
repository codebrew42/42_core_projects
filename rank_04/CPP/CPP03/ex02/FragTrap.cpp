#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name)
	: ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;

	std::cout << "FragTrap " << _name << " is constructed!" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
	std::cout << "FragTrap " << other._name << " is copied!" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
	std::cout << "FragTrap assignment operator called" << std::endl;
	if (this != &other) {
		ClapTrap::operator=(other);
	}
	return *this;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << _name << " is destroyed!" << std::endl;
}

void FragTrap::attack(const std::string& target) {
	if (_hitPoints == 0) {
		std::cout << "FragTrap " << _name 
		          << " can't attack, since it's already dead!" << std::endl;
		return;
	}
	if (_energyPoints == 0) {
		std::cout << "FragTrap " << _name 
		          << " can't attack due to low energy!" << std::endl;
		return;
	}
	_energyPoints--;
	std::cout << "FragTrap " << _name << " attacks " << target 
	          << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap " << _name << " requests a positive high five! ✋" << std::endl;
}

void FragTrap::scanThisPerson() {
	std::cout << "FragTrap [" << _name << "] is being scanned " << std::endl;
	std::cout << "  Hit Points: " << _hitPoints << std::endl;
	std::cout << "  Energy Points: " << _energyPoints << std::endl;
	std::cout << "  Attack Damage: " << _attackDamage << std::endl;
}