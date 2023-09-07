#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "building base class" << std::endl;
	const Animal* meta = new Animal();
	std::cout << "building Dog class" << std::endl;
	const Animal* j = new Dog();
	std::cout << "building Cat class" << std::endl;
	const Animal* i = new Cat();
	std::cout << "Type should be dog" << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << "Type should be cat" << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << "Calling makeSound() --- order is : 1-cat 2-dog 3-base" << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	std::cout << "freeing allocated space" << std::endl;
	delete meta;
	delete i;
	delete j;
	std::cout << "Testing wrong animals now" << std::endl;
	const WrongAnimal * abomination = new WrongAnimal();
	const WrongCat * abomicat = new WrongCat();
	std::cout << "printing WrongAnimal type" << std::endl;
	std::cout << abomination->getType() << " " << std::endl;
	std::cout << "printing WrongCat type" << std::endl;
	std::cout << abomicat->getType() << " " << std::endl;
	std::cout << "Calling makeSound() --- order is : 1-WrongAnimal 2-WrongCat" << std::endl;
	abomination->makeSound();
	abomicat->makeSound();
	std::cout << "Cleaning up" << std::endl;
	delete abomination;
	delete abomicat;
	return 0;
}
