// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   main.cpp                                           :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2023/10/09 12:16:39 by bgrulois          #+#    #+#             */
// /*   Updated: 2023/10/12 17:16:04 by bgrulois         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	Bureaucrat b1 = Bureaucrat("b1", 1);
	Bureaucrat b2 = Bureaucrat("b2", 42);
	Bureaucrat b3 = Bureaucrat("b3", 15);
	//Bureaucrat bBad = Bureaucrat("bBad", 151);
	//Bureaucrat bBad2 = Bureaucrat("bBad2", -1);

	PresidentialPardonForm ppf1("very corrupt politician");
	ShrubberyCreationForm shrub1("petrol company that specializes in greenwashing");
	RobotomyRequestForm robo1("innocent bystander");

	std::cout << ppf1 << std::endl << shrub1 << std::endl << robo1 << std::endl;

	b2.signForm(shrub1);
	b3.signForm(robo1);
	b2.signForm(ppf1);
	b1.signForm(ppf1);
	b2.executeForm(ppf1);
	b1.executeForm(ppf1);
	b2.executeForm(shrub1);
	b3.executeForm(robo1);
	return 0;
}

