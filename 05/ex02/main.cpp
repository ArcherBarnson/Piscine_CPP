/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:16:39 by bgrulois          #+#    #+#             */
/*   Updated: 2023/10/09 15:30:43 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main()
{
	try {
		Bureaucrat A = Bureaucrat("A", 5);
		Bureaucrat B = Bureaucrat("B", 25);
		Bureaucrat C = Bureaucrat("C", 101);

		//AForm	f1 = AForm("F1", 10, 8);
		//AForm	f2 = AForm("F2", 28, 24);
		//AForm	f3 = AForm("F3", 100, 50);
		ShrubberyCreationForm sC1 = ShrubberyCreationForm("sC1"); 

		B.signForm(&sC1);
		//B.signForm(&f2);
		//C.signForm(&f3);
	}

	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}
