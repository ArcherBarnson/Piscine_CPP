/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:16:39 by bgrulois          #+#    #+#             */
/*   Updated: 2023/10/23 13:39:15 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{
	try {
		Bureaucrat A = Bureaucrat("A", 5);
		Bureaucrat B = Bureaucrat("B", 25);
		Bureaucrat C = Bureaucrat("C", 101);

		Form	f1 = Form("F1", 10, 8);
		Form	f2 = Form("F2", 28, 24);
		Form	f3 = Form("F3", 100, 50);

		std::cout << f1 << f2 << f3 << std::endl;

		B.signForm(f1);
		B.signForm(f2);
		C.signForm(f3);
	}

	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}
