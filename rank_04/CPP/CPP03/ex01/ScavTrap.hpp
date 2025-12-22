#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap{
public:
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap& other);
	ScavTrap& operator=(const ScavTrap& other);
	~ScavTrap();

/* Same name fun `attack` of ClapTrap 
 caution!
	NOT true polymorphic overriding without `virtual void` in `ClapTrap`(CPP 04).
 if you want to call parent function, use explicit scope
	scav.ClapTrap::attack("..") //works
*/
	void attack(const std::string& target);
	void guardGate();
	void scanThisPerson();
};

#endif