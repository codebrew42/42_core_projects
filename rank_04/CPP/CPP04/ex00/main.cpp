#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
	std::cout << "=== Subject Tests ===" << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << "\n=== Type Tests ===" << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;

	std::cout << "\n=== Sound Tests (Should use derived class sounds) ===" << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();

	std::cout << "\n=== Cleanup ===" << std::endl;
	delete meta;
	delete j;
	delete i;

	std::cout << "\n\n=== Wrong Animal Tests ===" << std::endl;
	const WrongAnimal* wrongMeta = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();

	std::cout << "\n=== Wrong Type Tests ===" << std::endl;
	std::cout << wrongCat->getType() << " " << std::endl;

	std::cout << "\n=== Wrong Sound Tests (Use base class sound: no virtual) ===" << std::endl;
	wrongCat->makeSound();
	wrongMeta->makeSound();

	std::cout << "\n=== Wrong Cleanup ===" << std::endl;
	delete wrongMeta;
	delete wrongCat;

	std::cout << "\n\n=== Direct WrongCat Test ===" << std::endl;
	WrongCat directWrongCat;
	std::cout << "Direct WrongCat sound: ";
	directWrongCat.makeSound();

	std::cout << "\n=== Copy Constructor Tests ===" << std::endl;
	Dog originalDog;
	Dog copiedDog(originalDog);

	std::cout << "\n=== Assignment Operator Tests ===" << std::endl;
	Cat originalCat;
	Cat assignedCat;
	assignedCat = originalCat;

	std::cout << "\n=== End of Tests ===" << std::endl;
	return 0;
}
