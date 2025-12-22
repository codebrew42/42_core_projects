#include "ScavTrap.hpp"


ScavTrap::ScavTrap(std::string name)
	: ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;

	std::cout << "ScavTrap " << _name << " is constructed!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
	std::cout << "ScavTrap " << other._name << " is copied!" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
	std::cout << "ScavTrap assignment operator called" << std::endl;
	if (this != &other) {
		ClapTrap::operator=(other);  // Call parent assignment operator
	}
	return *this;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << _name << " is destroyed!" << std::endl;
}

void ScavTrap::guardGate() {
	std::cout << "ScavTrap " << _name << " is now in Gate keeper mode!" << std::endl;
}


void ScavTrap::attack(const std::string& target) {
	if (_hitPoints == 0) {
		std::cout << "ScavTrap " << _name 
				  << " can't attack, since it's already dead!" << std::endl;
		return;
	}
	if (_energyPoints == 0) {
		std::cout << "ScavTrap " << _name 
				  << " can't attack due to low energy!" << std::endl;
		return;
	}
	_energyPoints--;
	std::cout << "ScavTrap " << _name << " attacks " << target 
			  << ", causing " << _attackDamage << " points of damage!" << std::endl;
}


void ScavTrap::scanThisPerson() {
	std::cout << "ScavTrap [" << _name << "] is being scanned " << std::endl;
	std::cout << "  Hit Points: " << _hitPoints << std::endl;
	std::cout << "  Energy Points: " << _energyPoints << std::endl;
	std::cout << "  Attack Damage: " << _attackDamage << std::endl;
}
