#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) 
	: _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap " << _name << " is constructed!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) {
	std::cout << "ClapTrap " << other._name << " is copied!" << std::endl;
	*this = other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	std::cout << "ClapTrap assignment operator called" << std::endl;
	if (this != &other) {
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << _name << " is destroyed!" << std::endl;
}

void ClapTrap::attack(const std::string& target) {
	if (_hitPoints == 0) {
		std::cout << "ClapTrap " << _name 
		          << " can't attack, since it's already dead!" << std::endl;
		return;
	}
	if (_energyPoints == 0) {
		std::cout << "ClapTrap " << _name 
		          << " can't attack due to low energy!" << std::endl;
		return;
	}
	_energyPoints--;
	std::cout << "ClapTrap " << _name << " attacks " << target 
	          << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (_hitPoints == 0) {
		std::cout << "ClapTrap " << _name << " is already dead!" << std::endl;
		return;
	}
	
	if (amount >= _hitPoints) {
		_hitPoints = 0;
		std::cout << "ClapTrap " << _name << " takes " << amount 
		          << " damage and dies! Hit points: 0" << std::endl;
	} else {
		_hitPoints -= amount;
		std::cout << "ClapTrap " << _name << " takes " << amount 
		          << " damage! Hit points: " << _hitPoints << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (_hitPoints == 0) {
		std::cout << "ClapTrap " << _name 
		          << " can't be repaired, since it's already dead!" << std::endl;
		return;
	}
	if (_energyPoints == 0) {
		std::cout << "ClapTrap " << _name 
		          << " can't be repaired due to low energy!" << std::endl;
		return;
	}
	_energyPoints--;
	_hitPoints += amount;
	std::cout << "ClapTrap " << _name << " repairs itself for " << amount 
	          << " hit points! Hit points: " << _hitPoints << std::endl;
}

void ClapTrap::scanThisPerson() {
	std::cout << "ClapTrap [" << _name << "] is being scanned " << std::endl;
	std::cout << "  Hit Points: " << _hitPoints << std::endl;
	std::cout << "  Energy Points: " << _energyPoints << std::endl;
	std::cout << "  Attack Damage: " << _attackDamage << std::endl;
}
