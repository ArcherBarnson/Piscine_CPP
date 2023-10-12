/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 17:05:25 by bgrulois          #+#    #+#             */
/*   Updated: 2023/10/12 14:58:05 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Brain.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal	*pets[4];
	int i = -1;

	while (++i < 2)
		pets[i] = new Cat();
	i--;
	while (++i < 4)
		pets[i] = new Dog();
	i = -1;
	while (++i < 4)
	{
		std::cout << "uuuuuu" << std::endl;
		pets[i]->makeSound();
	}
	i = -1;
	while (++i < 4)
	{
		delete pets[i];
		std::cout << "HELLLLLOOOOOOOO" << std::endl;
	}

	//deep copy test
	std::cout << "------------------DEEP COPY TEST------------" << std::endl;
	Cat *cat = new Cat();
	cat->setBrainIdea(0, "I AM ANNOYED BY THE CPP04 SUBJECT BECAUSE IT IS QUITE UNCLEAR :((");
	Cat *cat2 = new Cat(*cat);

	cat->makeSound();
	delete cat;
	std::cout << "the brain was deep copied as well : proof -> cat2.getBrainIdea(0) == " << cat2->getBrainIdea(0) << std::endl; 	//special test, getter needs to be enabled in .hpp and .cpp
	cat2->makeSound();
	delete cat2;
	return 0;
}
