/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 17:05:25 by bgrulois          #+#    #+#             */
/*   Updated: 2023/10/03 17:09:45 by bgrulois         ###   ########.fr       */
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
	//delete [] pets; nul
	return 0;
}
