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

int	main()
{	
	try {
		Bureaucrat bware = Bureaucrat("bware", 13);
		int i;
		for (i = 0; i < 13; i++)
			bware.incrementGrade();
		Bureaucrat blow = Bureaucrat("blow", 147);
		for (i = 0; i < 4; i++)
			blow.decrementGrade();
		std::cout << bware << std::endl;
		std::cout << blow << std::endl;
		/* The two extremity cases are exlusive to each other because exception is thrown
		 * and thus the program is stopped
		 *
		 * 	Bureaucrat b1 = Bureaucrat("b1", 0);	//too high exception
		 *	Bureaucrat b2 = Bureaucrat("b2", 1111);	//too low exception
		 *
		 */
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	};
	return 0;
}
