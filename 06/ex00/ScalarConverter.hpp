/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 10:59:49 by bgrulois          #+#    #+#             */
/*   Updated: 2023/11/15 10:59:52 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <iomanip>
# include <cerrno>
# include <cstring>
# include <stdlib.h>
# include <limits.h>
# include <float.h>

class ScalarConverter {
	public:
		ScalarConverter(void);
		ScalarConverter(ScalarConverter const & copy);
		ScalarConverter &operator=(ScalarConverter const & other);
		virtual ~ScalarConverter(void) = 0;
		static void	convert(std::string input);
};

int detectType(std::string input);
void displayEval(void);

#endif
