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

// #include "Bureaucrat.hpp"
// #include "AForm.hpp"
// //#include "ShrubberyCreationForm.hpp"
// //#include "RobotomyRequestForm.hpp"
// #include "PresidentialPardonForm.hpp"

// int	main()
// {
// 	try{

// 		Bureaucrat A = Bureaucrat("A", 5);
// 		Bureaucrat B = Bureaucrat("B", 25);
// 		Bureaucrat C = Bureaucrat("C", 101);

// 		//AForm	f1 = AForm("F1", 10, 8);
// 		//AForm	f2 = AForm("F2", 28, 24);
// 		//AForm	f3 = AForm("F3", 100, 50);
// 		//ShrubberyCreationForm sC1 = ShrubberyCreationForm("MY");
// 		//RobotomyRequestForm rC1 = RobotomyRequestForm("innocent bystander");
// 		PresidentialPardonForm president("A");
	
// 		//B.signForm(&sC1);
// 		//B.signForm(&rC1);
// 		//A.signForm(&pP1);
// 		//A.signForm(&pP1);
// 		A.signForm(*pP1);
// 		std::cout << pP1->getFormState() << std::endl;
// 		A.executeForm(*pP1);
// 		//pP1.execute(B);
// 		//C.signForm(&pP1);		//throws permission exception

// 	return 0;
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldinaut <ldinaut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 11:55:47 by ldinaut           #+#    #+#             */
/*   Updated: 2023/10/12 17:10:53 by ldinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
//#include "ShrubberyCreationForm.hpp"
//#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int    main(void)
{
    //try
    //{
    //    Bureaucrat Luna("Luna", 151);
    //}
    //catch (std::exception &e)
    //{
    //    std::cerr << "Error : " << e.what() << std::endl;
    //}
    //Bureaucrat Medhi("Medhi", 50);
    //Bureaucrat Lucie("Lucie", 130);
    Bureaucrat Julien = Bureaucrat("Julien", 4);

    PresidentialPardonForm president = PresidentialPardonForm("Very corrupt politician");
    Julien.signForm(president);
    std::cout << "signed in main ? " << president.getFormState() << std::endl;
    Julien.executeForm(president);

    // ShrubberyCreationForm arbre("Julien");
    // Lucie.executeForm(arbre);

    // RobotomyRequestForm bot("Lucie");
    // Medhi.executeForm(bot);
    //for (int i = 0; i <= 6; i++)
    //    Medhi.incrementGrade();
    //std::cout << Medhi << std::endl;
    //std::cout << bot << std::endl;
   // Medhi.executeForm(bot);
}
