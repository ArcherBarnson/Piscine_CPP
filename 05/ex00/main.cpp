/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:16:39 by bgrulois          #+#    #+#             */
/*   Updated: 2023/10/24 11:32:07 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main()
{	
	int n = 1;
	try {
		Bureaucrat bware = Bureaucrat("bware", 13);
		int i;
		//grade too high exception if incremented over 1
		for (i = 0; i < n; i++)
			bware.incrementGrade();
		//grade too low exception if decremented uneder 150
		Bureaucrat blow = Bureaucrat("blow", 147);
		for (i = 0; i < n; i++)
			blow.decrementGrade();
		std::cout << bware << std::endl;
		std::cout << blow << std::endl;
		/* The two extremity cases are exclusive to each other because exception is thrown
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
