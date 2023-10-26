#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <cerrno>
# include <cstring>
# include <stdlib.h>
# include <limits.h>

class ScalarConverter {
	public:
		ScalarConverter(void);
		ScalarConverter(ScalarConverter const & copy);
		ScalarConverter &operator=(ScalarConverter const & other);
		~ScalarConverter(void);
		static void	convert(std::string input);
		static int detectType(std::string input);
		static void display(int mode);
	private:
		static char _c;
		static long int	_i;
		static float _f;
		static double _d;
		static char *_endbuf;
};

#endif