/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:16:39 by bgrulois          #+#    #+#             */
/*   Updated: 2023/10/11 15:01:47 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main()
{
	try {
		Bureaucrat A = Bureaucrat("A", 5);
		Bureaucrat B = Bureaucrat("B", 25);
		Bureaucrat C = Bureaucrat("C", 101);

		//AForm	f1 = AForm("F1", 10, 8);
		//AForm	f2 = AForm("F2", 28, 24);
		//AForm	f3 = AForm("F3", 100, 50);
		ShrubberyCreationForm sC1 = ShrubberyCreationForm("MY");
		RobotomyRequestForm rC1 = RobotomyRequestForm("innocent bystander");
		PresidentialPardonForm pP1 = PresidentialPardonForm("very corrupt politician");


		B.signForm(&sC1);
		B.signForm(&rC1);
		//A.signForm(&pP1);
		//A.signForm(&pP1);
		pP1.execute(A);
		//pP1.execute(B);
		//C.signForm(&pP1);		//throws permission exception
	}

	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}
