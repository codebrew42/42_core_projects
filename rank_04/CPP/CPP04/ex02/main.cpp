#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
	std::cout << "=== Create & Delete as Animal ===" << std::endl;
	// const Animal();
	// const Animal* thisAlsoFails = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;
	delete i;

	std::cout << "\n\n=== Array of Animals Test ===" << std::endl;
	const int arraySize = 6;
	Animal* animals[arraySize];

	std::cout << "\n--- Creating Dogs ---" << std::endl;
	for (int idx = 0; idx < arraySize / 2; idx++) {
		animals[idx] = new Dog();
	}

	std::cout << "\n--- Creating Cats ---" << std::endl;
	for (int idx = arraySize / 2; idx < arraySize; idx++) {
		animals[idx] = new Cat();
	}

	std::cout << "\n--- Making Sounds ---" << std::endl;
	for (int idx = 0; idx < arraySize; idx++) {
		std::cout << animals[idx]->getType() << ": ";
		animals[idx]->makeSound();
	}

	std::cout << "\n--- Deleting All Animals ---" << std::endl;
	for (int idx = 0; idx < arraySize; idx++) {
		delete animals[idx];
	}

	std::cout << "\n\n=== Deep Copy Test ===" << std::endl;
	Dog basic;
	basic.getBrain()->setIdea(0, "I am a good dog!");
	basic.getBrain()->setIdea(1, "I love bones!");

	std::cout << "\n--- Creating Deep Copy ---" << std::endl;
	{
		Dog tmp = basic;
		std::cout << "Original Dog's idea[0]: " << basic.getBrain()->getIdea(0) << std::endl;
		std::cout << "Copied Dog's idea[0]: " << tmp.getBrain()->getIdea(0) << std::endl;
		std::cout << "Brain addresses different? "
				  << (basic.getBrain() != tmp.getBrain() ? "YES (deep copy)" : "NO (shallow copy)")
				  << std::endl;

		std::cout << "\n--- Modifying Copy ---" << std::endl;
		tmp.getBrain()->setIdea(0, "I am a copied dog!");
		std::cout << "Original Dog's idea[0]: " << basic.getBrain()->getIdea(0) << std::endl;
		std::cout << "Copied Dog's idea[0]: " << tmp.getBrain()->getIdea(0) << std::endl;
	}

	std::cout << "\n--- tmp was destroyed, original still valid ---" << std::endl;
	std::cout << "Original Dog's idea[0]: " << basic.getBrain()->getIdea(0) << std::endl;
	std::cout << "Original Dog's idea[1]: " << basic.getBrain()->getIdea(1) << std::endl;

	std::cout << "\n\n=== Assignment Operator Deep Copy Test ===" << std::endl;
	Cat cat1;
	Cat cat2;
	cat1.getBrain()->setIdea(0, "I am cat1");
	cat2.getBrain()->setIdea(0, "I am cat2");

	std::cout << "  cat1 idea[0]: " << cat1.getBrain()->getIdea(0) << std::endl;
	std::cout << "  cat2 idea[0]: " << cat2.getBrain()->getIdea(0) << std::endl;

	cat2 = cat1;

	std::cout << "--After assignment(cat1 -> cat2):--" << std::endl;
	std::cout << "  cat1 idea[0]: " << cat1.getBrain()->getIdea(0) << std::endl;
	std::cout << "  cat2 idea[0]: " << cat2.getBrain()->getIdea(0) << std::endl;
	std::cout << "  Brain addresses different? "
			  << (cat1.getBrain() != cat2.getBrain() ? "YES (deep copy)" : "NO (shallow copy)")
			  << std::endl;

	std::cout << "\n=== End of Tests ===" << std::endl;
	return 0;
}
