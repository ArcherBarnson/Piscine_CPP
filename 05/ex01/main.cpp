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

		f1.beSigned(A);
		f2.beSigned(B);
		f3.beSigned(C);
	}

	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}
