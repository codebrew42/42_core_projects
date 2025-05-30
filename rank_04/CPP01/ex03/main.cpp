#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	Weapon club("crazily spiked club");
	Weapon b = club;
	Weapon knife("super sharp knife");
	Weapon pencil("round pencil");

	HumanA women("Hannah", club);
	HumanB men("Adolf");

	women.attack();
	men.attack(&b);
	men.attack(&knife);
	knife.setType("very dull knife");
	men.attack(&knife);
	men.attack(NULL);

	cout << endl;
	men.setWeapon(&pencil);
	men.attack();
	men.attack(NULL);

	cout << endl;
	pencil.setType("very shart pencil this time");
	men.attack();
}
